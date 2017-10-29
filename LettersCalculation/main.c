#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_INPUTED_STRING 1000000
#define SIZE_OF_ALPHABET 25

int main() {
    
    int counterTemporary[26] = {0};
    int countOfLetters[26] = {0};
    int indexArray[26] = {0};
    int position = 0;
    int strLen;
    int i, j;
    
    char* inputedString;
    inputedString = (char*) malloc(SIZE_OF_INPUTED_STRING * sizeof(char));
    
    printf("Pls enter a string. We will calculate an amount of each letter:\n");
    gets(inputedString);
    fpurge(stdin);
    
    //handle case whan user do not type anything
    if (inputedString[0] == 0){
        printf("Error! Empty string\n");
    }
    
    strLen = strlen(inputedString);
    for (i = 0; i < strLen; i++){
        //Considering characters from 'A' to 'Z' only and ignoring others
        if ((inputedString[i] >= 'A' && inputedString[i] <= 'Z')) {
            countOfLetters[inputedString[i]-'A']++;
            counterTemporary[inputedString[i]-'A']++;
        }
        //Considering characters from 'a' to 'z' only and ignoring others
        if  (inputedString[i] >= 'a' && inputedString[i] <= 'z'){
            countOfLetters[inputedString[i]-'a']++;
            counterTemporary[inputedString[i]-'a']++;
        }
    }
    
    //sorting array with letter coounter from max to min, bubble sort
    for(i=0; i < SIZE_OF_ALPHABET; i++){
        for(j=i+1; j<SIZE_OF_ALPHABET; j++){
            if(countOfLetters[i] < countOfLetters[j]){
                int temp = countOfLetters[i];
                countOfLetters[i] = countOfLetters[j];
                countOfLetters[j] = temp;
            }
        }
    }
    
    //saving index numbers of sorted elements
    for (int c = 0; c < SIZE_OF_ALPHABET; c++){
        if (countOfLetters[c] != 0) {
            for (i = 0; i < SIZE_OF_ALPHABET; i++) {
                if (counterTemporary[i] == countOfLetters[c]) {
                    indexArray[position] = i;
                    counterTemporary[i] = 0;
                    position++;
                }
            }
        }
    }
    
    //display result
    j = 0;
    for (i = 0; i < SIZE_OF_ALPHABET; i++){
        if (countOfLetters[i] != 0) {
            printf("%c occurs %d times in the entered string.\n", indexArray[j]+'A',countOfLetters[i]);
            j++;
        }
    }
    
    free(inputedString);
    return 0;
}


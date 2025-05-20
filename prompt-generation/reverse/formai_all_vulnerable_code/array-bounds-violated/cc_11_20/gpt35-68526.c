//FormAI DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char inputString[1000], word[1000];
    int i, j, k, count = 0;
    printf("Enter a string: ");
    fgets(inputString, 1000, stdin);
    inputString[strlen(inputString) - 1] = '\0';

    printf("Original string: %s\n", inputString);

    // Converting the string to lowercase
    for(i = 0; inputString[i]; i++){
        inputString[i] = tolower(inputString[i]);
    }

    // Removing punctuation marks from the string
    for(i = 0; inputString[i]; i++){
        if(ispunct(inputString[i])){
            for(j = i; inputString[j]; j++){
                inputString[j] = inputString[j+1];
            }
            i--;
        }
    }

    // Counting the number of words in the string
    for(i = 0; inputString[i]; i++){
        if(inputString[i] == ' ' && inputString[i-1] != ' '){
            count++;
        }
    }

    printf("Number of words in the string: %d\n", count+1);

    // Reversing each word in the string
    for(i = 0, j = 0; inputString[i]; i++){
        if(inputString[i] == ' ' && inputString[i-1] != ' ' || inputString[i+1] == '\0' ){
            if(inputString[i+1] == '\0'){
                word[j++] = inputString[i];
            }
            word[j] = '\0';
            for(k = strlen(word)-1; k >= 0; k--){
                printf("%c", word[k]);
            }
            printf(" ");
            j = 0;
        }else{
            word[j++] = inputString[i];
        }
    }

    return 0;
}
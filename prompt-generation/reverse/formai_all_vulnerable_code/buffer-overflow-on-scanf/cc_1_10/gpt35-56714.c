//FormAI DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTWORDS 10000

int isAlpha(char letter){
    if(letter >= 'a' && letter <= 'z' || letter >= 'A' && letter <= 'Z'){
        return 1;
    }
    return 0;
}

int main(){

    char dictionary[MAX_DICTWORDS][MAX_WORD_LENGTH];
    char input[100];
    char result[100];
    char word[MAX_WORD_LENGTH];
    int numWords = 0;

    printf("Enter words for the dictionary (ctrl+D to end):\n");
    while(scanf("%s", word) != EOF){
        strcpy(dictionary[numWords], word);
        numWords++;
    }

    printf("\nEnter a sentence to check (max 100 characters):\n");
    fgets(input, 100, stdin);
    input[strlen(input) - 1] = '\0';
    int len = strlen(input);

    int start = 0;
    int end = 0;
    int resultIndex = 0;
    int i;

    while(end <= len){
        if(isAlpha(input[end])){
            end++;
        }
        else{
            int found = 0;
            strncpy(word, input + start, end - start);
            word[end - start] = '\0';

            for(i = 0; i < numWords; i++){
                if(strcmp(word, dictionary[i]) == 0){
                    found = 1;
                    break;
                }
            }

            if(found){
                for(i = 0; i < strlen(word); i++){
                    result[resultIndex] = word[i];
                    resultIndex++;
                }
            }
            else{
                for(i = 0; i < strlen(word); i++){
                    result[resultIndex] = '*';
                    resultIndex++;
                }
            }
            result[resultIndex] = input[end];
            resultIndex++;
            start = ++end;
        }
    }

    printf("\n%s\n", result);

    return 0;
}
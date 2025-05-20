//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

int main(){

    char input_text[MAX_WORDS][MAX_WORD_LENGTH], word[MAX_WORD_LENGTH];
    int frequency[MAX_WORDS];
    int i, j, numWords = 0, flag = 0;

    // ask the user for input text
    printf("Enter text (press enter twice when done):\n");

    // read in the input text
    while(fgets(input_text[numWords], MAX_WORD_LENGTH, stdin) != NULL) {
        if(input_text[numWords][0] == '\n') {
            break;
        }
        // remove any new line characters
        if(input_text[numWords][strlen(input_text[numWords])-1] == '\n') {
            input_text[numWords][strlen(input_text[numWords])-1] = '\0';
        }
        numWords++;
    }

    // count the frequency of each word
    for(i = 0; i < numWords; i++) {
        // check if word already exists in the array
        for(j = 0; j < i; j++) {
            if(strcmp(input_text[i], input_text[j]) == 0) {
                flag = 1;
                break;
            }
        }
        // if word does not exist in array, find its frequency
        if(flag == 0) {
            int count = 1;
            strcpy(word, input_text[i]);
            for(j = i+1; j < numWords; j++) {
                if(strcmp(word, input_text[j]) == 0) {
                    count++;
                }
            }
            // store the word and its frequency in the arrays
            strcpy(input_text[i], word);
            frequency[i] = count;
        }
        flag = 0;
    }

    // display the frequency of each word
    printf("Word Frequency:\n");
    printf("============================\n");
    for(i = 0; i < numWords; i++) {
        printf("%-20s %d\n", input_text[i], frequency[i]);
    }

    return 0;
}
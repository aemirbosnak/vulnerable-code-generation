//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

int wordCount = 0;
char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];

void addWord(char* word) {
    if (wordCount >= MAX_NUM_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }
    strcpy(words[wordCount], word);
    wordCount++;
}

int main() {
    char input[MAX_WORD_LENGTH];
    char* word = NULL;
    int inputLength = 0;

    printf("Enter text to count words:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);
    inputLength = strlen(input);

    char* inputCopy = malloc(inputLength + 1);
    if (inputCopy == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    strcpy(inputCopy, input);

    char* token = strtok(inputCopy, ",.?!;:");
    while (token!= NULL) {
        if (strlen(token) > MAX_WORD_LENGTH) {
            printf("Error: Word length exceeded maximum limit.\n");
            exit(1);
        }
        addWord(token);
        token = strtok(NULL, ",.?!;:");
    }

    printf("Total number of words: %d\n", wordCount);
    for (int i = 0; i < wordCount; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
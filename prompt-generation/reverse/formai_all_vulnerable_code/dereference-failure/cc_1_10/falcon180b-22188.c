//Falcon-180B DATASET v1.0 Category: Educational ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

// Function prototypes
int isValidWord(char *word);
int compareWords(const void *a, const void *b);
void printWords(char **words, int numWords);

int main() {
    char input[MAX_WORD_LENGTH];
    char *words[MAX_NUM_WORDS];
    int numWords = 0;

    // Get user input
    printf("Enter a list of words separated by spaces:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    // Convert input to lowercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    // Tokenize input into words
    char *token = strtok(input, " ");
    while (token!= NULL) {
        // Check if word is valid
        if (isValidWord(token)) {
            // Add word to array
            words[numWords] = strdup(token);
            numWords++;
        }
        token = strtok(NULL, " ");
    }

    // Sort words alphabetically
    qsort(words, numWords, sizeof(char*), compareWords);

    // Print sorted words
    printf("Sorted words:\n");
    printWords(words, numWords);

    return 0;
}

// Function to check if a word is valid (contains only letters)
int isValidWord(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to compare two words alphabetically
int compareWords(const void *a, const void *b) {
    return strcmp(*(char**)a, *(char**)b);
}

// Function to print an array of words
void printWords(char **words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}
//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_SIZE 10000 // Assuming a maximum of 10,000 words in the dictionary

// Function prototypes
void loadDictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *wordCount);
int isWordInDictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int wordCount);
void checkSpelling(const char *inputText, char dictionary[][MAX_WORD_LENGTH], int wordCount);
void toLowerCase(char *word);
void splitWords(const char *inputText, char words[][MAX_WORD_LENGTH], int *wordCount);

int main() {
    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int wordCount = 0;

    loadDictionary("dictionary.txt", dictionary, &wordCount);

    char inputText[1024];
    printf("Enter text for spell checking (max 1024 characters): ");
    fgets(inputText, sizeof(inputText), stdin);

    checkSpelling(inputText, dictionary, wordCount);

    return 0;
}

void loadDictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *wordCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open dictionary file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dictionary[*wordCount]) != EOF) {
        toLowerCase(dictionary[*wordCount]);
        (*wordCount)++;
    }

    fclose(file);
}

void toLowerCase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

int isWordInDictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

void splitWords(const char *inputText, char words[][MAX_WORD_LENGTH], int *wordCount) {
    char *token = strtok((char *)inputText, " .,;!?\n");
    while (token != NULL) {
        toLowerCase(token);
        strcpy(words[*wordCount], token);
        (*wordCount)++;
        token = strtok(NULL, " .,;!?\n");
    }
}

void checkSpelling(const char *inputText, char dictionary[][MAX_WORD_LENGTH], int wordCount) {
    char words[100][MAX_WORD_LENGTH]; // Assuming maximum 100 words in the input text
    int validWordsCount = 0;

    splitWords(inputText, words, &validWordsCount);

    printf("\nSpelling Check Results:\n");
    for (int i = 0; i < validWordsCount; i++) {
        if (!isWordInDictionary(words[i], dictionary, wordCount)) {
            printf("Misspelled: %s\n", words[i]);
        }
    }

    if (validWordsCount == 0) {
        printf("No valid words to check.\n");
    }
}
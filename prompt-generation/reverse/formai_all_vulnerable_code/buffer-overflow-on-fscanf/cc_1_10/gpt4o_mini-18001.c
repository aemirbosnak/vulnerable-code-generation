//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define DICTIONARY_SIZE 1000

// Function prototypes
void loadDictionary(const char *filename, char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int *count);
int isWordInDictionary(const char *word, char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int count);
void toLowerCase(char *word);
void getInputText(char *input, int length);
void checkSpelling(char *input, char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int dictCount);

int main() {
    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dictCount = 0;
    char inputText[10000];

    // Load the dictionary file into the array
    loadDictionary("dictionary.txt", dictionary, &dictCount);

    printf("Enter text to check spelling (type 'exit' to quit):\n");
    while (1) {
        getInputText(inputText, sizeof(inputText));
        if (strcmp(inputText, "exit") == 0) {
            break;
        }
        checkSpelling(inputText, dictionary, dictCount);
    }

    return 0;
}

void loadDictionary(const char *filename, char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "%s", dictionary[*count]) != EOF && *count < DICTIONARY_SIZE) {
        toLowerCase(dictionary[*count]);
        (*count)++;
    }
    
    fclose(file);
}

int isWordInDictionary(const char *word, char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

void toLowerCase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower((unsigned char)word[i]);
    }
}

void getInputText(char *input, int length) {
    printf("Text: ");
    fgets(input, length, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline
}

void checkSpelling(char *input, char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int dictCount) {
    char *token = strtok(input, " ");
    printf("Misspelled words:\n");

    while (token) {
        char word[MAX_WORD_LENGTH];
        strncpy(word, token, sizeof(word));
        word[sizeof(word) - 1] = '\0'; // Ensure null-termination
        toLowerCase(word);

        if (!isWordInDictionary(word, dictionary, dictCount)) {
            printf(" - %s\n", token);
        }

        token = strtok(NULL, " ");
    }
}
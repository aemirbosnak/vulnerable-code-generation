//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 1000
#define MAX_INPUT_LENGTH 500

// Function prototypes
void loadDictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *wordCount);
int checkSpelling(char *word, char dictionary[][MAX_WORD_LENGTH], int wordCount);
void getInput(char *input, size_t length);
void processInput(const char *input, char dictionary[][MAX_WORD_LENGTH], int wordCount);

int main() {
    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int wordCount = 0;
    char input[MAX_INPUT_LENGTH];

    // Load the dictionary file with words
    loadDictionary("dictionary.txt", dictionary, &wordCount);

    // Get input from user
    printf("Enter text to check spelling (type 'exit' to quit):\n");

    while (1) {
        getInput(input, sizeof(input));

        if (strcmp(input, "exit") == 0) {
            break;
        }

        processInput(input, dictionary, wordCount);
        printf("\nEnter text to check spelling (type 'exit' to quit):\n");
    }

    return 0;
}

// Load dictionary from the file
void loadDictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *wordCount) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dictionary[*wordCount]) != EOF) {
        (*wordCount)++;
        if (*wordCount >= DICTIONARY_SIZE) {
            printf("Warning: Dictionary size exceeded. Some words may not be loaded.\n");
            break;
        }
    }

    fclose(file);
}

// Check if the word exists in the dictionary
int checkSpelling(char *word, char dictionary[][MAX_WORD_LENGTH], int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        if (strcasecmp(word, dictionary[i]) == 0) {
            return 1; // Word is correctly spelled
        }
    }
    return 0; // Word not found
}

// Get input from the user
void getInput(char *input, size_t length) {
    if (fgets(input, length, stdin) != NULL) {
        // Remove trailing newline character from input
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
    }
}

// Process the input and check spelling for each word
void processInput(const char *input, char dictionary[][MAX_WORD_LENGTH], int wordCount) {
    char *word = strtok((char *)input, " ");
    int foundWords = 0;

    printf("Spell Check Results:\n");
    while (word != NULL) {
        if (checkSpelling(word, dictionary, wordCount)) {
            foundWords++;
        } else {
            printf("Misspelled word: '%s'\n", word);
        }
        word = strtok(NULL, " ");
    }

    if (foundWords == 0) {
        printf("No correctly spelled words found.\n");
    } else {
        printf("Total correctly spelled words: %d\n", foundWords);
    }
}
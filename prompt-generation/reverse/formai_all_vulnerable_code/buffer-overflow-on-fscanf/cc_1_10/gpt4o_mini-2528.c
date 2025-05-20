//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define constants
#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000
#define DICTIONARY_SIZE 5000

// A structure to represent a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} DictionaryWord;

// Function prototypes
void loadDictionary(DictionaryWord *dictionary, const char *filename, int *wordCount);
bool isWordInDictionary(const char *word, DictionaryWord *dictionary, int wordCount);
void checkSpelling(const char *inputString, DictionaryWord *dictionary, int wordCount);
char *toLowerCase(char *str);

// Main function
int main(int argc, char *argv[]) {
    DictionaryWord dictionary[DICTIONARY_SIZE];
    int wordCount = 0;

    if (argc != 2) {
        printf("Usage: %s <dictionary_file>\n", argv[0]);
        return 1;
    }

    loadDictionary(dictionary, argv[1], &wordCount);

    char inputBuffer[1000];
    printf("Enter text to check (type 'exit' to quit):\n");
    while (true) {
        printf("> ");
        fgets(inputBuffer, sizeof(inputBuffer), stdin);

        // Check for exit command
        if (strcmp(inputBuffer, "exit\n") == 0) {
            break;
        }

        checkSpelling(inputBuffer, dictionary, wordCount);
    }

    return 0;
}

// Load the dictionary from file into an array of DictionaryWord
void loadDictionary(DictionaryWord *dictionary, const char *filename, int *wordCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open dictionary file %s\n", filename);
        exit(1);
    }

    *wordCount = 0;
    while (*wordCount < DICTIONARY_SIZE && fscanf(file, "%s", dictionary[*wordCount].word) == 1) {
        dictionary[*wordCount].frequency = 1; // Initialize frequency
        (*wordCount)++;
    }
    fclose(file);
    printf("Loaded %d words from dictionary.\n", *wordCount);
}

// Check if a word is in the dictionary
bool isWordInDictionary(const char *word, DictionaryWord *dictionary, int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(toLowerCase((char *)word), dictionary[i].word) == 0) {
            return true;
        }
    }
    return false;
}

// Check the spelling of the words in the input string
void checkSpelling(const char *inputString, DictionaryWord *dictionary, int wordCount) {
    char *token;
    char inputCopy[1000];
    strcpy(inputCopy, inputString);

    token = strtok(inputCopy, " \n");
    printf("Spelling Check Results:\n");

    while (token != NULL) {
        if (!isWordInDictionary(token, dictionary, wordCount)) {
            printf("Misspelled: %s\n", token);
        }
        token = strtok(NULL, " \n");
    }
}

// Convert a string to lower case
char *toLowerCase(char *str) {
    for (char *p = str; *p; p++) {
        *p = tolower(*p);
    }
    return str;
}
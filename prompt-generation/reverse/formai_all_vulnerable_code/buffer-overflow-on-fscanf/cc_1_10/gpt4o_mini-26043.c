//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICT_WORDS 1000
#define MAX_TEXT_LENGTH 1000

// Function to load dictionary words from a file
int loadDictionary(const char *fileName, char dict[][MAX_WORD_LENGTH]) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        perror("Unable to open dictionary file");
        return -1;
    }
    
    int count = 0;
    while (fscanf(file, "%s", dict[count]) != EOF && count < MAX_DICT_WORDS) {
        count++;
    }

    fclose(file);
    return count;
}

// Function to check if a word is in the dictionary
int isWordInDictionary(const char *word, char dict[][MAX_WORD_LENGTH], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dict[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to suggest corrections for a misspelled word
void suggestCorrections(const char *word, char dict[][MAX_WORD_LENGTH], int dictSize) {
    printf("Suggestions for '%s':\n", word);
    for (int i = 0; i < dictSize; i++) {
        if (strncmp(word, dict[i], strlen(word)-1) == 0 || strncmp(word, dict[i]+1, strlen(word)-1) == 0) {
            printf("- %s\n", dict[i]);
        }
    }
}

// Function to spell check a given text
void spellCheckText(const char *text, char dict[][MAX_WORD_LENGTH], int dictSize) {
    char *word = strtok((char *)text, " ,.!?;\n");
    while (word != NULL) {
        if (!isWordInDictionary(word, dict, dictSize)) {
            printf("Misspelled word: '%s'\n", word);
            suggestCorrections(word, dict, dictSize);
        }
        word = strtok(NULL, " ,.!?;\n");
    }
}

int main() {
    char dictionary[MAX_DICT_WORDS][MAX_WORD_LENGTH];
    char text[MAX_TEXT_LENGTH];
    int dictSize;

    // Load dictionary
    dictSize = loadDictionary("dictionary.txt", dictionary);
    if (dictSize < 0) {
        return EXIT_FAILURE;
    }

    // Get input text from user
    printf("Enter text to spell check (end input with Ctrl+D):\n");
    size_t nread = fread(text, sizeof(char), MAX_TEXT_LENGTH, stdin);
    text[nread] = '\0'; // Null terminate the string

    // Check the spelling of the text
    spellCheckText(text, dictionary, dictSize);

    return EXIT_SUCCESS;
}
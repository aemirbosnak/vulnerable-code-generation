//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000
#define DICTIONARY_FILE "dict.txt"
#define MAX_DICTIONARY_WORDS 5000

typedef struct {
    char *words[MAX_DICTIONARY_WORDS];
    int count;
} Dictionary;

typedef struct {
    char *misspelledWords[MAX_WORDS];
    int count;
} SpellCheckResults;

void loadDictionary(Dictionary *dict) {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    if (!file) {
        printf("In this desolate world, even the words have crumbled!\n");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    dict->count = 0;
    
    while (fscanf(file, "%s", word) != EOF && dict->count < MAX_DICTIONARY_WORDS) {
        dict->words[dict->count] = strdup(word);
        dict->count++;
    }
    
    fclose(file);
}

int checkWord(Dictionary *dict, const char *word) {
    for (int i = 0; i < dict->count; i++) {
        if (strcmp(dict->words[i], word) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

void spellCheck(const char *input, Dictionary *dict, SpellCheckResults *results) {
    FILE *file = fopen(input, "r");
    if (!file) {
        printf("The ruins have swallowed your scrolls. Can't find the text!\n");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    results->count = 0;

    while (fscanf(file, "%s", word) != EOF) {
        // Remove punctuation
        char cleanWord[MAX_WORD_LENGTH];
        int cleanIndex = 0;

        for (int i = 0; word[i] != '\0'; i++) {
            if (isalpha(word[i])) {
                cleanWord[cleanIndex++] = tolower(word[i]);
            }
        }
        cleanWord[cleanIndex] = '\0';

        // Check spelling
        if (!checkWord(dict, cleanWord) && results->count < MAX_WORDS) {
            results->misspelledWords[results->count] = strdup(cleanWord);
            results->count++;
        }
    }

    fclose(file);
}

void freeMemory(Dictionary *dict, SpellCheckResults *results) {
    for (int i = 0; i < dict->count; i++) {
        free(dict->words[i]);
    }

    for (int i = 0; i < results->count; i++) {
        free(results->misspelledWords[i]);
    }
}

void displayResults(SpellCheckResults *results) {
    if (results->count == 0) {
        printf("The scroll is filled with the sacred words. No mistakes found...\n");
    } else {
        printf("In the chaos of the wasteland, some words have been lost:\n");
        for (int i = 0; i < results->count; i++) {
            printf("> %s\n", results->misspelledWords[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Only the chosen one can provide the text to check: ./spell_checker <text_file>\n");
        return EXIT_FAILURE;
    }

    Dictionary dict;
    SpellCheckResults results;

    printf("Gathering lost words from the ruins...\n");
    loadDictionary(&dict);

    printf("Checking for forgotten words in the distance...\n");
    spellCheck(argv[1], &dict, &results);

    displayResults(&results);
    freeMemory(&dict, &results);

    return EXIT_SUCCESS;
}
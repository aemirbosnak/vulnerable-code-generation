//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000

// Structure to store the dictionary
typedef struct {
    char **words;
    int size;
} Dictionary;

// Functions to manage the dictionary
Dictionary* createDictionary(const char *filename);
void freeDictionary(Dictionary* dict);
int checkWord(Dictionary* dict, const char *word);

// Functions for text processing
void processFile(const char *filename, Dictionary *dict);
void normalizeWord(char *word);

// Main function
int main() {
    const char *dictionaryFile = "dictionary.txt"; // Configure dictionary file path here
    const char *inputFile = "input.txt";           // Configure input file path here

    Dictionary *dictionary = createDictionary(dictionaryFile);
    if (!dictionary) {
        fprintf(stderr, "Error: Could not load dictionary.\n");
        return 1;
    }

    printf("Spell checking the file: %s\n", inputFile);
    processFile(inputFile, dictionary);

    freeDictionary(dictionary);
    return 0;
}

// Function to create a dictionary from a file
Dictionary* createDictionary(const char *filename) {
    Dictionary *dict = (Dictionary*)malloc(sizeof(Dictionary));
    dict->words = (char**)malloc(sizeof(char*) * MAX_DICTIONARY_SIZE);
    dict->size = 0;

    FILE *file = fopen(filename, "r");
    if (!file) {
        free(dict->words);
        free(dict);
        return NULL;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF && dict->size < MAX_DICTIONARY_SIZE) {
        dict->words[dict->size] = strdup(word);
        dict->size++;
    }

    fclose(file);
    return dict;
}

// Function to free the dictionary memory
void freeDictionary(Dictionary* dict) {
    for (int i = 0; i < dict->size; i++) {
        free(dict->words[i]);
    }
    free(dict->words);
    free(dict);
}

// Function to check if a word is in the dictionary
int checkWord(Dictionary* dict, const char *word) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i], word) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to process the input file and check each word
void processFile(const char *filename, Dictionary *dict) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s.\n", filename);
        return;
    }

    char word[MAX_WORD_LENGTH];
    int misspelledCount = 0;

    while (fscanf(file, "%s", word) != EOF) {
        normalizeWord(word);

        if (!checkWord(dict, word)) {
            printf("Misspelled word: %s\n", word);
            misspelledCount++;
        }
    }

    printf("Total misspelled words: %d\n", misspelledCount);
    
    fclose(file);
}

// Function to normalize a word (remove punctuation, convert to lower case)
void normalizeWord(char *word) {
    char *p = word;
    char *q = word;

    // Remove punctuation and convert to lower case
    while (*p) {
        if (isalpha((unsigned char)*p)) {
            *q++ = tolower((unsigned char)*p);
        }
        p++;
    }
    *q = '\0'; // Null-terminate the normalized string
}
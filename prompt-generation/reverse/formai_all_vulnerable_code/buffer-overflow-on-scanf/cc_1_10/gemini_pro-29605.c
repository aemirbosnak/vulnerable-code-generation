//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// Structure to store a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

// Function to compare two words
int compareWords(const void *a, const void *b) {
    const Word *word1 = (const Word *)a;
    const Word *word2 = (const Word *)b;

    return strcmp(word1->word, word2->word);
}

// Function to check if a word is in the dictionary
int isWordInDictionary(const char *word, const Word *dictionary, int dictionarySize) {
    int low = 0;
    int high = dictionarySize - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (strcmp(word, dictionary[mid].word) == 0) {
            return 1;
        } else if (strcmp(word, dictionary[mid].word) < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return 0;
}

// Function to load the dictionary from a file
int loadDictionary(const char *filename, Word *dictionary) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        return -1;
    }

    int dictionarySize = 0;

    while (fscanf(file, "%s", dictionary[dictionarySize].word) != EOF) {
        dictionarySize++;
    }

    fclose(file);

    return dictionarySize;
}

// Function to check the spelling of a word
int checkSpelling(const char *word, const Word *dictionary, int dictionarySize) {
    if (isWordInDictionary(word, dictionary, dictionarySize)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print the suggestions for a misspelled word
void printSuggestions(const char *word, const Word *dictionary, int dictionarySize) {
    int low = 0;
    int high = dictionarySize - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (strcmp(word, dictionary[mid].word) == 0) {
            printf("The word is spelled correctly.\n");
            return;
        } else if (strcmp(word, dictionary[mid].word) < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("The word is misspelled.\n");
    printf("Suggestions:\n");

    for (int i = low; i <= high; i++) {
        printf("%s\n", dictionary[i].word);
    }
}

// Main function
int main() {
    // Load the dictionary from a file
    Word dictionary[MAX_WORDS];
    int dictionarySize = loadDictionary("dictionary.txt", dictionary);

    // Check the spelling of a word
    char word[MAX_WORD_LENGTH];
    printf("Enter a word: ");
    scanf("%s", word);

    if (checkSpelling(word, dictionary, dictionarySize)) {
        printf("The word is spelled correctly.\n");
    } else {
        printSuggestions(word, dictionary, dictionarySize);
    }

    return 0;
}
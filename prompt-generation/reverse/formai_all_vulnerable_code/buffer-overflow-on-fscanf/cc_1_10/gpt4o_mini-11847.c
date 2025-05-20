//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define DICTIONARY_SIZE 10000

// Function prototypes
void loadDictionary(const char *filename, char dictionary[][MAX_WORD_LEN], size_t *dictSize);
int isWordInDictionary(const char *word, char dictionary[][MAX_WORD_LEN], size_t dictSize);
void toLowerCase(char *str);
void checkSpelling(const char *inputFile, char dictionary[][MAX_WORD_LEN], size_t dictSize);
void suggestCorrections(const char *word, char dictionary[][MAX_WORD_LEN], size_t dictSize);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <dictionary_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char dictionary[DICTIONARY_SIZE][MAX_WORD_LEN];
    size_t dictSize = 0;

    loadDictionary(argv[2], dictionary, &dictSize);
    checkSpelling(argv[1], dictionary, dictSize);

    return EXIT_SUCCESS;
}

void loadDictionary(const char *filename, char dictionary[][MAX_WORD_LEN], size_t *dictSize) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dictionary[*dictSize]) != EOF) {
        toLowerCase(dictionary[*dictSize]);
        (*dictSize)++;
        if (*dictSize >= DICTIONARY_SIZE) {
            fprintf(stderr, "Warning: dictionary size exceeded. Some words may be skipped.\n");
            break;
        }
    }
    fclose(file);
}

int isWordInDictionary(const char *word, char dictionary[][MAX_WORD_LEN], size_t dictSize) {
    for (size_t i = 0; i < dictSize; ++i) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

void toLowerCase(char *str) {
    for (size_t i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

void checkSpelling(const char *inputFile, char dictionary[][MAX_WORD_LEN], size_t dictSize) {
    FILE *file = fopen(inputFile, "r");
    if (!file) {
        perror("Could not open input file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word) != EOF) {
        toLowerCase(word);
        
        if (!isWordInDictionary(word, dictionary, dictSize)) {
            printf("misspelled word: %s\n", word);
            suggestCorrections(word, dictionary, dictSize);
        }
    }
    fclose(file);
}

void suggestCorrections(const char *word, char dictionary[][MAX_WORD_LEN], size_t dictSize) {
    printf("Suggestions for '%s':\n", word);
    size_t count = 0;

    for (size_t i = 0; i < dictSize; ++i) {
        // Simple matching logic for suggestions — within 1 character
        if (abs((int)strlen(dictionary[i]) - (int)strlen(word)) <= 1) {
            int diff = 0;
            for (size_t j = 0; j < strlen(word) && j < strlen(dictionary[i]); j++) {
                if (word[j] != dictionary[i][j]) {
                    diff++;
                }
            }
            diff += abs((int)strlen(dictionary[i]) - (int)strlen(word));
            if (diff <= 1) {
                printf(" - %s\n", dictionary[i]);
                count++;
            }
        }
        if (count >= 5) break; // Limit suggestions to 5
    }

    if (count == 0) {
        printf(" No suggestions available.\n");
    }
}
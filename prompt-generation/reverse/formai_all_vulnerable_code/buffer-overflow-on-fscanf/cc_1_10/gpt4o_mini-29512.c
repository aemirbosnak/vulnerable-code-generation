//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000

void toLowerCase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

bool loadDictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *dictSize) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open dictionary file");
        return false;
    }

    *dictSize = 0;
    while (fscanf(file, "%s", dictionary[*dictSize]) != EOF) {
        (*dictSize)++;
        if (*dictSize >= DICTIONARY_SIZE) {
            break; // Prevents overflow
        }
    }

    fclose(file);
    return true;
}

bool checkWordInDictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return true; // Word found
        }
    }
    return false; // Word not found
}

void spellCheckText(const char *filename, char dictionary[][MAX_WORD_LENGTH], int dictSize) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open text file");
        return;
    }

    char word[MAX_WORD_LENGTH];
    printf("Misspelled words:\n");
    while (fscanf(file, "%s", word) != EOF) {
        // Remove punctuation from word
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            if (ispunct(word[i])) {
                word[i] = '\0';
                break; // Stop at the first punctuation
            }
        }
        toLowerCase(word);

        // Check if word is in dictionary
        if (!checkWordInDictionary(word, dictionary, dictSize)) {
            printf("%s\n", word);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dictSize;

    if (!loadDictionary(argv[1], dictionary, &dictSize)) {
        return EXIT_FAILURE; // Error loading dictionary
    }

    spellCheckText(argv[2], dictionary, dictSize);

    return EXIT_SUCCESS;
}
//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 25
#define MAX_DICTIONARY_SIZE 50000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_valid;
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
int dictionary_size = 0;

void loadDictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading dictionary file\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (dictionary_size >= MAX_DICTIONARY_SIZE) {
            printf("Dictionary is full\n");
            exit(1);
        }

        DictionaryEntry entry = {
           .word = strdup(word),
           .is_valid = true
        };

        int i;
        for (i = 0; i < dictionary_size; i++) {
            if (strcmp(dictionary[i].word, word) == 0) {
                entry.is_valid = false;
                break;
            }
        }

        if (entry.is_valid) {
            dictionary[dictionary_size++] = entry;
        }
    }

    fclose(file);
}

bool isWordValid(const char* word) {
    int i;
    for (i = 0; i < dictionary_size; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return true;
        }
    }

    return false;
}

void spellCheck(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (isWordValid(word)) {
            printf("%s is a valid word\n", word);
        } else {
            printf("%s is not a valid word\n", word);
        }
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        exit(1);
    }

    loadDictionary(argv[1]);
    spellCheck(argv[2]);

    return 0;
}
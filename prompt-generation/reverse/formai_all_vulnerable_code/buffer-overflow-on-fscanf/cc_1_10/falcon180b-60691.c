//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 100000

// Data structure for each word in the dictionary
typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    bool is_valid;
} DictionaryWord;

// Dictionary of valid words
DictionaryWord dictionary[MAX_DICTIONARY_SIZE];
int dictionary_size = 0;

// Load the dictionary from a file
void load_dictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(file, "%s", word) == 1) {
        if (dictionary_size >= MAX_DICTIONARY_SIZE) {
            printf("Error: dictionary is full\n");
            exit(1);
        }

        dictionary[dictionary_size].word[0] = tolower(word[0]);
        strcpy(dictionary[dictionary_size].word + 1, word + 1);
        dictionary[dictionary_size].is_valid = true;
        dictionary_size++;
    }

    fclose(file);
}

// Check if a word is in the dictionary
bool is_valid_word(const char* word) {
    for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return true;
        }
    }

    return false;
}

// Spell checking function
void spell_check(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(file, "%s", word) == 1) {
        if (is_valid_word(word)) {
            printf("%s is a valid word\n", word);
        } else {
            printf("%s is not a valid word\n", word);
        }
    }

    fclose(file);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s dictionary_file text_file\n", argv[0]);
        return 1;
    }

    load_dictionary(argv[1]);
    spell_check(argv[2]);

    return 0;
}
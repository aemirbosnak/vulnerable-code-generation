//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 30

// Create a dictionary of words
char* dictionary[MAX_WORDS];
int dictionary_size = 0;

// Load the dictionary from a file
void load_dictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        // Add the word to the dictionary
        dictionary[dictionary_size++] = strdup(word);
    }

    fclose(file);
}

// Check if a word is in the dictionary
bool is_in_dictionary(char* word) {
    for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }

    return false;
}

// Spell check a document
void spell_check(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        // Remove punctuation from the word
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
                break;
            }
        }

        // Check if the word is in the dictionary
        if (!is_in_dictionary(word)) {
            printf("%s is not in the dictionary.\n", word);
        }
    }

    fclose(file);
}

int main() {
    // Load the dictionary
    load_dictionary("dictionary.txt");

    // Spell check a document
    spell_check("document.txt");

    return 0;
}
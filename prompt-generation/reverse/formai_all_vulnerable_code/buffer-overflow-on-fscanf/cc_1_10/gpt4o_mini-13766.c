//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000

// Function prototypes
void load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *word_count);
int check_word(const char *word, char dictionary[][MAX_WORD_LENGTH], int word_count);
void to_lowercase(char *str);
void check_spelling(const char *filename, char dictionary[][MAX_WORD_LENGTH], int word_count);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <input_file>\n", argv[0]);
        return 1;
    }

    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int word_count = 0;

    load_dictionary(argv[1], dictionary, &word_count);
    check_spelling(argv[2], dictionary, word_count);

    return 0;
}

// Load the dictionary from a file
void load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *word_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening dictionary file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", dictionary[*word_count]) != EOF) {
        to_lowercase(dictionary[*word_count]);
        (*word_count)++;
        if (*word_count >= DICTIONARY_SIZE) break;
    }

    fclose(file);
}

// Check if the word is in the dictionary
int check_word(const char *word, char dictionary[][MAX_WORD_LENGTH], int word_count) {
    for (int i = 0; i < word_count; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word is found
        }
    }
    return 0; // Word is not found
}

// Convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Check spelling of words in the input file
void check_spelling(const char *filename, char dictionary[][MAX_WORD_LENGTH], int word_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        to_lowercase(word);
        // Remove punctuation
        char *p = word;
        while (*p) {
            if (ispunct((unsigned char)*p)) {
                *p = '\0'; // Replace punctuation with null character
                break;
            }
            p++;
        }

        if (!check_word(word, dictionary, word_count)) {
            printf("Misspelled: %s\n", word);
        }
    }

    fclose(file);
}
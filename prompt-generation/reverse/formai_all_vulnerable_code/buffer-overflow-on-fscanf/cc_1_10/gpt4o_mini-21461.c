//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define DICT_SIZE 1000
#define INPUT_SIZE 1000

// Function prototypes
void load_dictionary(const char *filename, char dictionary[][MAX_WORD_LEN], int *dict_size);
int is_word_in_dictionary(const char *word, char dictionary[][MAX_WORD_LEN], int dict_size);
void check_spelling(const char *input_text, char dictionary[][MAX_WORD_LEN], int dict_size);

int main() {
    char dictionary[DICT_SIZE][MAX_WORD_LEN];
    int dict_size = 0;

    load_dictionary("dictionary.txt", dictionary, &dict_size);

    // Sample input text to check
    char input_text[INPUT_SIZE];
    printf("Enter a text (max %d characters): ", INPUT_SIZE - 1);
    fgets(input_text, INPUT_SIZE, stdin);

    check_spelling(input_text, dictionary, dict_size);

    return 0;
}

void load_dictionary(const char *filename, char dictionary[][MAX_WORD_LEN], int *dict_size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open dictionary file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dictionary[*dict_size]) != EOF && *dict_size < DICT_SIZE) {
        (*dict_size)++;
    }

    fclose(file);
}

int is_word_in_dictionary(const char *word, char dictionary[][MAX_WORD_LEN], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

void check_spelling(const char *input_text, char dictionary[][MAX_WORD_LEN], int dict_size) {
    char word[MAX_WORD_LEN];
    int index = 0;

    printf("Checking spelling...\n");

    for (int i = 0; input_text[i] != '\0'; i++) {
        if (input_text[i] == ' ' || input_text[i] == '\n' || input_text[i] == '\t') {
            if (index > 0) {
                word[index] = '\0';
                if (!is_word_in_dictionary(word, dictionary, dict_size)) {
                    printf("Misspelled word: %s\n", word);
                }
                index = 0; // Reset word index
            }
        } else {
            if (index < MAX_WORD_LEN - 1) {
                word[index++] = input_text[i]; // Build the word
            }
        }
    }

    // Check the last word if exists
    if (index > 0) {
        word[index] = '\0';
        if (!is_word_in_dictionary(word, dictionary, dict_size)) {
            printf("Misspelled word: %s\n", word);
        }
    }
}
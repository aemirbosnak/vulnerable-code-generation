//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define constants
#define MAX_WORD_LEN 100
#define DICTIONARY_SIZE 1000
#define BUFFER_SIZE 1024

// Function prototypes
void load_dictionary(const char* filename, char dictionary[][MAX_WORD_LEN], int* dict_size);
int is_word_in_dictionary(const char* word, char dictionary[][MAX_WORD_LEN], int dict_size);
void make_lowercase(char* str);
void check_spelling(const char* text_file, char dictionary[][MAX_WORD_LEN], int dict_size);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Load dictionary from file
    char dictionary[DICTIONARY_SIZE][MAX_WORD_LEN];
    int dict_size = 0;
    load_dictionary(argv[1], dictionary, &dict_size);

    // Check spelling in the given text file
    check_spelling(argv[2], dictionary, dict_size);

    return 0;
}

void load_dictionary(const char* filename, char dictionary[][MAX_WORD_LEN], int* dict_size) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dictionary[*dict_size]) != EOF && *dict_size < DICTIONARY_SIZE) {
        make_lowercase(dictionary[*dict_size]);
        (*dict_size)++;
    }

    fclose(file);
}

int is_word_in_dictionary(const char* word, char dictionary[][MAX_WORD_LEN], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

void make_lowercase(char* str) {
    for (char* p = str; *p; p++) {
        *p = (char)tolower(*p);
    }
}

void check_spelling(const char* text_file, char dictionary[][MAX_WORD_LEN], int dict_size) {
    FILE* file = fopen(text_file, "r");
    if (!file) {
        perror("Could not open text file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        char* token = strtok(buffer, " \n");
        while (token != NULL) {
            char word[MAX_WORD_LEN];
            strncpy(word, token, MAX_WORD_LEN);
            word[MAX_WORD_LEN - 1] = '\0'; // Ensure null-termination
            make_lowercase(word);
            if (!is_word_in_dictionary(word, dictionary, dict_size)) {
                printf("Misspelled word: %s\n", token);
            }
            token = strtok(NULL, " \n");
        }
    }

    fclose(file);
}
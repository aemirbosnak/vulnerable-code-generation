//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000
#define MAX_LINE_LENGTH 256

// Function to convert a word to lowercase
void to_lowercase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

// Function to check if a word exists in the dictionary
int check_word(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found in dictionary
        }
    }
    return 0; // Word not found
}

// Function to load the dictionary from a file
int load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open dictionary file.\n");
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s", dictionary[count]) != EOF && count < DICTIONARY_SIZE) {
        to_lowercase(dictionary[count]); // Store words in lowercase
        count++;
    }

    fclose(file);
    return count; // Return the number of words loaded into the dictionary
}

// Function to check spelling in a given text file
void check_spelling(const char *filename, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open text file.\n");
        return;
    }

    char word[MAX_WORD_LENGTH];
    int line_number = 1;
    while (fgets(word, sizeof(word), file)) {
        char *token = strtok(word, " \n");
        while (token != NULL) {
            to_lowercase(token);
            if (!check_word(token, dictionary, dict_size)) {
                printf("Misspelled word found in line %d: %s\n", line_number, token);
            }
            token = strtok(NULL, " \n");
        }
        line_number++;
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dict_size = load_dictionary(argv[1], dictionary);
    if (dict_size < 0) return 1;

    check_spelling(argv[2], dictionary, dict_size);
    
    return 0;
}
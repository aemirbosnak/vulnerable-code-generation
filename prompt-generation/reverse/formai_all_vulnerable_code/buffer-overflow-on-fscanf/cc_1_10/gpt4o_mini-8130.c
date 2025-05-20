//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICT_SIZE 1000
#define MAX_INPUT_SIZE 500

// A structure to represent a word and its status
typedef struct {
    char word[MAX_WORD_LENGTH];
    int is_correct;
} WordEntry;

// Dictionary to hold valid words
WordEntry dictionary[MAX_DICT_SIZE];
int dict_size = 0;

// Function to load dictionary from file
void load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "The world is dark and empty, the dictionary is missing.\n");
        exit(1);
    }
    
    while (fscanf(file, "%s", dictionary[dict_size].word) == 1) {
        dictionary[dict_size].is_correct = 1; // Mark this word as correct
        dict_size++;
        if (dict_size >= MAX_DICT_SIZE) {
            break; // Avoid overflow
        }
    }
    fclose(file);
    printf("The remnants of civilization's words have been found, %d words loaded.\n", dict_size);
}

// Function to check if a word is in the dictionary
int check_word(const char *word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcasecmp(dictionary[i].word, word) == 0) {
            return 1; // Word is correct
        }
    }
    return 0; // Word is incorrect
}

// Function to split input into words
void split_input(const char *input, char words[][MAX_WORD_LENGTH], int *count) {
    char *token;
    char *input_copy = strdup(input); // Duplicate the input to work with
    token = strtok(input_copy, " ,.;!?-\n");

    *count = 0; // Reset word count
    while (token != NULL) {
        strncpy(words[*count], token, MAX_WORD_LENGTH);
        (*count)++;
        token = strtok(NULL, " ,.;!?-\n");
    }
    
    free(input_copy); // Release allocated memory
}

// Main spell checker function
void spell_check(const char *input) {
    char words[MAX_INPUT_SIZE][MAX_WORD_LENGTH];
    int word_count = 0;

    split_input(input, words, &word_count);
    
    printf("Scanning the ashes for errors...\n");
    for (int i = 0; i < word_count; i++) {
        if (!check_word(words[i])) {
            printf("Mistake found: '%s'\n", words[i]);
        }
    }
    printf("The search is over.\n");
}

// Main function
int main() {
    // Load the dark remnants of a dictionary
    load_dictionary("dictionary.txt");

    char input[MAX_INPUT_SIZE];
    printf("In this desolate world, type your text below for spell checking:\n");

    // Accept input from the user
    if (fgets(input, MAX_INPUT_SIZE, stdin) != NULL) {
        spell_check(input);
    }

    printf("May the lost words return to you. The path of language is dangerous, tread carefully.\n");

    return 0;
}
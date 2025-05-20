//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 50

// The dictionary
char *dictionary[MAX_WORDS];
int num_words = 0;

// Function to load the dictionary from a file
void load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, fp) != NULL) {
        // Remove the newline character
        line[strlen(line) - 1] = '\0';

        // Add the word to the dictionary
        dictionary[num_words++] = strdup(line);
    }

    fclose(fp);
}

// Function to check if a word is in the dictionary
int is_in_dictionary(char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// Function to check the spelling of a word
int check_spelling(char *word) {
    // Convert the word to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    // Check if the word is in the dictionary
    if (is_in_dictionary(word)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to get user input
char *get_user_input() {
    char *input = malloc(MAX_WORD_LEN);
    if (input == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    printf("Enter a word: ");
    scanf("%s", input);

    return input;
}

// Main function
int main() {
    // Load the dictionary
    load_dictionary("dictionary.txt");

    // Get user input
    char *input = get_user_input();

    // Check the spelling of the word
    if (check_spelling(input)) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is spelled incorrectly.\n");
    }

    // Free the memory allocated for the user input
    free(input);

    return 0;
}
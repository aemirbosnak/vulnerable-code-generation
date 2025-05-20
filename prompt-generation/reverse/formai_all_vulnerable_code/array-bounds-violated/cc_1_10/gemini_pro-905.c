//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

// Declare the dictionary
char *dictionary[MAX_WORDS];
int num_words = 0;

// Load the dictionary from a file
void load_dictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error opening dictionary file\n");
        exit(1);
    }

    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, fp)) {
        // Remove the newline character from the word
        line[strlen(line) - 1] = '\0';

        // Add the word to the dictionary
        dictionary[num_words++] = strdup(line);
    }

    fclose(fp);
}

// Check if a word is in the dictionary
int is_in_dictionary(char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// Print a list of misspelled words
void print_misspellings(char *text) {
    char *words[MAX_WORDS];
    int num_words = 0;

    // Split the text into words
    char *word = strtok(text, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Check each word for misspellings
    for (int i = 0; i < num_words; i++) {
        // Convert the word to lowercase
        for (int j = 0; j < strlen(words[i]); j++) {
            words[i][j] = tolower(words[i][j]);
        }

        // Check if the word is in the dictionary
        if (!is_in_dictionary(words[i])) {
            printf("%s\n", words[i]);
        }
    }
}

// Get the user input
char *get_user_input() {
    char *text = NULL;
    size_t len = 0;

    printf("Enter some text: ");
    getline(&text, &len, stdin);

    return text;
}

// Main function
int main() {
    // Load the dictionary
    load_dictionary();

    // Get the user input
    char *text = get_user_input();

    // Print the list of misspelled words
    print_misspellings(text);

    // Free the allocated memory
    free(text);

    return 0;
}
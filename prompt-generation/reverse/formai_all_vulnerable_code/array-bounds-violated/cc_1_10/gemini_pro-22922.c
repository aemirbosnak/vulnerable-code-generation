//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

// Function prototypes
void load_dictionary(char *filename);
int check_spelling(char *word, char *dictionary[]);
void print_suggestions(char *word, char *dictionary[]);

// Global variables
char *dictionary[MAX_WORDS];
int num_words = 0;

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc != 2) {
        printf("Usage: %s <dictionary_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Load the dictionary
    load_dictionary(argv[1]);

    // Get the word to check
    char word[MAX_WORD_LEN];
    printf("Enter a word to check: ");
    scanf("%s", word);

    // Check the spelling
    int result = check_spelling(word, dictionary);

    // Print the result
    if (result) {
        printf("The word \"%s\" is spelled correctly.\n", word);
    } else {
        printf("The word \"%s\" is spelled incorrectly.\n", word);
        print_suggestions(word, dictionary);
    }

    return EXIT_SUCCESS;
}

void load_dictionary(char *filename) {
    // Open the dictionary file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    // Read the words from the dictionary file
    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, fp)) {
        // Remove the newline character
        line[strlen(line) - 1] = '\0';

        // Add the word to the dictionary
        dictionary[num_words++] = strdup(line);
    }

    // Close the dictionary file
    fclose(fp);
}

int check_spelling(char *word, char *dictionary[]) {
    // Loop through the dictionary
    for (int i = 0; i < num_words; i++) {
        // Check if the word is in the dictionary
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    // The word is not in the dictionary
    return 0;
}

void print_suggestions(char *word, char *dictionary[]) {
    // Find words in the dictionary that are similar to the misspelled word
    char suggestions[MAX_WORDS][MAX_WORD_LEN];
    int num_suggestions = 0;

    for (int i = 0; i < num_words; i++) {
        // Check if the word is similar to the misspelled word
        if (strcmp(word, dictionary[i]) != 0 &&
            strncmp(word, dictionary[i], strlen(word)) == 0) {
            // Add the word to the list of suggestions
            strcpy(suggestions[num_suggestions++], dictionary[i]);
        }
    }

    // Print the suggestions
    if (num_suggestions > 0) {
        printf("Suggestions:\n");
        for (int i = 0; i < num_suggestions; i++) {
            printf(" - %s\n", suggestions[i]);
        }
    } else {
        printf("No suggestions found.\n");
    }
}
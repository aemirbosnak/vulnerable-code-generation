//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

// Declare the word list
char *wordlist[MAX_WORDS];

// Load the word list from a file
void load_wordlist(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening word list file");
        exit(EXIT_FAILURE);
    }

    // Read the words from the file
    int i = 0;
    while (fscanf(file, "%s", wordlist[i]) != EOF) {
        i++;
    }

    // Close the file
    fclose(file);
}

// Check if a word is in the word list
int is_word_in_list(const char *word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(word, wordlist[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// Spell check a document
void spell_check(const char *document) {
    // Open the document
    FILE *file = fopen(document, "r");
    if (file == NULL) {
        perror("Error opening document");
        exit(EXIT_FAILURE);
    }

    // Read the document line by line
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Tokenize the line into words
        char *tokens = strtok(line, " ,.-?!");
        while (tokens != NULL) {
            // Check if the word is in the word list
            if (!is_word_in_list(tokens)) {
                // If the word is not in the word list, print it
                printf("Misspelled word: %s\n", tokens);
            }

            // Get the next token
            tokens = strtok(NULL, " ,.-?!");
        }
    }

    // Close the file
    fclose(file);
}

// Main function
int main(int argc, char **argv) {
    // Check if the user specified a document
    if (argc < 2) {
        printf("Usage: %s <document>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load the word list
    load_wordlist("wordlist.txt");

    // Spell check the document
    spell_check(argv[1]);

    return EXIT_SUCCESS;
}
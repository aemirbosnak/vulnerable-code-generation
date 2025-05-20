//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

// Function to load the dictionary into a hash table
void load_dictionary(char *filename, char *table[]) {
    // Open the dictionary file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    // Read each word from the file and add it to the hash table
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        // Convert the word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Add the word to the hash table
        int index = hash(word);
        table[index] = strdup(word);
    }

    // Close the dictionary file
    fclose(file);
}

// Function to hash a word
int hash(char *word) {
    int hash = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash += word[i];
    }
    return hash % MAX_WORDS;
}

// Function to check if a word is in the dictionary
int is_in_dictionary(char *word, char *table[]) {
    // Convert the word to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    // Get the hash index of the word
    int index = hash(word);

    // Check if the word is in the hash table
    return table[index] != NULL && strcmp(table[index], word) == 0;
}

// Function to check the spelling of a word
int check_spelling(char *word, char *table[]) {
    // Check if the word is in the dictionary
    if (is_in_dictionary(word, table)) {
        return 1;
    }

    // Check if the word is a known misspelling
    char *misspellings[] = {"teh", "teh", "teh", "teh", "teh", "teh", "teh", "teh", "teh", "teh"};
    for (int i = 0; i < sizeof(misspellings) / sizeof(char*); i++) {
        if (strcmp(word, misspellings[i]) == 0) {
            return 1;
        }
    }

    // The word is not in the dictionary or a known misspelling
    return 0;
}

// Function to print the suggestions
void print_suggestions(char *word, char *table[]) {
    // Get the hash index of the word
    int index = hash(word);

    // Iterate over the hash table and print the words that are similar to the input word
    for (int i = index - 1; i <= index + 1; i++) {
        if (table[i] != NULL && strcmp(table[i], word) != 0) {
            printf("%s\n", table[i]);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided a dictionary file
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dictionary file>\n", argv[0]);
        exit(1);
    }

    // Load the dictionary into a hash table
    char *table[MAX_WORDS];
    load_dictionary(argv[1], table);

    // Get the input word from the user
    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check: ");
    scanf("%s", word);

    // Check the spelling of the word
    if (check_spelling(word, table)) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is spelled incorrectly.\n");
        printf("Suggestions:\n");
        print_suggestions(word, table);
    }

    // Free the memory allocated for the hash table
    for (int i = 0; i < MAX_WORDS; i++) {
        free(table[i]);
    }

    return 0;
}
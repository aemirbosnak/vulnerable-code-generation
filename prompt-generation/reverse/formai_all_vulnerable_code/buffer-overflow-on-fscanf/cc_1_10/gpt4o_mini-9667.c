//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_FILE "dictionary.txt"
#define MAX_DICTIONARY_WORDS 10000

char dictionary[MAX_DICTIONARY_WORDS][MAX_WORD_LENGTH];
int word_count = 0;

// Function prototypes
void load_dictionary();
int is_word_in_dictionary(char *word);
void to_lowercase(char *word);
void check_spelling(char *filename);

int main() {
    printf("Welcome to the Spell Checker!\n");
    
    // Loading the words from the dictionary file.
    load_dictionary();
    printf("Dictionary loaded with %d words.\n\n", word_count);
    
    // Prompting user for the text file to check
    char filename[MAX_WORD_LENGTH];
    printf("Please provide the name of the text file to check: ");
    scanf("%s", filename);
    
    check_spelling(filename);
    
    printf("Spell checking completed!\n");
    
    return 0;
}

// Function to load the dictionary into memory.
void load_dictionary() {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    if (file == NULL) {
        printf("Could not open dictionary file: %s\n", DICTIONARY_FILE);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dictionary[word_count]) == 1) {
        to_lowercase(dictionary[word_count]);
        word_count++;
        if (word_count >= MAX_DICTIONARY_WORDS) {
            printf("Dictionary capacity reached!\n");
            break;
        }
    }

    fclose(file);
}

// Function to check if a word exists in the dictionary.
int is_word_in_dictionary(char *word) {
    for (int i = 0; i < word_count; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1; // The word is found
        }
    }
    return 0; // The word is not found
}

// Function to convert a string to lowercase.
void to_lowercase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

// Function to check the spelling of words in the provided file.
void check_spelling(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open the file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("Checking spelling in the file: %s\n", filename);
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        to_lowercase(word);
        if (!is_word_in_dictionary(word)) {
            printf("Misspelled word: %s\n", word);
        }
    }

    fclose(file);
}
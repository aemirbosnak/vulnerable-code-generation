//FormAI DATASET v1.0 Category: Spell checking ; Style: shocked
// C program for spell checking
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50 // Maximum word size to be checked
#define DICTIONARY_SIZE 380061 // Size of english dictionary

char *dictionary[DICTIONARY_SIZE]; // Array of dictionary words
int dict_size = 0; // Size of dictionary
char word[MAX_WORD_SIZE]; // Word to be checked

// Loads the dictionary file into memory
void load_dictionary() {
    FILE *fp = fopen("dictionary.txt", "r");

    if (fp == NULL) {
        printf("Error loading dictionary file! Exiting program...");
        exit(1);
    }

    char buffer[MAX_WORD_SIZE];

    while (fgets(buffer, MAX_WORD_SIZE, fp) != NULL) {
        buffer[strlen(buffer) - 1] = '\0'; // Remove newline character
        dictionary[dict_size++] = strdup(buffer); // Add dictionary word to array
    }

    fclose(fp);
}

// Checks if a word is spelled correctly based on dictionary
int check_spelling(char *word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1; // Word spelled correctly
        }
    }

    return 0; // Word not found in dictionary
}

// Converts a word to lowercase
void to_lowercase(char *word) {
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }
}

int main() {
    load_dictionary(); // Load dictionary into memory

    printf("Enter a word to check spelling: ");
    scanf("%s", word);

    to_lowercase(word); // Convert word to lowercase

    if (check_spelling(word)) {
        printf("Spelling is correct!");
    } else {
        printf("Spelling is incorrect!");
    }

    return 0;
}
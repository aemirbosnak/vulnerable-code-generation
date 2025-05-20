//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Define the maximum number of words in the dictionary
#define MAX_DICTIONARY_SIZE 10000

// Define the dictionary
char* dictionary[MAX_DICTIONARY_SIZE];

// Initialize the dictionary
void init_dictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file\n");
        exit(1);
    }

    int i = 0;
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
        // Remove the newline character from the end of the word
        line[strlen(line) - 1] = '\0';

        // Add the word to the dictionary
        dictionary[i++] = strdup(line);
    }

    fclose(fp);
}

// Check if a word is in the dictionary
int is_in_dictionary(char* word) {
    for (int i = 0; i < MAX_DICTIONARY_SIZE; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// Check the spelling of a word
int check_spelling(char* word) {
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

// Get a word from the user
char* get_word() {
    char* word = malloc(MAX_WORD_LENGTH);
    printf("Enter a word: ");
    scanf("%s", word);

    return word;
}

// Print a message indicating whether a word is spelled correctly
void print_result(char* word, int is_spelled_correctly) {
    if (is_spelled_correctly) {
        printf("%s is spelled correctly\n", word);
    } else {
        printf("%s is not spelled correctly\n", word);
    }
}

// Main function
int main() {
    // Initialize the dictionary
    init_dictionary();

    // Get a word from the user
    char* word = get_word();

    // Check the spelling of the word
    int is_spelled_correctly = check_spelling(word);

    // Print a message indicating whether the word is spelled correctly
    print_result(word, is_spelled_correctly);

    // Free the memory allocated for the word
    free(word);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in the dictionary
#define MAX_DICTIONARY_SIZE 10000

// Define the structure of a word in the dictionary
typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} Word;

// Define the dictionary
Word dictionary[MAX_DICTIONARY_SIZE];

// Define the number of words in the dictionary
int dictionary_size = 0;

// Function to add a word to the dictionary
void add_word(char *word) {
    // Convert the word to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    // Check if the word is already in the dictionary
    for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            // If the word is already in the dictionary, increment its count
            dictionary[i].count++;
            return;
        }
    }

    // If the word is not in the dictionary, add it to the dictionary
    strcpy(dictionary[dictionary_size].word, word);
    dictionary[dictionary_size].count = 1;
    dictionary_size++;
}

// Function to print the dictionary
void print_dictionary() {
    for (int i = 0; i < dictionary_size; i++) {
        printf("%s: %d\n", dictionary[i].word, dictionary[i].count);
    }
}

int main() {
    // Get the input text from the user
    char input[10000];
    printf("Enter the text: ");
    gets(input);

    // Tokenize the input text into words
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Add the word to the dictionary
        add_word(token);

        // Get the next word
        token = strtok(NULL, " ");
    }

    // Print the dictionary
    printf("Word Frequency Count:\n");
    print_dictionary();

    return 0;
}
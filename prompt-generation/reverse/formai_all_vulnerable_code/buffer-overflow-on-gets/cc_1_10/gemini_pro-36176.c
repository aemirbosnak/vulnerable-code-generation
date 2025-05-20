//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum size of a word
#define MAX_WORD_SIZE 100

// Define the maximum number of words to count
#define MAX_WORD_COUNT 1000

// Create a struct to store the word and its count
typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} Word;

// Create an array of words to store the word and its count
Word words[MAX_WORD_COUNT];

// Define the number of words in the array
int word_count = 0;

// Function to add a word to the array
void add_word(char *word) {
    // Convert the word to lowercase
    for (int i = 0; word[i] != '\0'; i++) {
        word[i] = tolower(word[i]);
    }

    // Check if the word is already in the array
    for (int i = 0; i < word_count; i++) {
        if (strcmp(words[i].word, word) == 0) {
            // If the word is already in the array, increment its count
            words[i].count++;
            return;
        }
    }

    // If the word is not in the array, add it to the array
    if (word_count < MAX_WORD_COUNT) {
        strcpy(words[word_count].word, word);
        words[word_count].count = 1;
        word_count++;
    }
}

// Function to print the words and their counts
void print_words() {
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

// Main function
int main() {
    // Get the input from the user
    char input[1000];
    printf("Enter a string: ");
    gets(input);

    // Tokenize the input string and add each word to the array
    char *token = strtok(input, " ");
    while (token != NULL) {
        add_word(token);
        token = strtok(NULL, " ");
    }

    // Print the words and their counts
    print_words();

    return 0;
}
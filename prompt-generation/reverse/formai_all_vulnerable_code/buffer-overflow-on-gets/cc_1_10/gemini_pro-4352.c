//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words to store
#define MAX_WORDS 1000

// Define the maximum length of a word
#define MAX_WORD_LENGTH 50

// Define the structure of a word frequency pair
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} word_frequency_pair;

// Function to compare two word frequency pairs by frequency
int compare_word_frequency_pairs(const void *a, const void *b) {
    const word_frequency_pair *pair1 = (const word_frequency_pair *)a;
    const word_frequency_pair *pair2 = (const word_frequency_pair *)b;

    return pair2->frequency - pair1->frequency;
}

// Function to count the frequency of words in a string
void count_word_frequencies(char *string, word_frequency_pair *word_frequencies, int *num_words) {
    // Tokenize the string into words
    char *token = strtok(string, " \t\n\r");
    while (token != NULL) {
        // Check if the word is already in the list
        int found = 0;
        for (int i = 0; i < *num_words; i++) {
            if (strcmp(token, word_frequencies[i].word) == 0) {
                // Increment the frequency of the word
                word_frequencies[i].frequency++;
                found = 1;
                break;
            }
        }

        // If the word is not in the list, add it
        if (!found) {
            // Check if the list is full
            if (*num_words >= MAX_WORDS) {
                printf("Error: The list of words is full.\n");
                return;
            }

            // Add the word to the list
            strcpy(word_frequencies[*num_words].word, token);
            word_frequencies[*num_words].frequency = 1;
            (*num_words)++;
        }

        // Get the next token
        token = strtok(NULL, " \t\n\r");
    }
}

// Function to print the word frequencies
void print_word_frequencies(word_frequency_pair *word_frequencies, int num_words) {
    // Sort the word frequencies by frequency
    qsort(word_frequencies, num_words, sizeof(word_frequency_pair), compare_word_frequency_pairs);

    // Print the word frequencies
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }
}

// Main function
int main() {
    // Get the input string from the user
    char string[1000];
    printf("Enter a string: ");
    gets(string);

    // Initialize the word frequencies
    word_frequency_pair word_frequencies[MAX_WORDS];
    int num_words = 0;

    // Count the word frequencies
    count_word_frequencies(string, word_frequencies, &num_words);

    // Print the word frequencies
    print_word_frequencies(word_frequencies, num_words);

    return 0;
}
//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: brave
/*
 * C Word Frequency Counter
 *
 * This program counts the frequency of each word in a text file.
 *
 * Usage:
 *  ./word_frequency_counter <filename>
 *
 * Example:
 *  ./word_frequency_counter example.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 256

// Structure to store a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function to print the word frequency
void print_word_frequency(WordFrequency* words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

// Function to count the frequency of each word in a text file
int count_word_frequency(char* filename, WordFrequency* words, int max_words) {
    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    // Initialize variables
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    bool in_word = false;

    // Read the file and count the frequency of each word
    while (fscanf(file, "%s", word) != EOF) {
        // Check if the word is already in the list
        bool found = false;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(word, words[i].word) == 0) {
                found = true;
                words[i].frequency++;
                break;
            }
        }

        // Add the word to the list if it's not already there
        if (!found) {
            if (word_count >= max_words) {
                printf("Maximum number of words exceeded\n");
                break;
            }
            strcpy(words[word_count].word, word);
            words[word_count].frequency = 1;
            word_count++;
        }
    }

    // Close the file
    fclose(file);

    // Print the word frequency
    print_word_frequency(words, word_count);

    // Return the number of words
    return word_count;
}

// Main function
int main(int argc, char* argv[]) {
    // Check the number of arguments
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Declare the word frequency array
    WordFrequency words[100];

    // Count the frequency of each word in the file
    int num_words = count_word_frequency(argv[1], words, 100);
    if (num_words < 0) {
        return 1;
    }

    // Print the total number of words
    printf("Total number of words: %d\n", num_words);

    // Return success
    return 0;
}
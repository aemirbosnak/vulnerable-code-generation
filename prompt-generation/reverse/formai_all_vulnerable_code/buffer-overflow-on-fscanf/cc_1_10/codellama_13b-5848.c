//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: careful
/*
 * Word Frequency Counter
 *
 * This program reads a text file and counts the frequency of each word.
 * It uses a hash table to store the word frequencies.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 10000

// Structure to store a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Hash table to store the word frequencies
WordFrequency word_frequencies[MAX_NUM_WORDS];

// Function to hash a word to an index in the hash table
int hash_word(char *word) {
    int hash = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash += word[i];
    }
    return hash % MAX_NUM_WORDS;
}

// Function to add a word to the hash table
void add_word(char *word) {
    int hash = hash_word(word);
    WordFrequency *word_freq = &word_frequencies[hash];
    if (strcmp(word_freq->word, "") == 0) {
        // Word not found in hash table, add it
        strcpy(word_freq->word, word);
        word_freq->frequency = 1;
    } else {
        // Word already found in hash table, increment its frequency
        word_freq->frequency++;
    }
}

// Function to print the hash table
void print_hash_table() {
    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        WordFrequency *word_freq = &word_frequencies[i];
        if (strcmp(word_freq->word, "") != 0) {
            printf("%s: %d\n", word_freq->word, word_freq->frequency);
        }
    }
}

int main() {
    // Read a text file and add each word to the hash table
    char word[MAX_WORD_LENGTH];
    while (fscanf(stdin, "%s", word) != EOF) {
        add_word(word);
    }

    // Print the hash table
    print_hash_table();

    return 0;
}
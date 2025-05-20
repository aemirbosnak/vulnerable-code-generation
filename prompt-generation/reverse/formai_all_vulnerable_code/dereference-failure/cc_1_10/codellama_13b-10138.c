//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: complex
/*
 * C Word Frequency Counter Example Program
 *
 * This program takes a string as input and outputs the frequency of each word in the string.
 *
 * Usage:
 *
 *   $ ./word_freq <string>
 *
 *   <string> is a string to be analyzed.
 *
 * Example:
 *
 *   $ ./word_freq "Hello, World! How are you?"
 *
 *   Frequency of 'Hello': 1
 *   Frequency of 'World': 1
 *   Frequency of 'How': 1
 *   Frequency of 'are': 1
 *   Frequency of 'you': 1
 *   Frequency of '?': 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

// Struct to store a word and its frequency
struct word_freq {
    char word[MAX_WORD_LENGTH];
    int freq;
};

// Function to tokenize a string and count the frequency of each word
void word_freq_count(char *str) {
    struct word_freq words[MAX_WORDS];
    char *token;
    int i = 0, j = 0;

    // Tokenize the string
    token = strtok(str, " ,.!?");

    // Loop through each token and increment the frequency of each word
    while (token != NULL) {
        // Check if the word is already in the list
        for (i = 0; i < j; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].freq++;
                goto next;
            }
        }

        // If the word is not in the list, add it to the list
        strcpy(words[j].word, token);
        words[j].freq = 1;
        j++;

next:
        token = strtok(NULL, " ,.!?");
    }

    // Print the frequency of each word
    for (i = 0; i < j; i++) {
        printf("Frequency of '%s': %d\n", words[i].word, words[i].freq);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    word_freq_count(argv[1]);

    return 0;
}
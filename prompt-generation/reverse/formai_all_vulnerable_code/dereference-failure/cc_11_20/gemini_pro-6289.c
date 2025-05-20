//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: decentralized
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main function
int main(void) {
    // Create an array of word counters, with a maximum of 1000 unique words
    int word_counters[1000] = {0};

    // Get the input text from the user
    char input_text[10000];
    printf("Enter your text: ");
    fgets(input_text, sizeof(input_text), stdin);

    // Tokenize the input text into words
    char *token = strtok(input_text, " ");
    while (token != NULL) {
        // Convert the word to lowercase and remove punctuation
        char *word = malloc(strlen(token) + 1);
        strcpy(word, token);
        for (char *p = word; *p != '\0'; p++) {
            *p = tolower(*p);
            if (ispunct(*p)) {
                *p = '\0';
            }
        }

        // Find the index of the word in the word_counters array, or -1 if the word is not found
        int index = -1;
        for (int i = 0; i < 1000; i++) {
            if (strcmp(word, word_counters[i]) == 0) {
                index = i;
                break;
            }
        }

        // If the word is not found, add it to the array and initialize its counter to 1
        if (index == -1) {
            index = 0;
            while (word_counters[index] != 0) {
                index++;
            }
            word_counters[index] = malloc(strlen(word) + 1);
            strcpy(word_counters[index], word);
        }

        // Increment the counter for the word
        word_counters[index]++;

        // Free the memory allocated for the word
        free(word);

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Print the word frequencies
    printf("\nWord frequencies:\n");
    for (int i = 0; i < 1000; i++) {
        if (word_counters[i] != 0) {
            printf("%s: %d\n", word_counters[i], word_counters[i]);
        }
    }

    // Free the memory allocated for the word counters
    for (int i = 0; i < 1000; i++) {
        if (word_counters[i] != 0) {
            free(word_counters[i]);
        }
    }

    return 0;
}
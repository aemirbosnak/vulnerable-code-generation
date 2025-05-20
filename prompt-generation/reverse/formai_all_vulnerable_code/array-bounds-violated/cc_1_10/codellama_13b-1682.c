//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: Romeo and Juliet
// A unique C Word Frequency Counter example program in a Romeo and Juliet style
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store the word and its frequency
typedef struct {
    char word[50];
    int frequency;
} WordFrequency;

// Function to count the frequency of each word in a given string
int count_frequency(char *str, WordFrequency *word_freq) {
    // Initialize the frequency of each word to 0
    for (int i = 0; i < 50; i++) {
        word_freq[i].frequency = 0;
    }

    // Split the string into words
    char *token = strtok(str, " ");
    while (token != NULL) {
        // Check if the word is already in the list
        int found = 0;
        for (int i = 0; i < 50; i++) {
            if (strcmp(word_freq[i].word, token) == 0) {
                found = 1;
                word_freq[i].frequency++;
                break;
            }
        }

        // If the word is not found, add it to the list
        if (!found) {
            strcpy(word_freq[0].word, token);
            word_freq[0].frequency = 1;
        }

        // Get the next word
        token = strtok(NULL, " ");
    }

    return 0;
}

// Function to print the frequency of each word
void print_frequency(WordFrequency *word_freq) {
    for (int i = 0; i < 50; i++) {
        if (word_freq[i].frequency != 0) {
            printf("%s: %d\n", word_freq[i].word, word_freq[i].frequency);
        }
    }
}

int main() {
    // Declare a string to store the text
    char text[1000];

    // Get the text from the user
    printf("Enter the text: ");
    fgets(text, 1000, stdin);

    // Remove the newline character
    text[strlen(text) - 1] = '\0';

    // Declare an array to store the words and their frequency
    WordFrequency word_freq[50];

    // Count the frequency of each word
    count_frequency(text, word_freq);

    // Print the frequency of each word
    print_frequency(word_freq);

    return 0;
}
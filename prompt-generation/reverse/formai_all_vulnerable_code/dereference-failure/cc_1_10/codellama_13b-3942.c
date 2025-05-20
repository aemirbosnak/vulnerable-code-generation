//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: Sherlock Holmes
/*
 * C Word Frequency Counter
 *
 * A Sherlock Holmes-style program to count the frequency of words in a text.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the frequency of each word in the text
void count_frequency(char *text) {
    // Create a hash map to store the frequency of each word
    int *frequencies = malloc(sizeof(int) * 10000);
    memset(frequencies, 0, sizeof(int) * 10000);

    // Split the text into individual words
    char *word = strtok(text, " ");
    while (word != NULL) {
        // Check if the word is already in the hash map
        int index = hash(word) % 10000;
        if (frequencies[index] == 0) {
            // If not, add it to the hash map and set its frequency to 1
            frequencies[index] = 1;
        } else {
            // If it is already in the hash map, increment its frequency
            frequencies[index]++;
        }
        word = strtok(NULL, " ");
    }

    // Print the frequency of each word
    for (int i = 0; i < 10000; i++) {
        if (frequencies[i] > 0) {
            printf("%d: %d\n", i, frequencies[i]);
        }
    }
}

// Hash function to map each word to an index in the hash map
int hash(char *word) {
    int hash = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash += word[i] * i;
    }
    return hash % 10000;
}

int main() {
    // Read the text from the user
    char text[10000];
    printf("Enter the text: ");
    fgets(text, 10000, stdin);

    // Count the frequency of each word in the text
    count_frequency(text);

    return 0;
}
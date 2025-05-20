//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold word and its frequency
typedef struct WordFrequency {
    char *word;
    int frequency;
} WordFrequency;

// Array to store word frequencies
WordFrequency *wordFrequencies;

// Size of the array
int wordFrequencyCount = 0;

// Function to compare two WordFrequency structures
int compareWordFrequency(const void *a, const void *b) {
    WordFrequency *wordFrequency1 = (WordFrequency *)a;
    WordFrequency *wordFrequency2 = (WordFrequency *)b;
    return wordFrequency1->frequency - wordFrequency2->frequency;
}

// Function to add a word to the array
void addWord(char *word) {
    // Check if the word already exists in the array
    for (int i = 0; i < wordFrequencyCount; i++) {
        if (strcmp(wordFrequencies[i].word, word) == 0) {
            wordFrequencies[i].frequency++;
            return;
        }
    }

    // If the word does not exist, add it to the array
    wordFrequencies = realloc(wordFrequencies, (wordFrequencyCount + 1) * sizeof(WordFrequency));
    wordFrequencies[wordFrequencyCount].word = strdup(word);
    wordFrequencies[wordFrequencyCount].frequency = 1;
    wordFrequencyCount++;
}

// Function to print the word frequencies
void printWordFrequencies() {
    // Sort the array by frequency
    qsort(wordFrequencies, wordFrequencyCount, sizeof(WordFrequency), compareWordFrequency);

    // Print the word frequencies
    for (int i = 0; i < wordFrequencyCount; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

// Main function
int main() {
    // Initialize the array
    wordFrequencies = malloc(0);

    // Get the input text
    char input[10000];
    printf("Enter the text: ");
    scanf("%s", input);

    // Tokenize the input text
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Add the word to the array
        addWord(token);

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Print the word frequencies
    printWordFrequencies();

    // Free the memory allocated for the array
    for (int i = 0; i < wordFrequencyCount; i++) {
        free(wordFrequencies[i].word);
    }
    free(wordFrequencies);

    return 0;
}
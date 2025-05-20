//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: peaceful
// Word Frequency Counter Example Program

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store word and its frequency
typedef struct {
    char *word;
    int frequency;
} WordFrequency;

// Function to count word frequency
void countFrequency(WordFrequency *wordFrequencies, char *text) {
    // Split text into words
    char *words[strlen(text) + 1];
    char *token = strtok(text, " ");
    while (token != NULL) {
        words[strlen(words)] = token;
        token = strtok(NULL, " ");
    }

    // Count frequency of each word
    for (int i = 0; i < strlen(words); i++) {
        // Check if word is already in wordFrequencies
        int found = 0;
        for (int j = 0; j < strlen(wordFrequencies); j++) {
            if (strcmp(words[i], wordFrequencies[j].word) == 0) {
                found = 1;
                wordFrequencies[j].frequency++;
                break;
            }
        }

        // If word not found, add it to wordFrequencies
        if (!found) {
            WordFrequency newWord;
            newWord.word = words[i];
            newWord.frequency = 1;
            wordFrequencies[strlen(wordFrequencies)] = newWord;
        }
    }
}

// Function to print word frequencies
void printFrequency(WordFrequency *wordFrequencies) {
    for (int i = 0; i < strlen(wordFrequencies); i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main() {
    // Get input text from user
    char text[1000];
    printf("Enter text: ");
    fgets(text, 1000, stdin);

    // Create wordFrequencies array
    WordFrequency wordFrequencies[100];

    // Count word frequency
    countFrequency(wordFrequencies, text);

    // Print word frequencies
    printFrequency(wordFrequencies);

    return 0;
}
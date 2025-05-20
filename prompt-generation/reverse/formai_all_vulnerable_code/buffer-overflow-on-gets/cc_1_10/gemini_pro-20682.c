//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store a word and its frequency
typedef struct WordFrequency {
    char *word;
    int frequency;
} WordFrequency;

// Function to compare two WordFrequency structs by frequency
int compareWordFrequency(const void *a, const void *b) {
    const WordFrequency *wordFrequencyA = (const WordFrequency *)a;
    const WordFrequency *wordFrequencyB = (const WordFrequency *)b;
    return wordFrequencyB->frequency - wordFrequencyA->frequency;
}

// Function to count the frequency of each word in a string
int countWordFrequency(char *string, WordFrequency **wordFrequencies) {
    // Create a hash table to store the word frequencies
    char lowercaseString[strlen(string) + 1];
    strcpy(lowercaseString, string);
    for (int i = 0; i < strlen(lowercaseString); i++) {
        lowercaseString[i] = tolower(lowercaseString[i]);
    }
    char *tokens[10000];
    char *token = strtok(lowercaseString, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    int numTokens = i;
    int numWords = 0;
    for (int i = 0; i < numTokens; i++) {
        int found = 0;
        for (int j = 0; j < numWords; j++) {
            if (strcmp(tokens[i], wordFrequencies[j]->word) == 0) {
                wordFrequencies[j]->frequency++;
                found = 1;
                break;
            }
        }
        if (!found) {
            wordFrequencies[numWords] = (WordFrequency *)malloc(sizeof(WordFrequency));
            wordFrequencies[numWords]->word = tokens[i];
            wordFrequencies[numWords]->frequency = 1;
            numWords++;
        }
    }

    // Sort the word frequencies in decreasing order
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWordFrequency);

    // Return the number of unique words in the string
    return numWords;
}

// Function to print the word frequencies
void printWordFrequencies(WordFrequency **wordFrequencies, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i]->word, wordFrequencies[i]->frequency);
    }
}

int main() {
    // Get the input string from the user
    char string[1000];
    printf("Enter a string: ");
    gets(string);

    // Create an array of WordFrequency structs to store the word frequencies
    WordFrequency *wordFrequencies[1000];

    // Count the frequency of each word in the string
    int numWords = countWordFrequency(string, wordFrequencies);

    // Print the word frequencies
    printWordFrequencies(wordFrequencies, numWords);

    // Free the memory allocated for the word frequencies
    for (int i = 0; i < numWords; i++) {
        free(wordFrequencies[i]->word);
        free(wordFrequencies[i]);
    }

    return 0;
}
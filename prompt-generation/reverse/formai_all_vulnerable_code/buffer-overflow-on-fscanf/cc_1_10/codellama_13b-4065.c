//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: modular
// WordFrequencyCounter.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to store the word and its frequency
typedef struct {
    char word[20];
    int frequency;
} WordFrequency;

// Function to read a word from the file
void readWord(FILE *file, WordFrequency *word) {
    char buffer[20];
    if (fscanf(file, "%s", buffer) != EOF) {
        strcpy(word->word, buffer);
        word->frequency = 1;
    }
}

// Function to search for a word in the array of words
int searchWord(WordFrequency *words, int size, char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to add a new word to the array of words
void addWord(WordFrequency *words, int *size, char *word) {
    // Check if the word already exists in the array
    int index = searchWord(words, *size, word);
    if (index != -1) {
        words[index].frequency++;
    } else {
        // If the word doesn't exist, add it to the array
        strcpy(words[*size].word, word);
        words[*size].frequency = 1;
        *size = *size + 1;
    }
}

// Function to sort the array of words by frequency
void sortWords(WordFrequency *words, int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (words[i].frequency < words[j].frequency) {
                temp = words[i].frequency;
                words[i].frequency = words[j].frequency;
                words[j].frequency = temp;
            }
        }
    }
}

// Function to print the array of words
void printWords(WordFrequency *words, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s - %d\n", words[i].word, words[i].frequency);
    }
}

// Main function
int main() {
    // Initialize the array of words
    WordFrequency words[100];
    int size = 0;

    // Open the file
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the words from the file
    WordFrequency word;
    while (!feof(file)) {
        readWord(file, &word);
        addWord(words, &size, word.word);
    }

    // Close the file
    fclose(file);

    // Sort the array of words by frequency
    sortWords(words, size);

    // Print the array of words
    printWords(words, size);

    return 0;
}
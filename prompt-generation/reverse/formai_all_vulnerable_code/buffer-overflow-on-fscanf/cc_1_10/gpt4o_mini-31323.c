//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

// Structure to store a word and its associated frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function to compare two WordFrequency structures
int compare(const void *a, const void *b) {
    return strcmp(((WordFrequency *)a)->word, ((WordFrequency *)b)->word);
}

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Function to read input words and count their frequencies
int countWordFrequencies(WordFrequency wordFreq[], FILE *filePtr) {
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;

    while (fscanf(filePtr, "%s", word) != EOF) {
        toLowerCase(word); // Convert to lowercase

        // Check if the word already exists in the array
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(wordFreq[i].word, word) == 0) {
                wordFreq[i].frequency++;
                found = 1;
                break;
            }
        }

        // If the word was not found, add a new entry
        if (!found) {
            strcpy(wordFreq[wordCount].word, word);
            wordFreq[wordCount].frequency = 1;
            wordCount++;
            if (wordCount >= MAX_WORDS) {
                printf("Maximum word count reached, cannot add more words.\n");
                break;
            }
        }
    }
    return wordCount;
}

// Function to display the word frequencies
void displayFrequencies(WordFrequency wordFreq[], int wordCount) {
    printf("\nWord Frequency Count:\n");
    printf("----------------------\n");

    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordFreq[i].word, wordFreq[i].frequency);
    }
}

// Function to sort and display the word frequencies in descending order
void sortAndDisplayDescending(WordFrequency wordFreq[], int wordCount) {
    qsort(wordFreq, wordCount, sizeof(WordFrequency), compare);

    printf("\nSorted Word Frequency Count (Ascending Order):\n");
    printf("------------------------------------------\n");
    
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordFreq[i].word, wordFreq[i].frequency);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if input file is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *filePtr = fopen(argv[1], "r");
    if (filePtr == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordFrequency wordFreq[MAX_WORDS];
    int wordCount = countWordFrequencies(wordFreq, filePtr);

    fclose(filePtr); // Close the file after reading

    sortAndDisplayDescending(wordFreq, wordCount); // Sort and display frequencies
    displayFrequencies(wordFreq, wordCount); // Display word frequencies

    return EXIT_SUCCESS;
}
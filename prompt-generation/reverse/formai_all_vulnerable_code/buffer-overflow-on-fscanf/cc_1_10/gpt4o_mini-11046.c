//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Structure to hold the word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFreq;

// Function to count word frequencies in a text file
void countWordFrequencies(const char *filename) {
    FILE *file;
    char buffer[MAX_WORD_LENGTH];
    WordFreq wordList[MAX_WORDS];
    int wordCount = 0;
    int found;
    
    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read words from the file
    while (fscanf(file, "%s", buffer) != EOF) {
        // Convert to lowercase
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower((unsigned char) buffer[i]);
        }
        
        // Check if the word is already in the list
        found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(wordList[i].word, buffer) == 0) {
                wordList[i].count++;
                found = 1;
                break;
            }
        }
        
        // If not found, add the new word to the list
        if (!found && wordCount < MAX_WORDS) {
            strcpy(wordList[wordCount].word, buffer);
            wordList[wordCount].count = 1;
            wordCount++;
        } else if (!found) {
            fprintf(stderr, "Word limit exceeded! Increase MAX_WORDS.\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    // Close the file
    fclose(file);

    // Print the word frequencies
    printf("Word Frequency Report:\n");
    printf("-----------------------\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }

    printf("-----------------------\n");
    printf("Total unique words: %d\n", wordCount);
}

int main(int argc, char *argv[]) {
    // Check for valid arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Start the word frequency count
    countWordFrequencies(argv[1]);

    // Work done, paranoia has served us well
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

// Structure to hold word and frequency information
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function prototypes
void readFile(FILE *file, WordFrequency words[]);
void countWords(WordFrequency words[], int numWords);
void printWords(WordFrequency words[], int numWords);

int main() {
    FILE *inputFile;
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read words from file
    readFile(inputFile, words);
    fclose(inputFile);

    // Count word frequencies
    countWords(words, numWords);

    // Print word frequencies
    printf("Word frequencies:\n");
    printWords(words, numWords);

    return 0;
}

// Read words from file into array
void readFile(FILE *file, WordFrequency words[]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    // Read first word
    fscanf(file, "%s", word);

    // Loop through remaining words
    while (fscanf(file, "%s", word)!= EOF) {
        // Convert word to lowercase
        for (int j = 0; j < strlen(word); j++) {
            word[j] = tolower(word[j]);
        }

        // Add word to array
        strcpy(words[i].word, word);
        words[i].frequency = 1;
        i++;
    }
}

// Count word frequencies
void countWords(WordFrequency words[], int numWords) {
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].frequency += words[j].frequency;
                words[j].frequency = 0;
            }
        }
    }
}

// Print word frequencies
void printWords(WordFrequency words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}
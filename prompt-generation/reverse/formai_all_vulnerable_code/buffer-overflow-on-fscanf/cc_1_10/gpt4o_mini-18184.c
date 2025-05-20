//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Structure to hold a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

// Function prototypes
void processText(FILE *file, WordFrequency *wordFreq, int *wordCount);
void toLowerCase(char *str);
void printWordFrequencies(WordFrequency *wordFreq, int wordCount);
int compare(const void *a, const void *b);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return 1;
    }

    WordFrequency wordFreq[MAX_WORDS] = {0};
    int wordCount = 0;

    processText(file, wordFreq, &wordCount);
    fclose(file);

    // Sort the words based on frequency
    qsort(wordFreq, wordCount, sizeof(WordFrequency), compare);

    // Print the sorted word frequencies
    printWordFrequencies(wordFreq, wordCount);

    return 0;
}

// Process the text file and count word frequencies
void processText(FILE *file, WordFrequency *wordFreq, int *wordCount) {
    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer) != EOF) {
        toLowerCase(buffer);
        
        // Ignore special characters
        if (!isalpha(buffer[0])) {
            continue;
        }

        // Check if the word is already counted
        int found = 0;
        for (int i = 0; i < *wordCount; i++) {
            if (strcmp(wordFreq[i].word, buffer) == 0) {
                wordFreq[i].count++;
                found = 1;
                break;
            }
        }

        // If the word was not found, add it to the list
        if (!found && *wordCount < MAX_WORDS) {
            strcpy(wordFreq[*wordCount].word, buffer);
            wordFreq[*wordCount].count = 1;
            (*wordCount)++;
        }
    }
}

// Convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Print the word frequencies
void printWordFrequencies(WordFrequency *wordFreq, int wordCount) {
    printf("Word Frequency Count:\n");
    printf("=====================\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordFreq[i].word, wordFreq[i].count);
    }
}

// Compare function for qsort
int compare(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;
    return wordB->count - wordA->count; // Sort in descending order
}
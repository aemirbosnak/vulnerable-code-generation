//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

// Structure to hold words and their frequencies
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFreq;

// Function prototypes
void toLowerCase(char *str);
int addWord(WordFreq words[], int *wordCount, const char *newWord);
void sortWords(WordFreq words[], int wordCount);
void printWordFrequencies(WordFreq words[], int wordCount);

int main() {
    FILE *file;
    char filename[100];
    char word[MAX_WORD_LENGTH];
    WordFreq words[MAX_WORDS];
    int wordCount = 0;

    printf("Enter the filename to analyze (including the extension): ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    // Read words from the file
    while (fscanf(file, "%s", word) != EOF) {
        toLowerCase(word);
        if (addWord(words, &wordCount, word) == -1) {
            printf("Error: exceeded maximum word limit.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    // Sort words by frequency
    sortWords(words, wordCount);

    // Print word frequencies
    printWordFrequencies(words, wordCount);

    return 0;
}

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

// Function to add a word to the frequency array
int addWord(WordFreq words[], int *wordCount, const char *newWord) {
    for (int i = 0; i < *wordCount; i++) {
        if (strcmp(words[i].word, newWord) == 0) {
            words[i].count++;
            return 0; // Word already exists
        }
    }

    // Check if maximum word limit has been reached
    if (*wordCount < MAX_WORDS) {
        strcpy(words[*wordCount].word, newWord);
        words[*wordCount].count = 1;
        (*wordCount)++;
        return 0; // New word added
    }

    return -1; // Error: Maximum words reached
}

// Function to sort words by frequency using Bubble Sort
void sortWords(WordFreq words[], int wordCount) {
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            if (words[j].count < words[j + 1].count) {
                // Swap the two elements
                WordFreq temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

// Function to print the word frequencies
void printWordFrequencies(WordFreq words[], int wordCount) {
    printf("\nWord Frequencies:\n");
    printf("------------------\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}
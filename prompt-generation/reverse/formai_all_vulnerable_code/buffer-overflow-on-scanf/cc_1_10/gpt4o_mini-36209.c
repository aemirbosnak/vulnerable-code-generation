//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Struct to hold the word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function prototypes
void toLowercase(char *word);
int findWordIndex(WordFrequency *words, int count, const char *word);
void addOrUpdateWord(WordFrequency *words, int *count, const char *word);
void printWordFrequencies(WordFrequency *words, int count);
void sortWordFrequencies(WordFrequency *words, int count);
void freeMemory(WordFrequency *words);

int main() {
    // Declare an array to hold the word frequencies
    WordFrequency *words = malloc(MAX_WORDS * sizeof(WordFrequency));
    if (words == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    int wordCount = 0;
    char input[MAX_WORD_LENGTH];

    printf("Enter text (end with 'EOF' or Ctrl+D):\n");

    // Read words from standard input
    while (scanf("%s", input) != EOF) {
        toLowercase(input);
        addOrUpdateWord(words, &wordCount, input);
    }

    // Sort words by frequency
    sortWordFrequencies(words, wordCount);

    // Print the sorted frequencies
    printWordFrequencies(words, wordCount);

    // Free allocated memory
    freeMemory(words);

    return 0;
}

// Function to convert a string to lowercase
void toLowercase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

// Function to find the index of a word in the array, -1 if not found
int findWordIndex(WordFrequency *words, int count, const char *word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to add or update the count of a word in the frequency array
void addOrUpdateWord(WordFrequency *words, int *count, const char *word) {
    int index = findWordIndex(words, *count, word);
    if (index == -1) { // New word
        strncpy(words[*count].word, word, MAX_WORD_LENGTH);
        words[*count].frequency = 1;
        (*count)++;
    } else { // Existing word
        words[index].frequency++;
    }
}

// Function to print word frequencies
void printWordFrequencies(WordFrequency *words, int count) {
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

// Function to sort words by frequency in descending order
void sortWordFrequencies(WordFrequency *words, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (words[j].frequency < words[j + 1].frequency) {
                WordFrequency temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

// Function to free allocated memory for words
void freeMemory(WordFrequency *words) {
    free(words);
}
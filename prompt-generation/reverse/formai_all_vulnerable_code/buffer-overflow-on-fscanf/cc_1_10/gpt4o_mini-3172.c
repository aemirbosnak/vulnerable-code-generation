//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Structure to hold a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function prototypes
void toLowerCase(char *str);
int wordExists(WordFrequency *wordList, int count, const char *word);
void addOrIncrement(WordFrequency *wordList, int *count, const char *word);
void displayWordFrequencies(WordFrequency *wordList, int count);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordFrequency wordList[MAX_WORDS];
    int wordCount = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", word) != EOF) {
        toLowerCase(word);
        addOrIncrement(wordList, &wordCount, word);
    }

    fclose(file);
    displayWordFrequencies(wordList, wordCount);
    return EXIT_SUCCESS;
}

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Function to check if a word already exists in the list
int wordExists(WordFrequency *wordList, int count, const char *word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(wordList[i].word, word) == 0) {
            return 1; // Word exists
        }
    }
    return 0; // Word does not exist
}

// Function to add a new word or increment its frequency
void addOrIncrement(WordFrequency *wordList, int *count, const char *word) {
    if (wordExists(wordList, *count, word)) {
        for (int i = 0; i < *count; i++) {
            if (strcmp(wordList[i].word, word) == 0) {
                wordList[i].frequency++;
                break;
            }
        }
    } else {
        // Add new word to the list
        strcpy(wordList[*count].word, word);
        wordList[*count].frequency = 1;
        (*count)++;
    }
}

// Function to display the word frequencies
void displayWordFrequencies(WordFrequency *wordList, int count) {
    printf("\nWord Frequencies:\n");
    printf("------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].frequency);
    }
}
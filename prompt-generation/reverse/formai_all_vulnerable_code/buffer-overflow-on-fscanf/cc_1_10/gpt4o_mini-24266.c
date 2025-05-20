//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_UNIQUE_WORDS 1000

// A structure to hold each unique word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

// Function prototypes
void toLowerCase(char *str);
int isWordCharacter(char c);
void processFile(const char *filename, WordFrequency *wordFrequencies, int *uniqueWordCount);
void printFrequencies(const WordFrequency *wordFrequencies, int uniqueWordCount);
void sortFrequencies(WordFrequency *wordFrequencies, int uniqueWordCount);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    WordFrequency wordFrequencies[MAX_UNIQUE_WORDS] = {0};
    int uniqueWordCount = 0;

    processFile(argv[1], wordFrequencies, &uniqueWordCount);
    sortFrequencies(wordFrequencies, uniqueWordCount);
    printFrequencies(wordFrequencies, uniqueWordCount);

    return EXIT_SUCCESS;
}

// Converts a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Checks if a character is part of a word
int isWordCharacter(char c) {
    return isalnum(c) || c == '\'';
}

// Processes the given file to count word frequencies
void processFile(const char *filename, WordFrequency *wordFrequencies, int *uniqueWordCount) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        // Convert the word to lowercase to ensure case-insensitivity
        toLowerCase(word);

        // If the word contains invalid characters let's continue
        for (int i = 0; word[i]; i++) {
            if (!isWordCharacter(word[i])) {
                break;
            }
        }

        // Check if the word is already in the list
        int found = 0;
        for (int i = 0; i < *uniqueWordCount; i++) {
            if (strcmp(wordFrequencies[i].word, word) == 0) {
                wordFrequencies[i].count++;
                found = 1;
                break;
            }
        }

        // If the word was not found, add it to the list
        if (!found && *uniqueWordCount < MAX_UNIQUE_WORDS) {
            strcpy(wordFrequencies[*uniqueWordCount].word, word);
            wordFrequencies[*uniqueWordCount].count = 1;
            (*uniqueWordCount)++;
        }
    }

    fclose(file);
}

// Prints the word frequencies in a sorted manner
void printFrequencies(const WordFrequency *wordFrequencies, int uniqueWordCount) {
    printf("Word Frequencies:\n");
    printf("--------------------\n");
    for (int i = 0; i < uniqueWordCount; i++) {
        printf("%-20s : %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

// Sorts the frequency array in descending order based on frequency
void sortFrequencies(WordFrequency *wordFrequencies, int uniqueWordCount) {
    for (int i = 0; i < uniqueWordCount - 1; i++) {
        for (int j = i + 1; j < uniqueWordCount; j++) {
            if (wordFrequencies[i].count < wordFrequencies[j].count) {
                WordFrequency temp = wordFrequencies[i];
                wordFrequencies[i] = wordFrequencies[j];
                wordFrequencies[j] = temp;
            }
        }
    }
}
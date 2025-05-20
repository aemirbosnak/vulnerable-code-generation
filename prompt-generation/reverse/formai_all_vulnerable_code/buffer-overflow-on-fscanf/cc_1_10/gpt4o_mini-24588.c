//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Structure to hold words and their frequencies
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordCount;

// Function prototypes
void toLowerCase(char *str);
int isWordCharacter(char c);
void countWordsInFile(const char *filename, WordCount *wordCounts, int *wordCountSize);
void printWordFrequencies(WordCount *wordCounts, int wordCountSize);
void sortWordCounts(WordCount *wordCounts, int wordCountSize);

int main() {
    WordCount wordCounts[MAX_WORDS];
    int wordCountSize = 0;

    const char *filename = "input.txt"; // Input file with words to count
    countWordsInFile(filename, wordCounts, &wordCountSize);
    sortWordCounts(wordCounts, wordCountSize);
    printWordFrequencies(wordCounts, wordCountSize);

    return 0;
}

void countWordsInFile(const char *filename, WordCount *wordCounts, int *wordCountSize) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer) == 1) {
        toLowerCase(buffer); // Convert to lower case for consistency
        int found = 0;

        // Check if the word is already counted
        for (int i = 0; i < *wordCountSize; i++) {
            if (strcmp(wordCounts[i].word, buffer) == 0) {
                wordCounts[i].frequency++;
                found = 1;
                break;
            }
        }

        // If not found, add to the array
        if (!found && *wordCountSize < MAX_WORDS) {
            strcpy(wordCounts[*wordCountSize].word, buffer);
            wordCounts[*wordCountSize].frequency = 1;
            (*wordCountSize)++;
        }
    }

    fclose(file);
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void printWordFrequencies(WordCount *wordCounts, int wordCountSize) {
    printf("%-20s %s\n", "Word", "Frequency");
    printf("------------------------------\n");
    for (int i = 0; i < wordCountSize; i++) {
        printf("%-20s %d\n", wordCounts[i].word, wordCounts[i].frequency);
    }
}

void sortWordCounts(WordCount *wordCounts, int wordCountSize) {
    for (int i = 0; i < wordCountSize - 1; i++) {
        for (int j = 0; j < wordCountSize - i - 1; j++) {
            if (wordCounts[j].frequency < wordCounts[j + 1].frequency) {
                // Swap
                WordCount temp = wordCounts[j];
                wordCounts[j] = wordCounts[j + 1];
                wordCounts[j + 1] = temp;
            }
        }
    }
}
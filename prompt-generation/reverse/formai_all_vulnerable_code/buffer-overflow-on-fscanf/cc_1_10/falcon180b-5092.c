//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

// Structure to store word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function to compare two words (case insensitive)
int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcasecmp(wordA->word, wordB->word);
}

// Function to read words from a file and store them in an array
int readWordsFromFile(FILE *file, WordFrequency *words) {
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (wordCount >= MAX_WORDS) {
            printf("Error: Too many words in the file.\n");
            return -1;
        }

        strcpy(words[wordCount].word, word);
        words[wordCount].frequency = 0;
        wordCount++;
    }

    return 0;
}

// Function to count the frequency of each word in the array
void countWordFrequencies(WordFrequency *words, int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        WordFrequency *word = &words[i];

        for (int j = 0; j < wordCount; j++) {
            if (strcmp(word->word, words[j].word) == 0) {
                word->frequency++;
            }
        }
    }
}

// Function to print the word frequencies in descending order
void printWordFrequencies(WordFrequency *words, int wordCount) {
    qsort(words, wordCount, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < wordCount; i++) {
        WordFrequency *word = &words[i];

        printf("%s: %d\n", word->word, word->frequency);
    }
}

int main() {
    FILE *file;
    WordFrequency words[MAX_WORDS];
    int wordCount = 0;

    // Open the input file
    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        return -1;
    }

    // Read words from the file
    if (readWordsFromFile(file, words)!= 0) {
        fclose(file);
        return -1;
    }

    // Count the frequency of each word
    countWordFrequencies(words, wordCount);

    // Print the word frequencies in descending order
    printWordFrequencies(words, wordCount);

    // Close the input file
    fclose(file);

    return 0;
}
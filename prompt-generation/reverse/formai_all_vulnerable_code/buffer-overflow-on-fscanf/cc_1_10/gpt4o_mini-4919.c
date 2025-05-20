//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

// Function to compare two words for sorting
int compareWords(const void *a, const void *b) {
    return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

// Function to find the index of a word in the array of words
int findWordIndex(Word wordList[], int wordCount, const char *word) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(wordList[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to read data from a file and count word frequencies
void countWordFrequencies(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    Word wordList[MAX_WORDS] = {0};
    int wordCount = 0;
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", buffer) != EOF) {
        // To handle case insensitivity, convert word to lowercase
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
        }

        int index = findWordIndex(wordList, wordCount, buffer);
        if (index != -1) {
            // If the word already exists, increment its count
            wordList[index].count++;
        } else {
            // Add new word to the list
            strcpy(wordList[wordCount].word, buffer);
            wordList[wordCount].count = 1;
            wordCount++;

            // Avoid exceeding maximum words
            if (wordCount >= MAX_WORDS) {
                fprintf(stderr, "Exceeded maximum word limit of %d.\n", MAX_WORDS);
                break;
            }
        }
    }
    fclose(file);

    // Sort words alphabetically
    qsort(wordList, wordCount, sizeof(Word), compareWords);

    // Display the word frequencies
    printf("Word Frequency Count:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    countWordFrequencies(argv[1]);

    return EXIT_SUCCESS;
}
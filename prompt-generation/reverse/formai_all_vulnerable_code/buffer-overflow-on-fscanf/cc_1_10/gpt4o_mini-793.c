//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function prototypes
void countWordsInFile(const char *filename);
void processWord(char *word, WordCount *wordList, int *wordCount);
void printWordCounts(WordCount *wordList, int wordCount);
int compareWords(const void *a, const void *b);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    countWordsInFile(argv[1]);
    return EXIT_SUCCESS;
}

// Function to count words in a file
void countWordsInFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    WordCount wordList[MAX_WORDS];
    int wordCount = 0;

    while (fscanf(file, "%s", word) != EOF) {
        processWord(word, wordList, &wordCount);
    }

    fclose(file);
    printWordCounts(wordList, wordCount);
}

// Function to process each word and update the word count
void processWord(char *word, WordCount *wordList, int *wordCount) {
    // Convert to lowercase for uniformity
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }

    // Check if the word is already in the list
    for (int i = 0; i < *wordCount; i++) {
        if (strcmp(wordList[i].word, word) == 0) {
            wordList[i].count++;
            return;
        }
    }

    // If the word is new, add it to the list
    if (*wordCount < MAX_WORDS) {
        strcpy(wordList[*wordCount].word, word);
        wordList[*wordCount].count = 1;
        (*wordCount)++;
    } else {
        fprintf(stderr, "Exceeded maximum word count of %d\n", MAX_WORDS);
    }
}

// Function to print word counts sorted by word
void printWordCounts(WordCount *wordList, int wordCount) {
    // Sort the word list in alphabetical order
    qsort(wordList, wordCount, sizeof(WordCount), compareWords);

    printf("\nWord Count Summary:\n");
    printf("--------------------\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }
}

// Comparator function for qsort
int compareWords(const void *a, const void *b) {
    return strcmp(((WordCount *)a)->word, ((WordCount *)b)->word);
}
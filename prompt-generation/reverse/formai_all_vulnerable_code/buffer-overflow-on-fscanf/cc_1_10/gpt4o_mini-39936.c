//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Structure to hold the word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordCount;

// Function declarations
void toLowerCase(char *str);
int addWord(WordCount *wordArray, int *wordCount, const char *word);
void sortWords(WordCount *wordArray, int wordCount);
void printWordCounts(WordCount *wordArray, int wordCount);
void countWordsFromFile(const char *filename);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    countWordsFromFile(argv[1]);
    return EXIT_SUCCESS;
}

// Count words from the given file
void countWordsFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    WordCount wordArray[MAX_WORDS] = {0};
    int wordCount = 0;
    char word[MAX_WORD_LENGTH];
    
    while (fscanf(file, "%s", word) == 1) {
        toLowerCase(word);
        if (addWord(wordArray, &wordCount, word) == -1) {
            fprintf(stderr, "Word list exceeded maximum size.\n");
            break;
        }
    }

    fclose(file);
    sortWords(wordArray, wordCount);
    printWordCounts(wordArray, wordCount);
}

// Convert a string to lower case
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Add a word to the word count array, return index or -1 on failure
int addWord(WordCount *wordArray, int *wordCount, const char *word) {
    for (int i = 0; i < *wordCount; i++) {
        if (strcmp(wordArray[i].word, word) == 0) {
            wordArray[i].frequency++;
            return 0; // Word found, frequency incremented
        }
    }

    // If new word, check array bounds
    if (*wordCount >= MAX_WORDS) {
        return -1; // Array is full
    }

    // Add new word to array
    strcpy(wordArray[*wordCount].word, word);
    wordArray[*wordCount].frequency = 1;
    (*wordCount)++;
    return 0; // Success
}

// Sort words in descending order based on frequency
void sortWords(WordCount *wordArray, int wordCount) {
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (wordArray[i].frequency < wordArray[j].frequency) {
                WordCount temp = wordArray[i];
                wordArray[i] = wordArray[j];
                wordArray[j] = temp;
            }
        }
    }
}

// Print the word counts
void printWordCounts(WordCount *wordArray, int wordCount) {
    printf("Word Frequency Count:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordArray[i].word, wordArray[i].frequency);
    }
}
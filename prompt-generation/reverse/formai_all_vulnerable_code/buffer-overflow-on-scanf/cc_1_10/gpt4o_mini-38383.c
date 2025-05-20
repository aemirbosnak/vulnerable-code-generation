//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum number of words and word length
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Structure to hold a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function prototypes
void cleanWord(char *word);
int compare(const void *a, const void *b);
void countWords(FILE *file, WordCount *words, int *wordCount);
void printWordCounts(WordCount *words, int wordCount);

int main() {
    char fileName[100];
    FILE *file;
    WordCount words[MAX_WORDS];
    int wordCount = 0;

    // Get the file name from the user
    printf("Enter the name of the text file to process: ");
    scanf("%s", fileName);

    // Open the file
    file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", fileName);
        return EXIT_FAILURE;
    }

    // Count the words in the file
    countWords(file, words, &wordCount);

    // Close the file
    fclose(file);

    // Sort the words by frequency
    qsort(words, wordCount, sizeof(WordCount), compare);
    
    // Print the words and their frequencies
    printWordCounts(words, wordCount);

    return EXIT_SUCCESS;
}

// Function to clean up the word: remove punctuation and convert to lower case
void cleanWord(char *word) {
    char cleanedWord[MAX_WORD_LENGTH];
    int j = 0;

    for (int i = 0; word[i]; i++) {
        if (isalnum(word[i])) {
            cleanedWord[j++] = tolower(word[i]);
        }
    }
    cleanedWord[j] = '\0';
    strcpy(word, cleanedWord);
}

// Function to compare two WordCount structures for sorting
int compare(const void *a, const void *b) {
    WordCount *word1 = (WordCount *)a;
    WordCount *word2 = (WordCount *)b;

    if (word1->count == word2->count) {
        return strcmp(word1->word, word2->word);
    }
    
    return word2->count - word1->count;
}

// Function to count words in the given file
void countWords(FILE *file, WordCount *words, int *wordCount) {
    char word[MAX_WORD_LENGTH];
    int found;

    while (fscanf(file, "%49s", word) == 1) {
        cleanWord(word);
        found = 0;

        for (int i = 0; i < *wordCount; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        if (!found && *wordCount < MAX_WORDS) {
            strcpy(words[*wordCount].word, word);
            words[*wordCount].count = 1;
            (*wordCount)++;
        }
    }
}

// Function to print the word counts
void printWordCounts(WordCount *words, int wordCount) {
    printf("\nWord Count Summary:\n");
    printf("--------------------\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}
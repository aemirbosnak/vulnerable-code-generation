//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the count of each word
typedef struct {
    char *word;
    int count;
} WordCount;

// Function to compare two WordCount structures
int compareWordCount(const void *a, const void *b) {
    const WordCount *w1 = (const WordCount *)a;
    const WordCount *w2 = (const WordCount *)b;

    // Sort in descending order of count
    return w2->count - w1->count;
}

// Function to count the occurrences of each word in a string
WordCount *countWords(const char *str, int *numWords) {
    // Allocate memory for the array of WordCount structures
    *numWords = 0;
    WordCount *wordCounts = malloc(sizeof(WordCount) * 100);

    // Tokenize the string into words
    char *token = strtok(str, " ");
    while (token != NULL) {
        // Check if the word is already in the array
        int found = 0;
        for (int i = 0; i < *numWords; i++) {
            if (strcmp(token, wordCounts[i].word) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not in the array, add it
        if (!found) {
            wordCounts[*numWords].word = malloc(strlen(token) + 1);
            strcpy(wordCounts[*numWords].word, token);
            wordCounts[*numWords].count = 1;
            (*numWords)++;
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Return the array of WordCount structures
    return wordCounts;
}

// Function to print the word counts
void printWordCounts(WordCount *wordCounts, int numWords) {
    // Sort the array of WordCount structures in descending order of count
    qsort(wordCounts, numWords, sizeof(WordCount), compareWordCount);

    // Print the word counts
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    // Get the input string from the user
    char str[1000];
    printf("Enter a string: ");
    gets(str);

    // Count the occurrences of each word in the string
    int numWords = 0;
    WordCount *wordCounts = countWords(str, &numWords);

    // Print the word counts
    printWordCounts(wordCounts, numWords);

    // Free the memory allocated for the array of WordCount structures
    for (int i = 0; i < numWords; i++) {
        free(wordCounts[i].word);
    }
    free(wordCounts);

    return 0;
}
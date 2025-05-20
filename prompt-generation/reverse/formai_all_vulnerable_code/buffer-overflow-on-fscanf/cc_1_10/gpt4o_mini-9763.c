//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
};

// Function to sort the words in alphabetical order
int compareWords(const void *a, const void *b) {
    struct WordCount *word1 = (struct WordCount *)a;
    struct WordCount *word2 = (struct WordCount *)b;
    return strcmp(word1->word, word2->word);
}

// Function to process the text and count word frequencies
void countWords(FILE *file, struct WordCount *wordCounts, int *totalWords) {
    char buffer[MAX_WORD_LENGTH];
    int wordFound;

    while (fscanf(file, "%s", buffer) != EOF) {
        wordFound = 0;

        // Convert to lowercase for case insensitive comparison
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
        }

        // Check if the word is already in the wordCounts array
        for (int i = 0; i < *totalWords; i++) {
            if (strcmp(wordCounts[i].word, buffer) == 0) {
                wordCounts[i].count++;
                wordFound = 1;
                break;
            }
        }

        // If the word is new, add to the array
        if (!wordFound) {
            strcpy(wordCounts[*totalWords].word, buffer);
            wordCounts[*totalWords].count = 1;
            (*totalWords)++;
        }
    }
}

int main() {
    struct WordCount wordCounts[MAX_WORDS];
    int totalWords = 0;

    FILE *file = fopen("input.txt", "r");
    
    if (!file) {
        printf("Error: Could not open file.\n");
        return 1; // Return error code
    }

    countWords(file, wordCounts, &totalWords);
    fclose(file);

    // Sort the words array
    qsort(wordCounts, totalWords, sizeof(struct WordCount), compareWords);

    // Print the sorted word frequencies
    printf("Word Frequency Count:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0; // Return success code
}
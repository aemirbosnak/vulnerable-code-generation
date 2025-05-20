//Falcon-180B DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordCountA = (WordCount *) a;
    WordCount *wordCountB = (WordCount *) b;
    return strcmp(wordCountA->word, wordCountB->word);
}

int main() {
    FILE *file;
    char input[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;

    // Open the input file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Read in words and count their frequency
    while (fscanf(file, "%s", input)!= EOF) {
        // Convert input to lowercase
        for (int i = 0; i < strlen(input); i++) {
            input[i] = tolower(input[i]);
        }

        // Check if word is already in the array
        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(wordCounts[i].word, input) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }

        // Add new word to the array if it is not already there
        if (!found) {
            strcpy(wordCounts[numWords].word, input);
            wordCounts[numWords].count = 1;
            numWords++;
        }
    }

    // Sort the array of words by frequency in descending order
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    // Print the results
    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
    }

    // Close the input file
    fclose(file);

    return 0;
}
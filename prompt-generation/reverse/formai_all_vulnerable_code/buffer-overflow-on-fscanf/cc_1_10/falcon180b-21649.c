//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = a;
    const WordFrequency *wordB = b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    // Open the input file
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Count the frequency of each word in the input file
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(inputFile, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // Remove newline character
        tolower(word); // Convert to lowercase
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Too many unique words.\n");
                fclose(inputFile);
                return 1;
            }
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }
    }
    fclose(inputFile);

    // Sort the words by frequency
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    // Print the word frequency table
    printf("Word Frequency Table:\n");
    printf("----------------------\n");
    for (int i = 0; i < numWords; i++) {
        printf("%-20s %d\n", words[i].word, words[i].count);
    }

    return 0;
}
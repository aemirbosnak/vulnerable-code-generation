//Falcon-180B DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = a;
    const WordFrequency *wordB = b;
    
    if (wordA->frequency > wordB->frequency) {
        return -1;
    } else if (wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *inputFile;
    char inputBuffer[MAX_WORD_LENGTH];
    char *word;
    int numWords = 0;
    WordFrequency wordFrequencies[MAX_NUM_WORDS];
    
    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }
    
    // Read words from input file and store in array
    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        word = strtok(inputBuffer, ",.!?;:");
        while (word!= NULL) {
            numWords++;
            if (numWords >= MAX_NUM_WORDS) {
                printf("Error: too many words in input file.\n");
                exit(1);
            }
            strcpy(wordFrequencies[numWords].word, word);
            wordFrequencies[numWords].frequency = 1;
            word = strtok(NULL, ",.!?;:");
        }
    }
    
    // Sort words by frequency
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
    
    // Print word frequency table
    printf("Word Frequency Table:\n");
    printf("------------------------\n");
    for (int i = 0; i < numWords; i++) {
        printf("%-20s %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
    
    return 0;
}
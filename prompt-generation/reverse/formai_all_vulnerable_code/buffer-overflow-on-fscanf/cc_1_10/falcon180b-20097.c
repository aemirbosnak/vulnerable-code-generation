//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 1000
#define MAX_WORDS 100
#define NUM_SENTIMENTS 6

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    char *sentiment;
    int positive;
    int negative;
    int neutral;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"happy", 1, 0, 0},
    {"sad", 0, 1, 0},
    {"angry", 0, 1, 0},
    {"excited", 1, 0, 0},
    {"bored", 0, 0, 1},
    {"confused", 0, 0, 1}
};

void addWord(char *sentence, int *wordCounts) {
    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < NUM_SENTIMENTS; i++) {
            if (strcmp(word, sentiments[i].sentiment) == 0) {
                wordCounts[i]++;
                break;
            }
        }
        if (i == NUM_SENTIMENTS) {
            wordCounts[NUM_SENTIMENTS - 1]++; // neutral
        }
        word = strtok(NULL, " ");
    }
}

int main() {
    FILE *inputFile;
    char inputBuffer[MAX_SENTENCES][MAX_WORDS];
    int numSentences = 0;
    int i, j;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s", inputBuffer[numSentences])!= EOF) {
        numSentences++;
        if (numSentences >= MAX_SENTENCES) {
            printf("Error: too many sentences.\n");
            return 1;
        }
    }

    int wordCounts[NUM_SENTIMENTS] = {0};

    for (i = 0; i < numSentences; i++) {
        addWord(inputBuffer[i], wordCounts);
    }

    printf("Sentiment analysis:\n");
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        printf("%s: %d\n", sentiments[i].sentiment, wordCounts[i]);
    }

    fclose(inputFile);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Text processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *inputFile;
    char inputString[MAX_WORD_LENGTH];
    char *token;
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;
    int i;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fscanf(inputFile, "%s", inputString)!= EOF) {
        token = strtok(inputString, ",.!?;:\"'()[]{}<>");
        while (token!= NULL) {
            for (i = 0; i < numWords; i++) {
                if (strcmp(token, wordFrequencies[i].word) == 0) {
                    wordFrequencies[i].frequency++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords >= MAX_WORDS) {
                    printf("Maximum number of words exceeded.\n");
                    exit(1);
                }
                strcpy(wordFrequencies[numWords].word, token);
                wordFrequencies[numWords].frequency = 1;
                numWords++;
            }
            token = strtok(NULL, ",.!?;:\"'()[]{}<>");
        }
    }

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    printf("Word frequencies:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    fclose(inputFile);
    return 0;
}
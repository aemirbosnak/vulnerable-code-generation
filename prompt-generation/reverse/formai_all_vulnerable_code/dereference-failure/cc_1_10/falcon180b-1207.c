//Falcon-180B DATASET v1.0 Category: Educational ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_WORD_LENGTH];
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char *word = strtok(line, " \t\n\r\f\v");
        while (word!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, wordCounts[i].word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords >= MAX_WORDS) {
                    printf("Error: too many unique words\n");
                    exit(1);
                }
                strcpy(wordCounts[numWords].word, word);
                wordCounts[numWords].count = 1;
                numWords++;
            }
            word = strtok(NULL, " \t\n\r\f\v");
        }
    }

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    fprintf(outputFile, "Word count:\n");
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
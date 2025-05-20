//Falcon-180B DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *) a;
    WordCount *wordB = (WordCount *) b;

    return strcmp(wordA->word, wordB->word);
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

void processLine(char *line, WordCount *wordCounts, int numWords) {
    char *word = strtok(line, " ");

    while (word!= NULL) {
        int index = 0;

        while (index < numWords && strcmp(wordCounts[index].word, word)!= 0) {
            index++;
        }

        if (index == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Too many unique words.\n");
                exit(1);
            }

            strcpy(wordCounts[numWords].word, word);
            numWords++;
        }

        wordCounts[index].count++;
        word = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: No input file specified.\n");
        exit(1);
    }

    FILE *inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        processLine(line, wordCounts, numWords);
    }

    printWordCounts(wordCounts, numWords);

    fclose(inputFile);

    return 0;
}
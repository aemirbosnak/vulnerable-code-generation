//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = (const WordFrequency *)a;
    const WordFrequency *wordB = (const WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void printWordFrequencyTable(WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

int main() {
    FILE *inputFile;
    char filename[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    WordFrequency wordFrequencies[MAX_NUM_WORDS];
    int numWords = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    inputFile = fopen(filename, "r");

    if (inputFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char *token = strtok(line, ",.?!;:\"'");

        while (token!= NULL) {
            int wordLength = strlen(token);

            if (wordLength > 0 && wordLength <= MAX_WORD_LENGTH) {
                strcpy(wordFrequencies[numWords].word, token);
                wordFrequencies[numWords].count = 1;
                numWords++;
            }

            if (numWords >= MAX_NUM_WORDS) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }

            token = strtok(NULL, ",.?!;:\"'");
        }
    }

    fclose(inputFile);

    printWordFrequencyTable(wordFrequencies, numWords);

    return 0;
}
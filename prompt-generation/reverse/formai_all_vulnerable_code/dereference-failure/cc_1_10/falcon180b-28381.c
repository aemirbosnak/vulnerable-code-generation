//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 100

typedef struct {
    char *word;
    int count;
} WordFrequency;

void initializeWordFrequencyTable(WordFrequency *table, int numWords) {
    for (int i = 0; i < numWords; i++) {
        table[i].word = (char*) malloc(MAX_WORD_LENGTH * sizeof(char));
        table[i].count = 0;
    }
}

int compareWords(const void *a, const void *b) {
    return strcmp(*(char**)a, *(char**)b);
}

void printWordFrequencyTable(WordFrequency *table, int numWords) {
    qsort(table, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", table[i].word, table[i].count);
    }
}

int main() {
    FILE *inputFile;
    char line[MAX_LINE_LENGTH];
    int numWords = 0;
    WordFrequency *wordFrequencyTable;

    inputFile = fopen("resume.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    wordFrequencyTable = (WordFrequency*) malloc(MAX_NUM_WORDS * sizeof(WordFrequency));
    initializeWordFrequencyTable(wordFrequencyTable, MAX_NUM_WORDS);

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        char *token = strtok(line, " ");

        while (token!= NULL) {
            int wordLength = strlen(token);

            if (wordLength <= MAX_WORD_LENGTH) {
                int i;
                for (i = 0; i < numWords; i++) {
                    if (strcmp(token, wordFrequencyTable[i].word) == 0) {
                        wordFrequencyTable[i].count++;
                        break;
                    }
                }

                if (i == numWords) {
                    numWords++;
                    wordFrequencyTable = (WordFrequency*) realloc(wordFrequencyTable, numWords * sizeof(WordFrequency));

                    strncpy(wordFrequencyTable[numWords - 1].word, token, MAX_WORD_LENGTH);
                    wordFrequencyTable[numWords - 1].word[MAX_WORD_LENGTH - 1] = '\0';
                    wordFrequencyTable[numWords - 1].count = 1;
                }
            }

            token = strtok(NULL, " ");
        }
    }

    printWordFrequencyTable(wordFrequencyTable, numWords);

    fclose(inputFile);

    return 0;
}
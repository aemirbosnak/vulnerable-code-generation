//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main() {
    FILE* fp;
    char line[MAX_WORD_LENGTH];
    char* token;
    WordFrequency* wordFrequencyTable = malloc(MAX_WORDS * sizeof(WordFrequency));
    int numWords = 0;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        token = strtok(line, ",.!?;:");
        while (token!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Exceeded maximum number of words.\n");
                exit(1);
            }
            strcpy(wordFrequencyTable[numWords].word, token);
            wordFrequencyTable[numWords].count = 1;
            numWords++;
            token = strtok(NULL, ",.!?;:");
        }
    }

    qsort(wordFrequencyTable, numWords, sizeof(WordFrequency), compareWords);

    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordFrequencyTable[i].word, wordFrequencyTable[i].count);
    }

    free(wordFrequencyTable);
    fclose(fp);

    return 0;
}
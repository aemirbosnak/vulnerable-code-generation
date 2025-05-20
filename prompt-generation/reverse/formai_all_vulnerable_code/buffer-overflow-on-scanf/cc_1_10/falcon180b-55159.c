//Falcon-180B DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount*)a;
    WordCount *wc2 = (WordCount*)b;
    return strcmp(wc1->word, wc2->word);
}

void printWordCounts(WordCount *counts, int numWords) {
    qsort(counts, numWords, sizeof(WordCount), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", counts[i].word, counts[i].count);
    }
}

int main() {
    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordCount counts[1000];
    int numWords = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, " \t\n\r\f\v");
        while (token!= NULL) {
            strcpy(word, token);
            counts[numWords].word = strdup(word);
            counts[numWords].count = 1;
            numWords++;
            token = strtok(NULL, " \t\n\r\f\v");
        }
    }

    fclose(fp);

    printWordCounts(counts, numWords);

    return 0;
}
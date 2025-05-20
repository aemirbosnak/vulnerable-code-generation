//Falcon-180B DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1000
#define MAX_WORD_LEN 100

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void readFile(FILE *file, char *filename) {
    char line[MAX_LINE];
    int lineNum = 1;

    while (fgets(line, MAX_LINE, file)!= NULL) {
        printf("%d : %s", lineNum, line);
        lineNum++;
    }
}

void countWords(char *line, WordCount *wordCounts, int numWords) {
    char *word = strtok(line, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, wordCounts[i].word) == 0) {
                wordCounts[i].count++;
                break;
            }
        }
        if (i == numWords) {
            wordCounts[numWords].word = strdup(word);
            wordCounts[numWords].count = 1;
            numWords++;
        }
        word = strtok(NULL, " ");
    }
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s : %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    char filename[MAX_LINE];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE];
    WordCount wordCounts[MAX_WORD_LEN];
    int numWords = 0;

    while (fgets(line, MAX_LINE, file)!= NULL) {
        countWords(line, wordCounts, numWords);
    }

    fclose(file);

    printf("Word Counts:\n");
    printWordCounts(wordCounts, numWords);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000
#define MAX_WORD 100

typedef struct {
    char *word;
    int count;
} WordCount;

WordCount *readWords(FILE *fp) {
    char line[MAX_LINE];
    WordCount *wordCounts = NULL;
    int numWords = 0;

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, wordCounts[i].word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                wordCounts = realloc(wordCounts, sizeof(WordCount) * (numWords + 1));
                wordCounts[numWords].word = strdup(word);
                wordCounts[numWords].count = 1;
                numWords++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    return wordCounts;
}

void printWords(WordCount *wordCounts, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

void freeWords(WordCount *wordCounts, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        free(wordCounts[i].word);
    }
    free(wordCounts);
}

int main() {
    FILE *fp;
    char filename[MAX_LINE];
    WordCount *wordCounts = NULL;
    int numWords = 0;

    printf("Enter a filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    wordCounts = readWords(fp);
    fclose(fp);

    printWords(wordCounts, numWords);

    freeWords(wordCounts, numWords);

    return 0;
}
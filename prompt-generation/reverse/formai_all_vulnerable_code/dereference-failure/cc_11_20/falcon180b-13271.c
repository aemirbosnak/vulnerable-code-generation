//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char word[MAX_LINE_LENGTH];
    int numWords = 0;
    WordCount *wordCounts = NULL;
    int i, j;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        numWords = 0;
        memset(wordCounts, 0, sizeof(WordCount) * MAX_NUM_WORDS);

        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (numWords >= MAX_NUM_WORDS) {
                printf("Warning: Too many words in line. Truncating.\n");
                break;
            }

            if (isalpha(token[0])) {
                strcpy(wordCounts[numWords].word, token);
                wordCounts[numWords].count++;
                numWords++;
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(fp);

    printf("Total number of lines: %d\n", numWords);

    for (i = 0; i < numWords; i++) {
        printf("Word '%s' appears %d times.\n", wordCounts[i].word, wordCounts[i].count);
    }

    for (i = 0; i < numWords; i++) {
        for (j = i + 1; j < numWords; j++) {
            if (strcmp(wordCounts[i].word, wordCounts[j].word) == 0) {
                wordCounts[i].count += wordCounts[j].count;
                wordCounts[j].count = 0;
            }
        }
    }

    for (i = 0; i < numWords; i++) {
        if (wordCounts[i].count > 0) {
            printf("Word '%s' appears %d times.\n", wordCounts[i].word, wordCounts[i].count);
        }
    }

    free(wordCounts);

    return 0;
}
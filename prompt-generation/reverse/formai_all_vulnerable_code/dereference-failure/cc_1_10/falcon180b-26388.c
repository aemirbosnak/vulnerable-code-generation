//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_LENGTH 1000000
#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    if (((Word*)a)->count > ((Word*)b)->count) {
        return -1;
    } else if (((Word*)a)->count < ((Word*)b)->count) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    char log[MAX_LOG_LENGTH];
    if (fread(log, sizeof(char), MAX_LOG_LENGTH, fp)!= MAX_LOG_LENGTH) {
        printf("Error: could not read entire log file.\n");
        return 1;
    }

    fclose(fp);

    int numWords = 0;
    Word words[MAX_WORDS];
    char *token = strtok(log, " \n\t\r");
    while (token!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in log file.\n");
            return 1;
        }

        int i;
        for (i = 0; i < strlen(token); i++) {
            if (!isalnum(token[i])) {
                token[i] = '\0';
            }
        }

        strcpy(words[numWords].word, token);
        words[numWords].count = 1;
        numWords++;

        token = strtok(NULL, " \n\t\r");
    }

    qsort(words, numWords, sizeof(Word), compareWords);

    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
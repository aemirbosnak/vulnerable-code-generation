//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_LINE_SIZE 1024
#define MAX_WORD_SIZE 32

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE *logFile = fopen("logfile.txt", "r");

    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    char logLine[MAX_LOG_LINE_SIZE];
    WordCount wordCounts[MAX_LOG_LINE_SIZE];
    int numWords = 0;

    while (fgets(logLine, MAX_LOG_LINE_SIZE, logFile)!= NULL) {
        char *token = strtok(logLine, " ");

        while (token!= NULL) {
            if (numWords >= MAX_LOG_LINE_SIZE) {
                printf("Error: Too many words in log line.\n");
                return 1;
            }

            WordCount *word = &wordCounts[numWords];
            strncpy(word->word, token, MAX_WORD_SIZE);
            word->word[MAX_WORD_SIZE - 1] = '\0';
            word->count = 1;

            numWords++;

            token = strtok(NULL, " ");
        }
    }

    fclose(logFile);

    printWordCounts(wordCounts, numWords);

    return 0;
}
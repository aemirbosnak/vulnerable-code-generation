//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_SIZE 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readLog(FILE *logFile, char *logBuffer, int *logSize) {
    char c;
    int i = 0;

    while ((c = fgetc(logFile))!= EOF) {
        if (i >= *logSize - 1) {
            *logSize += 10000;
            logBuffer = realloc(logBuffer, *logSize);
        }
        logBuffer[i++] = c;
    }
    logBuffer[i] = '\0';
}

void tokenize(char *logBuffer, WordCount words[], int numWords) {
    char *token = strtok(logBuffer, " \t\r\n");
    int i = 0;

    while (token!= NULL && i < numWords) {
        strcpy(words[i].word, token);
        i++;
        token = strtok(NULL, " \t\r\n");
    }
}

void countWords(WordCount words[], int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        words[i].count++;
    }
}

void printResults(WordCount words[], int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *logFile;
    char *logBuffer = NULL;
    int logSize = 0;
    WordCount words[MAX_WORD_LENGTH];
    int numWords = 0;

    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    logFile = fopen(argv[1], "r");
    if (logFile == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    readLog(logFile, logBuffer, &logSize);
    fclose(logFile);

    tokenize(logBuffer, words, MAX_WORD_LENGTH);
    countWords(words, MAX_WORD_LENGTH);
    printResults(words, MAX_WORD_LENGTH);

    free(logBuffer);
    return 0;
}
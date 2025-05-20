//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_SIZE 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readLog(FILE *logFile, WordCount words[]) {
    char line[MAX_LOG_SIZE];
    while (fgets(line, MAX_LOG_SIZE, logFile)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < MAX_WORD_LENGTH; i++) {
                if (token[i] == '\0') {
                    words[i].word[i] = '\0';
                    words[i].count++;
                    break;
                } else {
                    strncat(words[i].word, token, i);
                }
            }
            token = strtok(NULL, " ");
        }
    }
}

void printTopWords(WordCount words[], int numWords) {
    printf("Top %d words:\n", numWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *logFile = fopen(argv[1], "r");
    if (logFile == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    WordCount words[MAX_WORD_LENGTH];
    readLog(logFile, words);

    int numWords = 0;
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        if (words[i].word[0]!= '\0') {
            numWords++;
        }
    }

    printf("Total words: %d\n", numWords);
    printTopWords(words, numWords);

    fclose(logFile);
    return 0;
}
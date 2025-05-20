//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_SIZE 100000 // maximum size of log file
#define MAX_WORD_SIZE 100 // maximum size of word
#define MAX_LINE_SIZE 1000 // maximum size of line

typedef struct {
    char *word;
    int count;
} WordCount;

int main() {
    FILE *logFile;
    char logLine[MAX_LINE_SIZE];
    char word[MAX_WORD_SIZE];
    WordCount wordCounts[MAX_LOG_SIZE];
    int numWords = 0;
    int i;

    logFile = fopen("logfile.txt", "r");
    if (logFile == NULL) {
        printf("Error opening log file\n");
        exit(1);
    }

    while (fgets(logLine, MAX_LINE_SIZE, logFile)!= NULL) {
        char *token = strtok(logLine, " ");
        while (token!= NULL) {
            strcpy(word, token);
            for (i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                }
            }
            int j;
            for (j = 0; j < numWords; j++) {
                if (strcmp(wordCounts[j].word, word) == 0) {
                    wordCounts[j].count++;
                    break;
                }
            }
            if (j == numWords) {
                strcpy(wordCounts[numWords].word, word);
                wordCounts[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(logFile);

    printf("Word count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}
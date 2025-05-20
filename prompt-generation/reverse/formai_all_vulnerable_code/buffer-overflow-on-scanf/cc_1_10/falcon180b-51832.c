//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000000 // Maximum size of log file
#define MAX_WORD_LEN 100 // Maximum length of a word
#define MAX_NUM_WORDS 1000 // Maximum number of words to store in memory

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void readLogFile(FILE *fp, WordCount *wordCounts, int numWords) {
    char line[MAX_LOG_SIZE];
    char *word;
    int i = 0;

    while (fgets(line, MAX_LOG_SIZE, fp)!= NULL) {
        word = strtok(line, " \t\n\r\f\v");
        while (word!= NULL) {
            if (i >= numWords) {
                break;
            }
            strncpy(wordCounts[i].word, word, MAX_WORD_LEN);
            wordCounts[i].count = 1;
            i++;
            word = strtok(NULL, " \t\n\r\f\v");
        }
    }
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (wordCounts[i].count > 0) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main() {
    FILE *fp;
    char logFilePath[MAX_LOG_SIZE];
    WordCount wordCounts[MAX_NUM_WORDS];
    int numWords = 0;

    printf("Enter the path to the log file: ");
    scanf("%s", logFilePath);

    fp = fopen(logFilePath, "r");
    if (fp == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    readLogFile(fp, wordCounts, MAX_NUM_WORDS);
    fclose(fp);

    printf("Word counts:\n");
    printWordCounts(wordCounts, numWords);

    return 0;
}
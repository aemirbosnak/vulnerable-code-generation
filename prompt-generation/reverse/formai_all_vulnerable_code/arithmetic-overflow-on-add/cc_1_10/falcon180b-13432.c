//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

void printTopWords(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    printf("Top words:\n");
    for (int i = 0; i < numWords && i < 10; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE *logFile;
    char logBuffer[MAX_LOG_SIZE];
    WordCount wordCounts[MAX_WORD_LENGTH];
    int numWords = 0;

    logFile = fopen("example.log", "r");

    if (logFile == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    while (fgets(logBuffer, MAX_LOG_SIZE, logFile)!= NULL) {
        char *token = strtok(logBuffer, " ");

        while (token!= NULL) {
            int wordLength = strlen(token);

            if (wordLength > MAX_WORD_LENGTH) {
                wordLength = MAX_WORD_LENGTH;
            }

            strncpy(wordCounts[numWords].word, token, wordLength);
            wordCounts[numWords].count++;
            numWords++;

            if (numWords >= MAX_WORD_LENGTH) {
                break;
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(logFile);

    printTopWords(wordCounts, numWords);

    return 0;
}
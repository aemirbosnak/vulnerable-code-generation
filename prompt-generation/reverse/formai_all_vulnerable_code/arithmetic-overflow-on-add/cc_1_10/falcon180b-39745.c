//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* wordA = (const WordCount*)a;
    const WordCount* wordB = (const WordCount*)b;
    return strcmp(wordA->word, wordB->word);
}

void printWordCounts(WordCount* wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE* logFile = fopen("logfile.txt", "r");
    if (logFile == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    char line[MAX_LINE_SIZE];
    WordCount wordCounts[MAX_WORD_SIZE];
    int numWords = 0;

    time_t startTime, endTime;
    time(&startTime);

    while (fgets(line, MAX_LINE_SIZE, logFile)!= NULL) {
        int wordIndex = 0;
        char* word = strtok(line, " ");
        while (word!= NULL) {
            if (wordIndex >= MAX_WORD_SIZE) {
                printf("Too many words in line.\n");
                break;
            }
            strcpy(wordCounts[wordIndex].word, word);
            wordCounts[wordIndex].count++;
            wordIndex++;
            word = strtok(NULL, " ");
        }
        numWords = wordIndex;
    }

    time(&endTime);
    double elapsedTime = difftime(endTime, startTime);

    printf("Total words: %d\n", numWords);
    printf("Elapsed time: %.2f seconds\n", elapsedTime);

    printWordCounts(wordCounts, numWords);

    fclose(logFile);
    return 0;
}
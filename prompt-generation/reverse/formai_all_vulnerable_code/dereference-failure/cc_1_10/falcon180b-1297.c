//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    return strcmp(wc1->word, wc2->word);
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    FILE *logFile = fopen(argv[1], "r");
    if (logFile == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    WordCount wordCounts[MAX_WORD_LENGTH];
    int numWords = 0;

    while (fgets(line, MAX_LINE_LENGTH, logFile)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            WordCount *wc = NULL;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(token, wordCounts[i].word) == 0) {
                    wc = &wordCounts[i];
                    break;
                }
            }

            if (wc == NULL) {
                if (numWords >= MAX_WORD_LENGTH) {
                    printf("Error: Too many unique words in log file.\n");
                    fclose(logFile);
                    return 1;
                }

                wc = &wordCounts[numWords++];
                strncpy(wc->word, token, MAX_WORD_LENGTH - 1);
                wc->word[MAX_WORD_LENGTH - 1] = '\0';
                wc->count = 1;
            } else {
                wc->count++;
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(logFile);
    printWordCounts(wordCounts, numWords);

    return 0;
}
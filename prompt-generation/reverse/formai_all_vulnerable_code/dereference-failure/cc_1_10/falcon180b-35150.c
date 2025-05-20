//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100000
#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *) a;
    WordCount *wordB = (WordCount *) b;
    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *logFile = fopen(argv[1], "r");
    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    int numLines = 0;
    int numWords = 0;
    char line[MAX_LINE_LENGTH];
    WordCount words[MAX_LINES];

    while (fgets(line, MAX_LINE_LENGTH, logFile)!= NULL) {
        if (numLines >= MAX_LINES) {
            printf("Error: Reached maximum number of lines.\n");
            break;
        }
        numLines++;

        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (numWords >= MAX_LINES) {
                printf("Error: Reached maximum number of words.\n");
                break;
            }
            numWords++;

            WordCount *existingWord = bsearch(word, words, numWords, sizeof(WordCount), compareWords);
            if (existingWord == NULL) {
                existingWord = &words[numWords];
                strncpy(existingWord->word, word, MAX_WORD_LENGTH);
                existingWord->word[MAX_WORD_LENGTH - 1] = '\0';
                existingWord->count = 1;
                qsort(words, numWords, sizeof(WordCount), compareWords);
            } else {
                existingWord->count++;
            }

            word = strtok(NULL, " ");
        }
    }

    fclose(logFile);

    printf("Total lines: %d\n", numLines);
    printf("Total words: %d\n", numWords);

    qsort(words, numWords, sizeof(WordCount), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
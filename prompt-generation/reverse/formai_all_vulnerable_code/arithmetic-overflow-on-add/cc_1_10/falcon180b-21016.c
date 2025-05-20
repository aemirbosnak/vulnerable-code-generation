//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LOG_LINES 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

int main(int argc, char *argv[])
{
    FILE *logFile;
    char line[MAX_LOG_LINES];
    int numLines = 0;
    char *words[MAX_WORD_LEN];
    int numWords = 0;
    WordCount wordCounts[MAX_WORD_LEN];
    int i;

    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    logFile = fopen(argv[1], "r");
    if (logFile == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    while (fgets(line, MAX_LOG_LINES, logFile)) {
        numLines++;

        // Tokenize the line into words
        words[numWords] = strtok(line, " ");
        while (words[numWords]!= NULL) {
            numWords++;
            words[numWords] = strtok(NULL, " ");
        }

        // Count the frequency of each word
        for (i = 0; i < numWords; i++) {
            int j;
            for (j = 0; j < numWords; j++) {
                if (strcmp(words[i], words[j]) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }
        }
    }

    fclose(logFile);

    // Sort the words alphabetically
    qsort(words, numWords, sizeof(char *), compareWords);

    // Print the word frequency table
    printf("Word\tFrequency\n");
    for (i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i], wordCounts[i].count);
    }

    return 0;
}
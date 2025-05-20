//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 50

typedef struct {
    char* word;
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    WordCount* wc1 = (WordCount*)a;
    WordCount* wc2 = (WordCount*)b;

    if(wc1->count > wc2->count) {
        return -1;
    } else if(wc1->count < wc2->count) {
        return 1;
    } else {
        return 0;
    }
}

void logAnalysis(FILE* logFile) {
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordCount words[1000];
    int numWords = 0;

    while(fgets(line, MAX_LINE_LENGTH, logFile)!= NULL) {
        char* token = strtok(line, " ");
        while(token!= NULL) {
            int i;
            for(i = 0; i < numWords; i++) {
                if(strcmp(token, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if(i == numWords) {
                if(numWords == 1000) {
                    printf("Error: Maximum number of words reached.\n");
                    exit(1);
                }
                strcpy(words[numWords].word, token);
                words[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, " ");
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word\tCount\n");
    for(int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char** argv) {
    if(argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    FILE* logFile = fopen(argv[1], "r");
    if(logFile == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    logAnalysis(logFile);

    fclose(logFile);
    return 0;
}
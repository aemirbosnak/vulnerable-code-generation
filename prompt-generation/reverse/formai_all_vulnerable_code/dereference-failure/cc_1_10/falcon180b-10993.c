//Falcon-180B DATASET v1.0 Category: File handling ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *) a;
    WordCount *wordB = (WordCount *) b;

    if (wordA->count > wordB->count) {
        return -1;
    } else if (wordA->count < wordB->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *inputFile;
    char line[MAX_LINE_LENGTH];
    char *token;
    WordCount words[MAX_NUM_WORDS];
    int numWords = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords >= MAX_NUM_WORDS) {
                    printf("Error: Too many unique words.\n");
                    exit(1);
                }
                words[numWords].word = strdup(token);
                words[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, " ");
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    return 0;
}
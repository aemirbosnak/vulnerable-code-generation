//Falcon-180B DATASET v1.0 Category: File handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 100

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char *words[MAX_NUM_WORDS];
    int numWords = 0;
    WordCount wordCounts[MAX_NUM_WORDS];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, ",.!?;:");
        while (token!= NULL) {
            if (numWords >= MAX_NUM_WORDS) {
                printf("Too many words in line.\n");
                exit(1);
            }
            words[numWords] = token;
            numWords++;
            token = strtok(NULL, ",.!?;:");
        }
        for (int i = 0; i < numWords; i++) {
            WordCount *word = NULL;
            for (int j = 0; j < i; j++) {
                if (strcmp(words[i], words[j]) == 0) {
                    word = &wordCounts[j];
                    break;
                }
            }
            if (word == NULL) {
                if (numWords >= MAX_NUM_WORDS) {
                    printf("Too many unique words in file.\n");
                    exit(1);
                }
                word = &wordCounts[numWords];
                numWords++;
            }
            word->count++;
        }
    }

    printWordCounts(wordCounts, numWords);

    fclose(file);
    return 0;
}
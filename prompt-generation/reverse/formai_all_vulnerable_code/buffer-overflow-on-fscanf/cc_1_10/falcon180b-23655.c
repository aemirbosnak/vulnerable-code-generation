//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* wordA = (const WordCount*)a;
    const WordCount* wordB = (const WordCount*)b;

    if (wordA->count > wordB->count) {
        return -1;
    } else if (wordA->count < wordB->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input[MAX_WORD_LENGTH];
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    WordCount words[MAX_NUM_WORDS];
    int numWords = 0;

    while (fscanf(inputFile, "%s", input)!= EOF) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, input) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == numWords) {
            if (numWords >= MAX_NUM_WORDS) {
                printf("Error: Too many unique words in input file.\n");
                exit(1);
            }
            strcpy(words[numWords].word, input);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(inputFile);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s %d\n", words[i].word, words[i].count);
    }

    return 0;
}
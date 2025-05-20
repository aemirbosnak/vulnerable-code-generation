//Falcon-180B DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void readWords(char* filename, WordCount* wordCounts, int numWords) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    int i = 0;
    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (i >= numWords) {
            printf("Error: too many words in file\n");
            exit(1);
        }

        strcpy(wordCounts[i].word, word);
        wordCounts[i].count = 1;
        i++;
    }

    fclose(fp);
}

int compareWordCounts(const void* a, const void* b) {
    const WordCount* wc1 = (const WordCount*)a;
    const WordCount* wc2 = (const WordCount*)b;

    return strcmp(wc1->word, wc2->word);
}

void printWordCounts(WordCount* wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWordCounts);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    char filename[MAX_WORD_LEN];
    printf("Enter filename: ");
    scanf("%s", filename);

    int numWords = 0;
    printf("Enter number of words to count: ");
    scanf("%d", &numWords);

    WordCount wordCounts[MAX_WORDS];
    readWords(filename, wordCounts, numWords);

    printWordCounts(wordCounts, numWords);

    return 0;
}
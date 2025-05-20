//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void* a, const void* b) {
    WordCount* wordCountA = (WordCount*)a;
    WordCount* wordCountB = (WordCount*)b;

    if (wordCountA->count > wordCountB->count) {
        return -1;
    } else if (wordCountA->count < wordCountB->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    WordCount wordFrequency[MAX_WORDS];

    while (fscanf(file, "%s", word)!= EOF) {
        wordCount++;
        if (wordCount >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            fclose(file);
            return 1;
        }

        int i;
        for (i = 0; i < wordCount; i++) {
            if (strcmp(wordFrequency[i].word, word) == 0) {
                wordFrequency[i].count++;
                break;
            }
        }

        if (i == wordCount) {
            strcpy(wordFrequency[wordCount].word, word);
            wordFrequency[wordCount].count = 1;
        }
    }

    fclose(file);

    qsort(wordFrequency, wordCount, sizeof(WordCount), compare);

    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < wordCount; i++) {
        printf("%s: %d\n", wordFrequency[i].word, wordFrequency[i].count);
    }

    return 0;
}
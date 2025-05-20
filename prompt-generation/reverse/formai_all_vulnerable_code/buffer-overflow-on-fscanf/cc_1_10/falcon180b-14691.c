//Falcon-180B DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* w1 = a;
    const WordCount* w2 = b;

    if (w1->count > w2->count) {
        return -1;
    } else if (w1->count < w2->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    WordCount words[MAX_WORDS];
    int numWords = 0;

    char word[MAX_WORD_LEN];
    while (fscanf(inputFile, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Reached maximum number of words.\n");
                fclose(inputFile);
                return 1;
            }

            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    return 0;
}
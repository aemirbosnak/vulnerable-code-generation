//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Ken Thompson
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;

    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
        return 1;
    }

    WordCount *wordCounts[MAX_WORD_COUNT];
    int numWords = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_WORD_COUNT) {
            fprintf(stderr, "Error: Maximum word count reached\n");
            return 1;
        }

        WordCount *wordCount = malloc(sizeof(WordCount));
        strcpy(wordCount->word, word);
        wordCount->count = 1;

        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, wordCounts[i]->word) == 0) {
                wordCounts[i]->count++;
                free(wordCount);
                break;
            }
        }

        if (i == numWords) {
            wordCounts[numWords] = wordCount;
            numWords++;
        }
    }

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i]->word, wordCounts[i]->count);
    }

    return 0;
}
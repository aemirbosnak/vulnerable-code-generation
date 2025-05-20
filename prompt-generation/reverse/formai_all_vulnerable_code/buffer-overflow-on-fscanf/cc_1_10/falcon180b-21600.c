//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;
    return strcmp(wordA->word, wordB->word);
}

void printTopWords(WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
    printf("Top %d most frequent words:\n", numWords);
    for (int i = 0; i < numWords && i < MAX_WORDS; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < numWords; i++) {
            if (strcmp(wordFrequencies[i].word, word) == 0) {
                wordFrequencies[i].count++;
                break;
            }
        }
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }
        strcpy(wordFrequencies[numWords].word, word);
        wordFrequencies[numWords].count = 1;
        numWords++;
    }

    fclose(file);

    printTopWords(wordFrequencies, numWords);

    return 0;
}
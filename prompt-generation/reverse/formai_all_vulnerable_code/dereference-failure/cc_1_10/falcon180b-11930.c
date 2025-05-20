//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void printWordFrequency(WordFrequency *wordFrequency, int numWords) {
    qsort(wordFrequency, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequency[i].word, wordFrequency[i].frequency);
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    int numWords = 0;
    WordFrequency *wordFrequency = NULL;

    while (fscanf(file, "%s", word)!= EOF) {
        numWords++;
        wordFrequency = realloc(wordFrequency, sizeof(WordFrequency) * numWords);
        strcpy(wordFrequency[numWords - 1].word, word);
        wordFrequency[numWords - 1].frequency = 1;
    }

    fclose(file);

    printWordFrequency(wordFrequency, numWords);

    free(wordFrequency);
    return 0;
}
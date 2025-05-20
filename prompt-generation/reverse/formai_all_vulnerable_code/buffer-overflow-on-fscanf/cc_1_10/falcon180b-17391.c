//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }

        if (i == numWords) {
            strcpy(words[numWords].word, word);
            words[numWords].frequency = 1;
            numWords++;
        }
    }

    fclose(inputFile);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}
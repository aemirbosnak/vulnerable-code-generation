//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* wordA = (const WordCount*)a;
    const WordCount* wordB = (const WordCount*)b;

    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char buffer[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int numWords = 0;

    while (fscanf(inputFile, "%s", buffer)!= EOF) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(buffer, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }
            strcpy(words[numWords].word, buffer);
            words[numWords].count = 1;
            numWords++;
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    return 0;
}
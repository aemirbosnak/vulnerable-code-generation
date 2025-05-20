//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void readWords(FILE* file, struct WordFrequency* words, int* numWords) {
    char buffer[MAX_WORD_LENGTH];
    int currentWord = 0;
    while (fscanf(file, "%s", buffer)!= EOF) {
        if (currentWord >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }
        strcpy(words[currentWord].word, buffer);
        words[currentWord].frequency = 1;
        currentWord++;
    }
    *numWords = currentWord;
}

int compareWords(const void* a, const void* b) {
    struct WordFrequency* wordA = (struct WordFrequency*)a;
    struct WordFrequency* wordB = (struct WordFrequency*)b;
    return strcmp(wordA->word, wordB->word);
}

void printTopWords(struct WordFrequency* words, int numWords, int topN) {
    qsort(words, numWords, sizeof(struct WordFrequency), compareWords);
    printf("Top %d most frequent words:\n", topN);
    for (int i = 0; i < topN && i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <top_n>\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    int numWords = 0;
    struct WordFrequency words[MAX_WORDS];
    readWords(inputFile, words, &numWords);

    int topN = atoi(argv[2]);
    if (topN <= 0 || topN > numWords) {
        printf("Error: Invalid top N value.\n");
        return 1;
    }

    printTopWords(words, numWords, topN);

    fclose(inputFile);
    return 0;
}
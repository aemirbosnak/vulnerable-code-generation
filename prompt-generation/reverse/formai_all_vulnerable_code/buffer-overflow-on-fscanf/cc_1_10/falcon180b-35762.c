//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    WordFrequency* wordA = (WordFrequency*)a;
    WordFrequency* wordB = (WordFrequency*)b;

    if (wordA->frequency > wordB->frequency) {
        return -1;
    } else if (wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

void readWords(FILE* file, WordFrequency* words, int* numWords) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (*numWords >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }
        strcpy(words[*numWords].word, word);
        words[*numWords].frequency = 1;
        (*numWords)++;
    }
}

void writeWords(FILE* file, WordFrequency* words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < numWords; i++) {
        fprintf(file, "%s %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    FILE* outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error: Cannot open output file.\n");
        fclose(inputFile);
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readWords(inputFile, words, &numWords);

    writeWords(outputFile, words, numWords);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
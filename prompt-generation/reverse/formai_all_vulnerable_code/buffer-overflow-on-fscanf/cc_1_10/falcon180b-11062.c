//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    WordFrequency* wordA = (WordFrequency*)a;
    WordFrequency* wordB = (WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

void readWords(FILE* file, WordFrequency* words, int* numWords) {
    char word[WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < *numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }
        if (i == *numWords) {
            if (*numWords >= MAX_WORDS) {
                fprintf(stderr, "Error: Too many words!\n");
                exit(1);
            }
            strcpy(words[*numWords].word, word);
            words[*numWords].frequency = 1;
            (*numWords)++;
        }
    }
}

void writeWords(FILE* file, WordFrequency* words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        fprintf(file, "%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error: Could not open input file!\n");
        return 1;
    }

    FILE* outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error: Could not open output file!\n");
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
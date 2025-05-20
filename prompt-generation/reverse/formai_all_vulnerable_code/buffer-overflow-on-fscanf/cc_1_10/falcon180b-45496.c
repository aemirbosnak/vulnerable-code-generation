//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWordsFromFile(FILE* file, WordFrequency* words, int* numWords);
int compareWords(const void* a, const void* b);
void printFrequencyTable(WordFrequency* words, int numWords);

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readWordsFromFile(inputFile, words, &numWords);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    printf("Frequency table:\n");
    printFrequencyTable(words, numWords);

    fclose(inputFile);
    return 0;
}

void readWordsFromFile(FILE* file, WordFrequency* words, int* numWords) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (*numWords == MAX_WORDS) {
            printf("Error: too many words in input file.\n");
            exit(1);
        }
        strcpy(words[*numWords].word, word);
        words[*numWords].frequency = 1;
        (*numWords)++;
    }
}

int compareWords(const void* a, const void* b) {
    WordFrequency wordA = *(WordFrequency*)a;
    WordFrequency wordB = *(WordFrequency*)b;
    return strcmp(wordA.word, wordB.word);
}

void printFrequencyTable(WordFrequency* words, int numWords) {
    printf("Word\t\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t\t%d\n", words[i].word, words[i].frequency);
    }
}
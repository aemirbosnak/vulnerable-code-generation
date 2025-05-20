//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;
    return strcmp(wordA->word, wordB->word);
}

void readWords(FILE* file, WordFrequency* words) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
                break;
            }
        }
        strcpy(words[i].word, word);
        words[i].frequency = 1;
        i++;
    }
}

void writeWords(FILE* file, WordFrequency* words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < numWords; i++) {
        fprintf(file, "%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readWords(inputFile, words);
    fclose(inputFile);

    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    writeWords(outputFile, words, numWords);
    fclose(outputFile);

    return 0;
}
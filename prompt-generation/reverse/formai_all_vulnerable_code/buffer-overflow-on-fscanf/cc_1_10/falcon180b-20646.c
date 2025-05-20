//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;

    return strcmp(wordA->word, wordB->word);
}

void printWordFrequencies(WordFrequency *frequencies, int numWords) {
    qsort(frequencies, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
    }
}

int main() {
    FILE *inputFile;
    char inputText[MAX_SENTENCE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int wordLength;
    WordFrequency frequencies[MAX_WORDS];
    int numWords = 0;

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error: input file not found.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s", inputText)!= EOF) {
        strcpy(word, "");
        wordLength = 0;

        for (int i = 0; i < strlen(inputText); i++) {
            if (isalpha(inputText[i])) {
                strncat(word, &inputText[i], 1);
                wordLength++;
            } else {
                if (wordLength > 0) {
                    strcpy(frequencies[numWords].word, word);
                    frequencies[numWords].count++;
                    numWords++;
                    wordLength = 0;
                }
            }
        }

        if (wordLength > 0) {
            strcpy(frequencies[numWords].word, word);
            frequencies[numWords].count++;
            numWords++;
        }
    }

    fclose(inputFile);

    printWordFrequencies(frequencies, numWords);

    return 0;
}
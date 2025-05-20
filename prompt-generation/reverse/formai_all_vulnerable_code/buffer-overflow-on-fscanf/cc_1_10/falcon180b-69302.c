//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void readWords(FILE *inputFile, WordFrequency *words, int *numWords) {
    char word[WORD_LENGTH];
    int i = 0;

    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].frequency = 0;
        i++;
    }

    *numWords = i;
}

void countWordFrequencies(char *text, WordFrequency *words, int numWords) {
    char *token;
    int i = 0;

    token = strtok(text, ",.?!;:\"'");

    while (token!= NULL) {
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }

        token = strtok(NULL, ",.?!;:\"'");
    }
}

void printWordFrequencies(WordFrequency *words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char *text;
    WordFrequency words[MAX_WORDS];
    int numWords;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    readWords(inputFile, words, &numWords);

    fclose(inputFile);

    text = malloc(1024);

    while (fgets(text, 1024, inputFile)!= NULL) {
        countWordFrequencies(text, words, numWords);
    }

    printWordFrequencies(words, numWords);

    free(text);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    const Word *wordA = a;
    const Word *wordB = b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    char text[100000];
    char word[MAX_WORD_LENGTH];
    FILE *inputFile;
    FILE *outputFile;
    Word words[MAX_WORDS];
    int numWords = 0;
    int i, j;

    printf("Enter the name of the input file: ");
    scanf("%s", text);

    inputFile = fopen(text, "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    while (fscanf(inputFile, "%s", word)!= EOF) {
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Error: too many unique words.\n");
                exit(1);
            }
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(inputFile);

    qsort(words, numWords, sizeof(Word), compareWords);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    for (i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(outputFile);

    return 0;
}
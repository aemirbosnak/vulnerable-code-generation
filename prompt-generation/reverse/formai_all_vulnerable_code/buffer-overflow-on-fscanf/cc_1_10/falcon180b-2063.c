//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compare(const void* a, const void* b) {
    WordFrequency* wordA = (WordFrequency*) a;
    WordFrequency* wordB = (WordFrequency*) b;

    if (wordA->count > wordB->count) {
        return -1;
    } else if (wordA->count < wordB->count) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char** argv) {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    char word[MAX_WORD_LENGTH];
    char buffer[1024];
    while (fscanf(inputFile, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }

        int wordLength = strlen(word);
        if (wordLength >= MAX_WORD_LENGTH) {
            printf("Error: word \"%s\" is too long.\n", word);
            continue;
        }

        strcpy(words[numWords].word, word);
        words[numWords].count = 1;
        numWords++;

        if (numWords == MAX_WORDS) {
            printf("Error: too many words.\n");
            break;
        }
    }

    fclose(inputFile);

    qsort(words, numWords, sizeof(WordFrequency), compare);

    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}
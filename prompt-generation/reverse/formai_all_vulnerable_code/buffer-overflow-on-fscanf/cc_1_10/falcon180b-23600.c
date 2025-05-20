//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

bool compareWords(const void *a, const void *b) {
    return strcmp(((WordFrequency*)a)->word, ((WordFrequency*)b)->word) < 0;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int numWords = 0;
    WordFrequency *wordFrequencyArray = NULL;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    while (fscanf(file, "%s", word)!= EOF) {
        numWords++;
    }

    rewind(file);

    wordFrequencyArray = (WordFrequency*)malloc(numWords * sizeof(WordFrequency));

    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= numWords) {
            printf("Error: Too many words in file\n");
            return 1;
        }
        strcpy(wordFrequencyArray[i].word, word);
        wordFrequencyArray[i].frequency = 1;
        i++;
    }

    qsort(wordFrequencyArray, numWords, sizeof(WordFrequency), compareWords);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencyArray[i].word, wordFrequencyArray[i].frequency);
    }

    free(wordFrequencyArray);
    fclose(file);

    return 0;
}
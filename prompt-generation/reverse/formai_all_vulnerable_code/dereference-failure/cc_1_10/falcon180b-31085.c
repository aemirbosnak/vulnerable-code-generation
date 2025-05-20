//Falcon-180B DATASET v1.0 Category: Data mining ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 5000
#define MAX_CHARS_PER_WORD 50

typedef struct {
    char word[MAX_CHARS_PER_WORD];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *file;
    char line[1000];
    char *word;
    char *delimiters = ",.?!;:\"'()[]{}<>";
    int numWords = 0;
    WordFrequency *wordFrequencies = (WordFrequency *) malloc(MAX_WORDS * sizeof(WordFrequency));

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    while (fgets(line, 1000, file)!= NULL) {
        numWords = 0;
        word = strtok(line, delimiters);

        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: too many words in input.\n");
                exit(1);
            }

            strcpy(wordFrequencies[numWords].word, word);
            wordFrequencies[numWords].count = 1;

            numWords++;

            word = strtok(NULL, delimiters);
        }
    }

    fclose(file);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    printf("Word\tFrequency\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    free(wordFrequencies);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_CHARS_PER_WORD 100
#define NUM_CLASSES 2

typedef struct {
    char* word;
    int freq;
    int class;
} WordFreq;

typedef struct {
    int numWords;
    int numClasses;
    WordFreq* words;
} Corpus;

void readWords(char* filename, Corpus* corpus) {
    FILE* fp = fopen(filename, "r");
    char word[MAX_CHARS_PER_WORD];
    int numWords = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            fprintf(stderr, "Error: Maximum number of words exceeded\n");
            exit(1);
        }
        corpus->words[numWords] = (WordFreq) {
           .word = strdup(word),
           .freq = 1,
           .class = -1
        };
        numWords++;
    }
    fclose(fp);
    corpus->numWords = numWords;
}

void countWords(Corpus* corpus) {
    int i;
    for (i = 0; i < corpus->numWords; i++) {
        corpus->words[i].freq++;
    }
}

void assignClasses(Corpus* corpus) {
    int i;
    int numClasses = 0;
    for (i = 0; i < corpus->numWords; i++) {
        if (corpus->words[i].class == -1) {
            corpus->words[i].class = numClasses++;
        }
    }
    corpus->numClasses = numClasses;
}

void printWords(Corpus* corpus) {
    int i;
    for (i = 0; i < corpus->numWords; i++) {
        printf("%s (%d)\tClass: %d\n", corpus->words[i].word, corpus->words[i].freq, corpus->words[i].class);
    }
}

int main() {
    srand(time(NULL));
    Corpus corpus = {0};
    char* filename = "romeo_and_juliet.txt";
    readWords(filename, &corpus);
    countWords(&corpus);
    assignClasses(&corpus);
    printWords(&corpus);
    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct _Word {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word words[MAX_WORDS];
int numWords = 0;

void addWord(char *word) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (!strcmp(words[i].word, word)) {
            words[i].count++;
            return;
        }
    }
    if (numWords == MAX_WORDS) {
        fprintf(stderr, "Error: Too many words.\n");
        exit(1);
    }
    strcpy(words[numWords].word, word);
    words[numWords].count = 1;
    numWords++;
}

void printSummary(int numWordsToPrint) {
    int i;
    for (i = 0; i < numWordsToPrint && i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <number of words to print>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s.\n", argv[1]);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        addWord(word);
    }

    fclose(fp);

    int numWordsToPrint = atoi(argv[2]);

    printSummary(numWordsToPrint);

    return 0;
}
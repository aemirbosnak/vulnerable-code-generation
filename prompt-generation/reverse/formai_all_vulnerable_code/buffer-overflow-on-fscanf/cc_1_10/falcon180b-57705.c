//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10
#define ALPHABET_SIZE 26

typedef struct {
    char word[MAX_WORD_LENGTH+1];
    int count;
} WordCount;

void readWords(FILE *fp, WordCount words[]) {
    char word[MAX_WORD_LENGTH+1];
    int i = 0;

    while (fscanf(fp, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].count = 0;
        i++;
    }
}

void countWords(char *filename, WordCount words[]) {
    FILE *fp;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s.\n", filename);
        exit(1);
    }

    readWords(fp, words);
    fclose(fp);
}

void printWords(WordCount words[]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    WordCount words[MAX_WORDS];

    countWords("input.txt", words);
    printWords(words);

    return 0;
}
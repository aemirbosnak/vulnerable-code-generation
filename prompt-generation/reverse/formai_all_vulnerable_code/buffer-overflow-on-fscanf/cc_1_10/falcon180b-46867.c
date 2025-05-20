//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void loadWords(FILE *fp, WordCount words[]) {
    char word[MAX_WORD_LEN];
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

void printWords(WordCount words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[MAX_WORD_LEN];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    WordCount words[MAX_WORDS];
    loadWords(fp, words);

    int numWords = 0;
    while (fscanf(fp, "%s", words[numWords].word)!= EOF) {
        numWords++;

        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }
    }

    fclose(fp);

    printf("Enter the name of the output file: ");
    scanf("%s", filename);

    FILE *outfp = fopen(filename, "w");
    if (outfp == NULL) {
        printf("Error: Could not create output file.\n");
        exit(1);
    }

    printWords(words, numWords);

    fclose(outfp);

    return 0;
}
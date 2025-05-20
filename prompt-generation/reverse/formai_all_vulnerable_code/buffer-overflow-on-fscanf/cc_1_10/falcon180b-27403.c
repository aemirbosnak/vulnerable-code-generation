//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN + 1];
    int count;
} WordCount;

void readFile(FILE *fp, char *filename) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            if (i >= MAX_WORD_LEN) {
                printf("Error: Word \"%s\" is too long.\n", filename);
                exit(1);
            }
            strncat(filename + strlen(filename), &ch, 1);
            i++;
        }
    }
    filename[i] = '\0';
}

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = (const WordCount *)a;
    const WordCount *wc2 = (const WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file \"%s\".\n", argv[1]);
        exit(1);
    }

    char filename[MAX_WORD_LEN + 1];
    readFile(fp, filename);

    int numWords = 0;
    WordCount wordCounts[MAX_WORDS];
    char word[MAX_WORD_LEN + 1];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }
        strcpy(wordCounts[numWords].word, word);
        wordCounts[numWords].count = 1;
        numWords++;
    }

    fclose(fp);

    for (int i = 0; i < numWords; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (strcmp(wordCounts[i].word, wordCounts[j].word) == 0) {
                wordCounts[i].count += wordCounts[j].count;
                wordCounts[j].count = 0;
            }
        }
    }

    printWordCounts(wordCounts, numWords);

    return 0;
}
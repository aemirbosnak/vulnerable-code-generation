//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MIN_WORD_LEN 3
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN + 1];
    int count;
} WordCount;

void readFile(char *filename, char *content);
int countWords(char *content, int len, WordCount *wordCount);
int compareWords(const void *a, const void *b);
void printWordCounts(WordCount *wordCount, int numWords);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <numWords>\n", argv[0]);
        return 1;
    }

    char filename[100];
    strcpy(filename, argv[1]);

    char content[100000];
    readFile(filename, content);

    int numWords = atoi(argv[2]);
    WordCount wordCount[MAX_WORDS];

    int wordCounts = countWords(content, strlen(content), wordCount);
    if (wordCounts < numWords) {
        printf("Not enough words in the file.\n");
        return 1;
    }

    qsort(wordCount, wordCounts, sizeof(WordCount), compareWords);
    printWordCounts(wordCount, numWords);

    return 0;
}

void readFile(char *filename, char *content) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    content[len] = '\0';
    fread(content, len, 1, fp);
    fclose(fp);
}

int countWords(char *content, int len, WordCount *wordCount) {
    int wordCounts = 0;
    char *token = strtok(content, ",.?!;:");
    while (token!= NULL) {
        int len = strlen(token);
        if (len >= MIN_WORD_LEN && len <= MAX_WORD_LEN) {
            strcpy(wordCount[wordCounts].word, token);
            wordCount[wordCounts].count = 1;
            wordCounts++;
        }
        token = strtok(NULL, ",.?!;:");
    }

    return wordCounts;
}

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;

    return strcmp(wordA->word, wordB->word);
}

void printWordCounts(WordCount *wordCount, int numWords) {
    printf("Word counts:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCount[i].word, wordCount[i].count);
    }
}
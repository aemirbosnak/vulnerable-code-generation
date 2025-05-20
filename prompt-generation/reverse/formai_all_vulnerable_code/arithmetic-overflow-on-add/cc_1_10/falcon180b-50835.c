//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(FILE *fp, WordCount *wordCounts) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            wordCounts[i].word[wordCounts[i].count++] = tolower(ch);
        } else if (wordCounts[i].count > 0) {
            wordCounts[i].word[wordCounts[i].count] = '\0';
            i++;
            if (i >= MAX_WORDS) {
                printf("Too many words in file.\n");
                exit(1);
            }
        }
    }
    if (i > 0 && wordCounts[i-1].count > 0) {
        wordCounts[i-1].word[wordCounts[i-1].count] = '\0';
    }
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordCount wordCounts[MAX_WORDS];
    readFile(fp, wordCounts);

    int numWords = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordCounts[i].count > 0) {
            numWords++;
        }
    }

    printWordCounts(wordCounts, numWords);

    fclose(fp);
    return 0;
}
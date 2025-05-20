//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 10000

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordCount;

bool compareWords(const void *a, const void *b) {
    const WordCount *wordA = a;
    const WordCount *wordB = b;
    return strcmp(wordA->word, wordB->word) < 0;
}

int main() {
    FILE *fp;
    char ch;
    char word[MAX_WORD_LENGTH + 1] = { 0 };
    WordCount wordCounts[MAX_WORD_COUNT];
    int wordCount = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            strncat(word, &ch, 1);
        } else {
            word[strlen(word) - 1] = '\0';

            int i;
            for (i = 0; i < wordCount; i++) {
                if (strcmp(wordCounts[i].word, word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }

            if (i == wordCount) {
                if (wordCount >= MAX_WORD_COUNT) {
                    printf("Error: maximum word count reached.\n");
                    fclose(fp);
                    return 1;
                }

                strcpy(wordCounts[wordCount].word, word);
                wordCounts[wordCount].count = 1;
                wordCount++;
            }

            memset(word, 0, MAX_WORD_LENGTH + 1);
        }
    }

    fclose(fp);

    qsort(wordCounts, wordCount, sizeof(WordCount), compareWords);

    printf("Word\tCount\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}
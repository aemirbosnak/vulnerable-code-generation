//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

typedef struct {
    char *words[MAX_WORDS];
    int numWords;
} WordArray;

void readWords(FILE *fp, WordArray *array) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (array->numWords >= MAX_WORDS) {
            printf("Error: reached maximum number of words.\n");
            exit(1);
        }
        strcpy(array->words[array->numWords], word);
        array->numWords++;
    }
}

void countWords(WordArray *array, WordCount *counts) {
    for (int i = 0; i < array->numWords; i++) {
        char *word = array->words[i];
        int len = strlen(word);
        for (int j = 0; j < len; j++) {
            if (!isalpha(word[j])) {
                word[j] = '\0';
                len = j;
                break;
            }
        }
        for (int j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, counts[j].word) == 0) {
                counts[j].count++;
                break;
            }
        }
    }
}

void printCounts(WordCount *counts) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (counts[i].count > 0) {
            printf("%s: %d\n", counts[i].word, counts[i].count);
        }
    }
}

int main() {
    srand(time(NULL));
    WordArray array;
    WordCount counts[MAX_WORDS];

    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    readWords(fp, &array);
    fclose(fp);

    countWords(&array, counts);

    printCounts(counts);

    return 0;
}
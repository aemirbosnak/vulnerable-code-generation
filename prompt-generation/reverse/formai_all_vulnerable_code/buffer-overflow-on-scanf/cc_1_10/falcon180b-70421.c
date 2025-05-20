//Falcon-180B DATASET v1.0 Category: Text processing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int getWordCounts(FILE* fp, WordCount* wordCounts) {
    char word[MAX_WORD_LEN] = {0};
    int count = 0;
    int i = 0;

    while (fscanf(fp, "%s", word)!= EOF) {
        for (int j = 0; j < strlen(word); j++) {
            if (isalpha(word[j])) {
                word[j] = tolower(word[j]);
            }
        }
        if (strlen(word) > 0) {
            for (int k = 0; k < MAX_WORD_LEN; k++) {
                if (strcmp(word, wordCounts[k].word) == 0) {
                    wordCounts[k].count++;
                    break;
                }
            }
            if (i < MAX_WORD_LEN) {
                strcpy(wordCounts[i].word, word);
                wordCounts[i].count = 1;
                i++;
            }
        }
        count++;
    }

    return count;
}

void displayWordCounts(WordCount* wordCounts, int count) {
    printf("Total number of words: %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE* fp;
    char filename[50];
    WordCount wordCounts[MAX_WORDS];
    int count;

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File not found\n");
        exit(1);
    }

    count = getWordCounts(fp, wordCounts);

    fclose(fp);

    displayWordCounts(wordCounts, count);

    return 0;
}
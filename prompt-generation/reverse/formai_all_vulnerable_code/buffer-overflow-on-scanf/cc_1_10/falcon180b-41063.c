//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE *fp, WordCount words[]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = toupper(ch);
            words[i].count = 1;
            i++;
        }
    }
}

void countWords(WordCount words[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                words[j].count = 0;
            }
        }
    }
}

void printWords(WordCount words[], int n) {
    for (int i = 0; i < n; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *fp;
    char filename[MAX_WORD_LENGTH];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    WordCount words[MAX_WORDS];
    int n = 0;
    readWords(fp, words);
    countWords(words, n);

    printf("Word frequency:\n");
    printWords(words, n);

    fclose(fp);
    return 0;
}
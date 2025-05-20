//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void loadWords(FILE *fp, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(words[i].word, word);
        words[i].count = 0;
        i++;
    }
}

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void spellCheck(FILE *fp, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(fp, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // remove newline character

        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Unknown word: %s\n", word);
        }
    }
}

void printWords(WordCount words[], int n) {
    qsort(words, n, sizeof(WordCount), compareWords);

    for (int i = 0; i < n; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *fp;
    char filename[50];
    char ch;
    int i = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    WordCount words[MAX_WORDS];

    loadWords(fp, words);

    fclose(fp);

    spellCheck(fp, words);

    printWords(words, i);

    return 0;
}
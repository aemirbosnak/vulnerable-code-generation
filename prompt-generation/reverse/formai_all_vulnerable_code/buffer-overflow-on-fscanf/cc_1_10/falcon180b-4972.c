//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void readWords(FILE *fp, WordCount words[]) {
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

void countWords(char *text, WordCount words[]) {
    char *p, *q;
    int i, j, k;

    for (i = 0; i < strlen(text); i++) {
        if (isspace(text[i])) {
            text[i] = '\0';
        }
    }

    p = strtok(text, " ");

    while (p!= NULL) {
        for (j = 0; j < i; j++) {
            if (strcmp(p, words[j].word) == 0) {
                words[j].count++;
                break;
            }
        }

        if (j == i) {
            if (i >= MAX_WORDS) {
                printf("Error: Too many words.\n");
                exit(1);
            }

            strcpy(words[i].word, p);
            words[i].count = 1;
            i++;
        }

        p = strtok(NULL, " ");
    }
}

void printWords(WordCount words[]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    WordCount words[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    readWords(fp, words);
    fclose(fp);

    countWords(argv[1], words);
    printWords(words);

    return 0;
}
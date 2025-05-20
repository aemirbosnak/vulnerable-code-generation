//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 50000
#define WORD_LEN 50

typedef struct {
    char word[WORD_LEN];
    int count;
} Word;

Word words[MAX_WORDS];
int numWords = 0;

void addWord(char *word) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(word, words[i].word) == 0) {
            words[i].count++;
            return;
        }
    }
    if (numWords >= MAX_WORDS) {
        printf("Error: Max words reached.\n");
        exit(1);
    }
    strcpy(words[numWords].word, word);
    words[numWords].count = 1;
    numWords++;
}

void printWords(FILE *fp) {
    int i;
    for (i = 0; i < numWords; i++) {
        fprintf(fp, "%s %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char word[WORD_LEN];
    int count = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        addWord(word);
        count++;
    }

    fclose(fp);

    printf("Total words: %d\n", count);
    printf("Unique words: %d\n", numWords);

    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not create output file.\n");
        return 1;
    }

    printWords(fp);

    fclose(fp);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct Word *wordTable;
int numWords;

void initWordTable() {
    wordTable = (struct Word*) malloc(MAX_WORDS * sizeof(struct Word));
    numWords = 0;
}

void addWord(char *word) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(wordTable[i].word, word) == 0) {
            wordTable[i].count++;
            return;
        }
    }
    if (numWords >= MAX_WORDS) {
        printf("Error: Word table is full.\n");
        exit(1);
    }
    strcpy(wordTable[numWords].word, word);
    wordTable[numWords].count = 1;
    numWords++;
}

void displayWordTable() {
    int i;
    printf("Word\tCount\n");
    for (i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordTable[i].word, wordTable[i].count);
    }
}

int main() {
    FILE *fp;
    char line[100];
    char word[MAX_WORD_LENGTH];
    int i;

    initWordTable();

    if ((fp = fopen("input.txt", "r")) == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        i = 0;
        while (line[i]!= '\0') {
            if (isalpha(line[i])) {
                strcpy(wordTable[numWords].word, &line[i]);
                wordTable[numWords].count = 1;
                numWords++;
            } else {
                i++;
            }
        }
    }

    displayWordTable();

    fclose(fp);

    return 0;
}
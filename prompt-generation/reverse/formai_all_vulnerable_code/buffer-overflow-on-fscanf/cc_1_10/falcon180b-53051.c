//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

typedef struct {
    WordCount words[MAX_WORDS];
    int numWords;
} Index;

void initIndex(Index *index) {
    index->numWords = 0;
}

int addWord(Index *index, const char *word) {
    int i;
    for (i = 0; i < index->numWords; i++) {
        if (strcmp(index->words[i].word, word) == 0) {
            index->words[i].count++;
            return i;
        }
    }
    if (index->numWords >= MAX_WORDS) {
        return -1;
    }
    strcpy(index->words[index->numWords].word, word);
    index->words[index->numWords].count = 1;
    index->numWords++;
    return index->numWords - 1;
}

void printIndex(Index *index) {
    int i;
    for (i = 0; i < index->numWords; i++) {
        printf("%s: %d\n", index->words[i].word, index->words[i].count);
    }
}

int main() {
    FILE *fp;
    char line[MAX_WORD_LEN];
    char word[MAX_WORD_LEN];
    Index index;
    initIndex(&index);

    fp = fopen("text.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(fp, "%s", line)!= EOF) {
        int i;
        char *token;
        token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (strlen(token) > 0) {
                strcpy(word, token);
                for (i = 0; i < strlen(word); i++) {
                    if (isalpha(word[i])) {
                        word[i] = tolower(word[i]);
                    }
                }
                int wordIndex = addWord(&index, word);
                if (wordIndex >= 0) {
                    index.words[wordIndex].count++;
                }
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(fp);

    printf("Index:\n");
    printIndex(&index);

    return 0;
}
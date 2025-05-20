//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordIndex;

void initIndex(WordIndex *index, int numWords) {
    for (int i = 0; i < numWords; i++) {
        strcpy(index[i].word, "");
        index[i].count = 0;
    }
}

void addWord(WordIndex *index, int numWords, char *word) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(index[i].word, word) == 0) {
            index[i].count++;
            return;
        }
    }
    for (i = 0; i < numWords; i++) {
        if (strcmp(index[i].word, "") == 0) {
            strcpy(index[i].word, word);
            index[i].count = 1;
            return;
        }
    }
}

void printIndex(WordIndex *index, int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(index[i].word, "")!= 0) {
            printf("%s: %d\n", index[i].word, index[i].count);
        }
    }
}

int main() {
    char fileName[50];
    printf("Enter file name: ");
    scanf("%s", fileName);
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    WordIndex index[MAX_WORDS];
    initIndex(index, MAX_WORDS);

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        line[strcspn(line, "\n")] = '\0';
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            addWord(index, MAX_WORDS, word);
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
    printIndex(index, MAX_WORDS);

    return 0;
}
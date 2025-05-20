//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: funny
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

bool isWord(char *str) {
    char *word = str;
    while (*word!= '\0') {
        if (!isalpha(*word)) {
            return false;
        }
        word++;
    }
    return true;
}

void addWord(WordCount *wordCounts, int count, char *word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            wordCounts[i].count++;
            return;
        }
    }
    strcpy(wordCounts[count].word, word);
    wordCounts[count].count = 1;
}

void printWordCounts(WordCount *wordCounts, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    WordCount wordCounts[MAX_WORD_COUNT];
    int count = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fscanf(file, "%s", word)!= EOF) {
        if (isWord(word)) {
            addWord(wordCounts, count, word);
            count++;
        }
    }

    fclose(file);

    printWordCounts(wordCounts, count);

    return 0;
}
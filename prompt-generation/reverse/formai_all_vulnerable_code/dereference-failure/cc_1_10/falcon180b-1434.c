//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100

typedef struct {
    char word[MAX_WORDS][50];
    int count[MAX_WORDS];
} WordCount;

void initializeWordCount(WordCount *wordCount) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        wordCount->count[i] = 0;
        strcpy(wordCount->word[i], "");
    }
}

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void extractWords(char *text, WordCount *wordCount) {
    char *token;
    char *word = strtok_r(text, " ", &token);
    while (word!= NULL) {
        int index = 0;
        while (index < MAX_WORDS && strcmp(wordCount->word[index], word)!= 0) {
            index++;
        }
        if (index == MAX_WORDS) {
            printf("Warning: Maximum number of words reached.\n");
        } else {
            strcpy(wordCount->word[index], word);
            wordCount->count[index]++;
        }
        word = strtok_r(NULL, " ", &token);
    }
}

void printWordCount(WordCount *wordCount) {
    qsort(wordCount->word, MAX_WORDS, sizeof(char *), compareWords);
    printf("Word\tCount\n");
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (wordCount->count[i] > 0) {
            printf("%s\t%d\n", wordCount->word[i], wordCount->count[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    char *text = NULL;
    size_t size = 0;
    if (getline(&text, &size, file) == -1) {
        printf("Error: Unable to read file.\n");
        return 1;
    }
    WordCount wordCount;
    initializeWordCount(&wordCount);
    extractWords(text, &wordCount);
    printWordCount(&wordCount);
    free(text);
    fclose(file);
    return 0;
}
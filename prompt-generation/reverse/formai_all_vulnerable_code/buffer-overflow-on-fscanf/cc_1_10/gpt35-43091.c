//FormAI DATASET v1.0 Category: Word Count Tool ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 30
#define INITIAL_CAPACITY 10

typedef struct {
    char* word;
    int count;
} WordCount;

typedef struct {
    int capacity;
    int size;
    WordCount* wordCounts;
} WordCountList;

void initializeList(WordCountList* list) {
    list->capacity = INITIAL_CAPACITY;
    list->size = 0;
    list->wordCounts = (WordCount*) malloc(list->capacity * sizeof(WordCount));
}

void resizeList(WordCountList* list) {
    list->capacity *= 2;
    list->wordCounts = (WordCount*) realloc(list->wordCounts, list->capacity * sizeof(WordCount));
}

void addWord(WordCountList* list, char* word) {
    int i;
    for (i = 0; i < list->size; i++) {
        if (strcmp(list->wordCounts[i].word, word) == 0) {
            list->wordCounts[i].count++;
            return;
        }
    }

    if (list->size == list->capacity) {
        resizeList(list);
    }

    WordCount newWordCount;
    newWordCount.word = (char*) malloc(MAX_WORD_LENGTH * sizeof(char));
    strcpy(newWordCount.word, word);
    newWordCount.count = 1;

    list->wordCounts[list->size] = newWordCount;
    list->size++;
}

void printWordCountList(WordCountList* list) {
    int i;
    for (i = 0; i < list->size; i++) {
        printf("%s: %d\n", list->wordCounts[i].word, list->wordCounts[i].count);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error reading file %s\n", argv[1]);
        return 1;
    }

    WordCountList wordCounts;
    initializeList(&wordCounts);

    char currentWord[MAX_WORD_LENGTH];
    while (fscanf(inputFile, "%s", currentWord) != EOF) {
        addWord(&wordCounts, currentWord);
    }

    fclose(inputFile);

    printWordCountList(&wordCounts);

    return 0;
}
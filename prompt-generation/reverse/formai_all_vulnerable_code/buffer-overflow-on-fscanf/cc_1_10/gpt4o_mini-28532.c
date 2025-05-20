//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INITIAL_CAPACITY 10
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordFrequency;

typedef struct {
    WordFrequency *array;
    int size;
    int capacity;
} WordCountList;

void initializeList(WordCountList *list) {
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    list->array = malloc(sizeof(WordFrequency) * list->capacity);
}

void addWord(WordCountList *list, const char *word) {
    for (int i = 0; i < list->size; i++) {
        if (strcasecmp(list->array[i].word, word) == 0) {
            list->array[i].count++;
            return;
        }
    }
    
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->array = realloc(list->array, sizeof(WordFrequency) * list->capacity);
    }

    list->array[list->size].word = strdup(word);
    list->array[list->size].count = 1;
    list->size++;
}

void freeList(WordCountList *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->array[i].word);
    }
    free(list->array);
}

void printWordFrequencies(WordCountList *list) {
    printf("Word Frequencies:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%s: %d\n", list->array[i].word, list->array[i].count);
    }
}

void cleanWord(char *word) {
    char *src = word, *dst = word;
    while (*src) {
        if (isalpha(*src)) {
            *dst++ = tolower(*src);
        }
        src++;
    }
    *dst = '\0';
}

void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    WordCountList wordList;
    initializeList(&wordList);

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        cleanWord(word);
        if (strlen(word) > 0) {
            addWord(&wordList, word);
        }
    }

    fclose(file);
    printWordFrequencies(&wordList);
    freeList(&wordList);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    processFile(argv[1]);

    return EXIT_SUCCESS;
}
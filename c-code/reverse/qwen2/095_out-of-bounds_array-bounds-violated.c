#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define INITIAL_CAPACITY 10

typedef struct {
    char *word;
    int count;
} WordFreq;

void addWord(WordFreq **words, int *size, int *capacity, const char *word) {
    if (*size == *capacity) {
        *capacity *= 2;
        *words = realloc(*words, *capacity * sizeof(WordFreq));
    }
    (*words)[*size].word = strdup(word);
    (*words)[*size].count = 1;
    (*size)++;
}

int findWord(WordFreq *words, int size, const char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void freeWords(WordFreq *words, int size) {
    for (int i = 0; i < size; i++) {
        free(words[i].word);
    }
    free(words);
}

int main() {
    FILE *file;
    char filename[100];
    char word[MAX_WORD_LENGTH];
    WordFreq *words = NULL;
    int size = 0, capacity = INITIAL_CAPACITY;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fscanf(file, "%s", word) != EOF) {
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        word[strcspn(word, ",.!?;:\'\"]")] = '\0';
        int index = findWord(words, size, word);
        if (index != -1) {
            words[index].count++;
        } else {
            addWord(&words, &size, &capacity, word);
        }
    }

    fclose(file);

    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    freeWords(words, size);

    return EXIT_SUCCESS;
}

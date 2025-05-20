//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_WORDS 50

typedef struct {
    char word[MAX_LENGTH];
} Word;

void swap(Word* a, Word* b) {
    Word temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void* a, const void* b) {
    return strcmp(((Word*)a)->word, ((Word*)b)->word);
}

void printWords(Word* words, int count) {
    printf("Sorted Words:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i].word);
    }
}

void readWordsFromFile(const char* filename, Word* words, int* count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (fscanf(file, "%s", words[*count].word) != EOF && *count < MAX_WORDS) {
        (*count)++;
    }

    fclose(file);
}

void sortWords(Word* words, int count) {
    qsort(words, count, sizeof(Word), compare);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Word words[MAX_WORDS];
    int count = 0;

    readWordsFromFile(argv[1], words, &count);
    
    printf("Read %d words from file: %s\n", count, argv[1]);

    sortWords(words, count);
    printWords(words, count);

    return EXIT_SUCCESS;
}
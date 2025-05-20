//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

struct word_entry {
    char * word;
    int frequency;
};

typedef struct word_entry WordEntry;

int compare_entries(const void * a, const void * b) {
    const WordEntry * ea = *(const WordEntry **)a;
    const WordEntry * eb = *(const WordEntry **)b;
    return eb->frequency - ea->frequency;
}

int main(int argc, char *argv[]) {
    FILE * file;
    char * buffer;
    char * word;
    int i, j, k, n;
    int capacity = 10;
    int size = 0;
    WordEntry ** entries;

    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    buffer = (char*) malloc(MAX_WORD_LENGTH);
    entries = (WordEntry**) malloc(sizeof(WordEntry*) * capacity);

    while (fscanf(file, "%s", buffer) == 1) {
        for (i = 0; buffer[i] != '\0'; i++) {
            if (!isalpha(buffer[i]))
                break;
            buffer[i] = tolower(buffer[i]);
        }
        buffer[i] = '\0';

        for (i = 0; i < size; i++) {
            if (strcmp(entries[i]->word, buffer) == 0) {
                entries[i]->frequency++;
                break;
            }
        }
        if (i == size) {
            if (size == capacity) {
                WordEntry ** new_entries = (WordEntry**) malloc(sizeof(WordEntry*) * capacity * 2);
                memcpy(new_entries, entries, sizeof(WordEntry*) * capacity);
                free(entries);
                entries = new_entries;
                capacity *= 2;
            }
            entries[size] = (WordEntry*) malloc(sizeof(WordEntry));
            entries[size]->word = strdup(buffer);
            entries[size]->frequency = 1;
            size++;
        }
    }

    qsort(entries, size, sizeof(WordEntry*), compare_entries);

    for (i = 0; i < size; i++) {
        printf("%s: %d\n", entries[i]->word, entries[i]->frequency);
    }

    fclose(file);
    for (i = 0; i < size; i++) {
        free(entries[i]->word);
        free(entries[i]);
    }
    free(entries);
    free(buffer);

    return 0;
}
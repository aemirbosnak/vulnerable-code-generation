//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000
#define MAX_INDEX_SIZE 10000

typedef struct {
    char *word;
    int index;
} WordIndex;

typedef struct {
    char *filename;
    int numWords;
    WordIndex *index;
} Index;

void createIndex(Index *index, char *filename) {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    index->filename = filename;
    index->numWords = 0;
    index->index = (WordIndex*) malloc(MAX_INDEX_SIZE * sizeof(WordIndex));

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_NUM_WORDS) {
            printf("Error: Too many words in file %s\n", filename);
            exit(1);
        }
        index->index[i].word = (char*) malloc(strlen(word) + 1);
        strcpy(index->index[i].word, word);
        index->index[i].index = i;
        i++;
        index->numWords++;
    }

    fclose(file);
}

void searchIndex(Index *index, char *word) {
    int i;

    for (i = 0; i < index->numWords; i++) {
        if (strcmp(index->index[i].word, word) == 0) {
            printf("Found %s in file %s at index %d\n", word, index->filename, index->index[i].index);
            return;
        }
    }

    printf("Not found %s in file %s\n", word, index->filename);
}

int main() {
    Index index;
    char filename[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);

    createIndex(&index, filename);

    while (1) {
        printf("Enter word to search (or type 'exit'): ");
        scanf("%s", word);

        if (strcmp(word, "exit") == 0) {
            break;
        }

        searchIndex(&index, word);
    }

    return 0;
}
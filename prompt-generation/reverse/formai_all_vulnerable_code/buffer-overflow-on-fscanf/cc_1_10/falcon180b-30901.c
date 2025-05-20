//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MAX_INDEX_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

typedef struct {
    Word words[MAX_WORDS];
    int num_words;
} Index;

void read_file(FILE *file, Index *index) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }
        strcpy(index->words[i].word, word);
        index->words[i].count = 1;
        i++;
    }
    index->num_words = i;
}

void create_index(Index *index) {
    int i, j;
    for (i = 0; i < index->num_words; i++) {
        for (j = 0; j < i; j++) {
            if (strcmp(index->words[i].word, index->words[j].word) == 0) {
                index->words[i].count += index->words[j].count;
                index->words[j] = index->words[--index->num_words];
                break;
            }
        }
    }
}

void search_index(Index *index, char *query) {
    int i, j;
    for (i = 0; i < index->num_words; i++) {
        if (strcmp(query, index->words[i].word) == 0) {
            printf("Found %s: %d times\n", index->words[i].word, index->words[i].count);
            return;
        }
    }
    printf("Not found\n");
}

int main() {
    FILE *file;
    Index index;

    file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    read_file(file, &index);
    fclose(file);

    create_index(&index);

    char query[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a query: ");
        fgets(query, MAX_WORD_LENGTH, stdin);
        search_index(&index, query);
        printf("\n");
    }

    return 0;
}
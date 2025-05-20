//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordCount;

typedef struct {
    WordCount *words;
    int num_words;
} WordIndex;

void create_index(FILE *file, WordIndex *index) {
    char word[MAX_WORD_LENGTH + 1];
    int i, j;

    index->words = (WordCount *) malloc(MAX_WORDS * sizeof(WordCount));
    index->num_words = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        for (i = 0; i < index->num_words; i++) {
            if (strcmp(index->words[i].word, word) == 0) {
                index->words[i].count++;
                break;
            }
        }

        if (i == index->num_words) {
            index->words[index->num_words].word[0] = word[0];
            index->words[index->num_words].count = 1;
            index->num_words++;
        }
    }
}

void print_index(WordIndex *index) {
    int i;

    for (i = 0; i < index->num_words; i++) {
        printf("%s %d\n", index->words[i].word, index->words[i].count);
    }
}

void search_index(WordIndex *index, char *query) {
    int i;
    char query_word[MAX_WORD_LENGTH + 1];

    strcpy(query_word, query);
    for (i = 0; i < strlen(query_word); i++) {
        query_word[i] = tolower(query_word[i]);
    }

    for (i = 0; i < index->num_words; i++) {
        if (strcmp(index->words[i].word, query_word) == 0) {
            printf("%s %d\n", index->words[i].word, index->words[i].count);
        }
    }
}

int main() {
    FILE *file;
    WordIndex index;

    file = fopen("example.txt", "r");
    create_index(file, &index);
    fclose(file);

    print_index(&index);

    search_index(&index, "example");

    return 0;
}
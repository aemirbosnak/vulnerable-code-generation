//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_SIZE 50
#define MAX_NUM_WORDS 1000
#define MAX_INDEX_SIZE 5000

typedef struct {
    char word[MAX_WORD_SIZE];
    int index;
} Word;

typedef struct {
    Word words[MAX_NUM_WORDS];
    int numWords;
} Index;

void createIndex(Index *index) {
    index->numWords = 0;
}

void addWord(Index *index, char *word) {
    if (index->numWords >= MAX_NUM_WORDS) {
        printf("Error: Index is full.\n");
        return;
    }

    Word newWord;
    strcpy(newWord.word, word);
    newWord.index = index->numWords;

    index->words[index->numWords++] = newWord;
}

void searchIndex(Index *index, char *query) {
    int i;
    for (i = 0; i < index->numWords; i++) {
        if (strcasecmp(index->words[i].word, query) == 0) {
            printf("Index: %d\n", index->words[i].index);
            return;
        }
    }

    printf("Not found.\n");
}

int main() {
    Index index;
    createIndex(&index);

    char word[MAX_WORD_SIZE];
    int i;

    for (i = 0; i < MAX_NUM_WORDS; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", word);
        addWord(&index, word);
    }

    char query[MAX_WORD_SIZE];
    printf("Enter query: ");
    scanf("%s", query);

    searchIndex(&index, query);

    return 0;
}
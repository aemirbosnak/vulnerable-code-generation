//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int length;
} Word;

int compareWords(const void *a, const void *b) {
    const Word *wordA = a;
    const Word *wordB = b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    Word words[MAX_WORDS];
    int numWords = 0;
    int i, j;

    file = fopen("romeo_and_juliet.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached\n");
            exit(1);
        }

        words[numWords].word = strdup(word);
        words[numWords].length = strlen(word);
        numWords++;
    }

    fclose(file);

    qsort(words, numWords, sizeof(Word), compareWords);

    for (i = 0; i < numWords; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }

    return 0;
}
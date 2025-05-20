//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 20

typedef struct {
    char word[WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;

    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char *argv[]) {
    char input[MAX_WORDS][WORD_LENGTH];
    int numWords = 0;
    char word[WORD_LENGTH];
    char *token;
    FILE *file;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            fprintf(stderr, "Maximum number of words exceeded.\n");
            exit(1);
        }

        strcpy(input[numWords], word);
        numWords++;
    }

    fclose(file);

    qsort(input, numWords, sizeof(char *), compareWords);

    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", input[i], 1);
    }

    return 0;
}
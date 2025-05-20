//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int index;
} Word;

void loadWords(char *filename, Word words[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    int numWords = 0;
    while (fscanf(file, "%s", words[numWords].word)!= EOF) {
        numWords++;
        if (numWords == MAX_WORDS) {
            fprintf(stderr, "Error: Too many words in file '%s'\n", filename);
            exit(1);
        }
    }

    fclose(file);
}

void searchWords(char *filename, char *searchTerm, Word words[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    int numWords = 0;
    while (fscanf(file, "%s", words[numWords].word)!= EOF) {
        numWords++;
        if (numWords == MAX_WORDS) {
            fprintf(stderr, "Error: Too many words in file '%s'\n", filename);
            exit(1);
        }
    }

    fclose(file);

    int i, j;
    for (i = 0; i < numWords; i++) {
        int k = 0;
        while (k < strlen(words[i].word) && tolower(words[i].word[k]) == tolower(searchTerm[k])) {
            k++;
        }
        if (k == strlen(searchTerm)) {
            printf("%s\n", words[i].word);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <filename> <search_term>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    char *searchTerm = argv[2];

    Word words[MAX_WORDS];
    loadWords(filename, words);

    searchWords(filename, searchTerm, words);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50
#define EBOOK_FILE "ebook.txt"

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    WordFrequency* wordA = (WordFrequency*)a;
    WordFrequency* wordB = (WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE* ebookFile = fopen(EBOOK_FILE, "r");
    if (ebookFile == NULL) {
        printf("Error: could not open ebook file.\n");
        exit(1);
    }

    char ebookContent[MAX_WORDS][MAX_WORD_LENGTH];
    int ebookContentIndex = 0;

    char word[MAX_WORD_LENGTH];
    int wordIndex = 0;
    while (fscanf(ebookFile, "%s", word)!= EOF) {
        strcpy(ebookContent[ebookContentIndex], word);
        ebookContentIndex++;

        if (ebookContentIndex == MAX_WORDS) {
            printf("Error: ebook content too long.\n");
            exit(1);
        }
    }

    fclose(ebookFile);

    qsort(ebookContent, ebookContentIndex, sizeof(char*), compareWords);

    printf("Ebook content:\n");
    for (int i = 0; i < ebookContentIndex; i++) {
        printf("%s\n", ebookContent[i]);
    }

    return 0;
}
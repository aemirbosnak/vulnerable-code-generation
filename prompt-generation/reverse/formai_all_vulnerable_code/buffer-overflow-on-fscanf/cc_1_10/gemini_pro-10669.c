//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LEN 50

typedef struct {
    char word[MAX_LEN + 1];
    int count;
} Word;

int compare_words(const void *a, const void *b) {
    Word *wa = (Word *)a;
    Word *wb = (Word *)b;

    return strcmp(wa->word, wb->word);
}

void sort_words(Word *words, int n) {
    qsort(words, n, sizeof(Word), compare_words);
}

int main() {
    FILE *fp;
    char word[MAX_LEN + 1];
    Word words[MAX_WORDS];
    int n = 0;

    fp = fopen("text.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fscanf(fp, "%s", word) != EOF) {
        if (n >= MAX_WORDS) {
            printf("Error: Too many words in text file\n");
            return EXIT_FAILURE;
        }

        strcpy(words[n].word, word);
        words[n].count = 1;

        n++;
    }

    fclose(fp);

    sort_words(words, n);

    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return EXIT_SUCCESS;
}
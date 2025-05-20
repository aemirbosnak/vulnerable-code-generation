//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compare_words(const void *a, const void *b) {
    return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    Word words[MAX_WORDS];
    int num_words = 0;

    char buf[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", buf) != EOF) {
        int found = 0;

        for (int i = 0; i < num_words; i++) {
            if (strcmp(words[i].word, buf) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[num_words].word, buf);
            words[num_words].count = 1;
            num_words++;
        }
    }

    fclose(fp);

    qsort(words, num_words, sizeof(Word), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
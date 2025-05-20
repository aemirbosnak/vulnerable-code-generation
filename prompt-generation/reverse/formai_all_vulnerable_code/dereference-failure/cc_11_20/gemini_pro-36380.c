//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

typedef struct {
    char *word;
    int count;
} word_count;

int compare_word_counts(const void *a, const void *b) {
    const word_count *wc1 = (const word_count *)a;
    const word_count *wc2 = (const word_count *)b;

    return wc2->count - wc1->count; // descending order
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    char *buffer = malloc(100000);
    if (buffer == NULL) {
        perror("malloc");
        exit(1);
    }

    size_t len = fread(buffer, 1, 100000, fp);
    fclose(fp);

    char *words[MAX_WORDS];
    int counts[MAX_WORDS];

    int num_words = 0;
    char *ptr = buffer;
    while (*ptr != '\0' && num_words < MAX_WORDS) {
        while (*ptr == ' ' || *ptr == '\n' || *ptr == '\t') {
            ptr++;
        }

        if (*ptr == '\0') {
            break;
        }

        char *start = ptr;
        while (*ptr != ' ' && *ptr != '\n' && *ptr != '\t' && *ptr != '\0') {
            ptr++;
        }

        int len = ptr - start;
        if (len > MAX_WORD_LEN) {
            continue; // ignore words that are too long
        }

        char *word = malloc(len + 1);
        if (word == NULL) {
            perror("malloc");
            exit(1);
        }

        memcpy(word, start, len);
        word[len] = '\0';

        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, words[i]) == 0) {
                counts[i]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            words[num_words] = word;
            counts[num_words] = 1;
            num_words++;
        }
    }

    free(buffer);

    word_count word_counts[MAX_WORDS];
    for (int i = 0; i < num_words; i++) {
        word_counts[i].word = words[i];
        word_counts[i].count = counts[i];
    }

    qsort(word_counts, num_words, sizeof(word_count), compare_word_counts);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}
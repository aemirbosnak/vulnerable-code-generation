//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 256

typedef struct {
    char *word;
    int count;
} word_count_t;

int compare_word_counts(const void *a, const void *b) {
    const word_count_t *wa = (const word_count_t *)a;
    const word_count_t *wb = (const word_count_t *)b;

    return wb->count - wa->count;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char buffer[MAX_WORD_LEN];
    word_count_t word_counts[MAX_WORDS];
    int num_words = 0;

    while (fscanf(fp, "%s", buffer) != EOF) {
        int found = 0;

        for (int i = 0; i < num_words; i++) {
            if (strcmp(buffer, word_counts[i].word) == 0) {
                word_counts[i].count++;
                found = 1;
                break;
            }
        }

        if (!found && num_words < MAX_WORDS) {
            word_counts[num_words].word = strdup(buffer);
            word_counts[num_words].count = 1;
            num_words++;
        }
    }

    fclose(fp);

    qsort(word_counts, num_words, sizeof(word_count_t), compare_word_counts);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        free(word_counts[i].word);
    }

    return EXIT_SUCCESS;
}
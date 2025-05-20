//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: real-life
/*
 * Word Frequency Counter
 *
 * This program counts the frequency of each word in a given input file.
 * The output is sorted in descending order of frequency.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    const struct word_count *wc1 = a;
    const struct word_count *wc2 = b;
    return wc2->count - wc1->count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    struct word_count *word_counts = NULL;
    int num_words = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(fp, "%s", word) == 1) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == num_words) {
            struct word_count *new_word_counts = realloc(word_counts, (num_words + 1) * sizeof(struct word_count));
            if (!new_word_counts) {
                printf("Error: could not reallocate memory\n");
                return 1;
            }
            word_counts = new_word_counts;
            strcpy(word_counts[num_words].word, word);
            word_counts[num_words].count = 1;
            num_words++;
        }
    }

    qsort(word_counts, num_words, sizeof(struct word_count), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);

    return 0;
}
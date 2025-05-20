//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} word_count_pair;

int compare_word_count_pairs(const void *a, const void *b) {
    const word_count_pair *pair1 = (const word_count_pair *)a;
    const word_count_pair *pair2 = (const word_count_pair *)b;

    return pair2->count - pair1->count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char buffer[MAX_WORD_LENGTH];
    int num_words = 0;
    word_count_pair word_count_pairs[MAX_WORDS];

    while (fscanf(input_file, "%s", buffer) != EOF) {
        if (num_words >= MAX_WORDS) {
            fprintf(stderr, "Error: Too many words in input file.\n");
            return EXIT_FAILURE;
        }

        char *word = strdup(buffer);
        int count = 1;

        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, word_count_pairs[i].word) == 0) {
                word_count_pairs[i].count++;
                count = 0;
                break;
            }
        }

        if (count) {
            word_count_pairs[num_words].word = word;
            word_count_pairs[num_words].count = 1;
            num_words++;
        }
    }

    fclose(input_file);

    qsort(word_count_pairs, num_words, sizeof(word_count_pair), compare_word_count_pairs);

    printf("Word Frequency Count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_count_pairs[i].word, word_count_pairs[i].count);
    }

    return EXIT_SUCCESS;
}
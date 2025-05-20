//FormAI DATASET v1.0 Category: Text processing ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} word_count;

int compare_word_counts(const void *a, const void *b) {
    const word_count *word_count_a = (const word_count *) a;
    const word_count *word_count_b = (const word_count *) b;
    return word_count_b->frequency - word_count_a->frequency;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }
    const char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return 1;
    }
    word_count word_counts[MAX_NUM_WORDS];
    int num_words = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        int length = strlen(word);
        if (length >= MAX_WORD_LENGTH) {
            fprintf(stderr, "Warning: word \"%s\" is too long and will be skipped\n",
                word);
            continue;
        }
        for (int i = 0; i < length; ++i) {
            word[i] = tolower(word[i]);
        }
        int i;
        for (i = 0; i < num_words; ++i) {
            if (strcmp(word_counts[i].word, word) == 0) {
                word_counts[i].frequency++;
                break;
            }
        }
        if (i == num_words) {
            if (num_words >= MAX_NUM_WORDS) {
                fprintf(stderr, "Error: too many unique words, increase MAX_NUM_WORDS\n");
                return 1;
            }
            strcpy(word_counts[num_words].word, word);
            word_counts[num_words].frequency = 1;
            num_words++;
        }
    }
    fclose(file);
    qsort(word_counts, num_words, sizeof(word_count), compare_word_counts);
    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < num_words; ++i) {
        printf("%d %s\n", word_counts[i].frequency, word_counts[i].word);
    }
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_WORD_LEN 64

typedef struct {
    char *word;
    int count;
} WordCount;

int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

char *get_word(char *line) {
    char *word = NULL;
    char *start = line;
    while (*start && isspace(*start)) start++;
    word = start;
    while (*start &&!isspace(*start)) start++;
    if (start - word > MAX_WORD_LEN - 1) {
        printf("Error: Word too long.\n");
        exit(1);
    }
    *start = '\0';
    return word;
}

void count_words(char *filename, int num_words, WordCount **word_counts) {
    FILE *file;
    char line[MAX_LINE_LEN];
    char *word;
    int i;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }

    word_counts[0] = malloc(num_words * sizeof(WordCount));
    for (i = 0; i < num_words; i++) {
        word_counts[i]->word = malloc(MAX_WORD_LEN * sizeof(char));
        word_counts[i]->count = 0;
    }

    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        word = get_word(line);
        if (word == NULL) continue;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, word_counts[i]->word) == 0) {
                word_counts[i]->count++;
                break;
            }
        }
        if (i == num_words) {
            printf("Error: Too many words.\n");
            exit(1);
        }
    }

    fclose(file);
    qsort(word_counts[0], num_words, sizeof(WordCount), compare_strings);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i]->word, word_counts[i]->count);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s filename [num_words]\n", argv[0]);
        return 1;
    }

    int num_words = 10;
    if (argc > 2) num_words = atoi(argv[2]);

    WordCount **word_counts = malloc(num_words * sizeof(WordCount *));
    for (int i = 0; i < num_words; i++) {
        word_counts[i] = malloc(sizeof(WordCount));
        word_counts[i]->word = malloc(MAX_WORD_LEN * sizeof(char));
        word_counts[i]->count = 0;
    }

    count_words(argv[1], num_words, word_counts);

    for (int i = 0; i < num_words; i++) {
        free(word_counts[i]->word);
        free(word_counts[i]);
    }
    free(word_counts);

    return 0;
}
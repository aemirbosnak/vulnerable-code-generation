//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} word_count_t;

void read_words_from_file(FILE *file, word_count_t *word_counts, int count) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (count >= MAX_WORD_COUNT) {
            break;
        }
        word_count_t *word_count = &word_counts[count];
        strcpy(word_count->word, word);
        word_count->count = 1;
        count++;
    }
}

void print_word_counts(word_count_t *word_counts, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    word_count_t word_counts[MAX_WORD_COUNT];
    int count = 0;

    read_words_from_file(file, word_counts, count);

    fclose(file);

    print_word_counts(word_counts, count);

    return 0;
}
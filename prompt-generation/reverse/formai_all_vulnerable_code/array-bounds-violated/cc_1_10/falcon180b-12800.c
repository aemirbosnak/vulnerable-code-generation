//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define WORD_LENGTH 100

struct word_count {
    char word[WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    struct word_count *word_a = (struct word_count *)a;
    struct word_count *word_b = (struct word_count *)b;

    return strcmp(word_a->word, word_b->word);
}

void count_words(FILE *file, struct word_count *word_counts, int count) {
    char word[WORD_LENGTH];
    char c;

    while ((c = fgetc(file))!= EOF) {
        if (isalpha(c)) {
            strncat(word, &c, 1);
        } else {
            word[strlen(word) - 1] = '\0';

            if (count >= MAX_WORDS) {
                printf("Reached maximum number of words.\n");
                break;
            }

            struct word_count *found_word = bsearch(word, word_counts, count, sizeof(struct word_count), compare_words);

            if (found_word == NULL) {
                strcpy(word_counts[count].word, word);
                word_counts[count].count = 1;
                count++;
            } else {
                found_word->count++;
            }

            memset(word, 0, WORD_LENGTH);
        }
    }
}

void print_word_counts(struct word_count *word_counts, int count) {
    qsort(word_counts, count, sizeof(struct word_count), compare_words);

    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    struct word_count word_counts[MAX_WORDS];
    int count = 0;

    count_words(file, word_counts, count);

    fclose(file);
    print_word_counts(word_counts, count);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_WORD_COUNT 100000

struct word_count {
    char word[MAX_WORD_LEN];
    int count;
};

int compare_words(const void *a, const void *b) {
    struct word_count *word1 = (struct word_count *)a;
    struct word_count *word2 = (struct word_count *)b;

    return strcmp(word1->word, word2->word);
}

void read_file(FILE *file, struct word_count *word_counts, int *word_count) {
    char ch;
    char word[MAX_WORD_LEN];
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[i] = tolower(ch);
            i++;
        } else {
            word[i] = '\0';
            i = 0;
        }

        if (i == MAX_WORD_LEN) {
            printf("Error: Word is too long.\n");
            exit(1);
        }
    }

    if (i > 0) {
        word[i] = '\0';
        struct word_count key = {.word = word };
        int index = bsearch(&key, word_counts, *word_count, sizeof(struct word_count), compare_words);

        if (index == *word_count) {
            word_counts[*word_count].count++;
        } else {
            word_counts[index].count++;
        }

        (*word_count)++;
    }
}

void print_word_counts(struct word_count *word_counts, int word_count) {
    qsort(word_counts, word_count, sizeof(struct word_count), compare_words);

    for (int i = 0; i < word_count; i++) {
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
        printf("Error: Could not open file.\n");
        return 1;
    }

    struct word_count word_counts[MAX_WORD_COUNT];
    int word_count = 0;

    read_file(file, word_counts, &word_count);

    print_word_counts(word_counts, word_count);

    fclose(file);

    return 0;
}
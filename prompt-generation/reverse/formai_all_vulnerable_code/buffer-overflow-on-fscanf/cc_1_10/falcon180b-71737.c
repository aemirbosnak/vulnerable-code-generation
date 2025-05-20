//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    const struct word_count *wc1 = a;
    const struct word_count *wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

void read_file(const char *filename, struct word_count *word_counts) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char buffer[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int word_length = 0;
    int in_word = 0;

    while (fscanf(file, "%s", buffer)!= EOF) {
        int i;
        for (i = 0; i < strlen(buffer); i++) {
            if (isalpha(buffer[i])) {
                if (!in_word) {
                    in_word = 1;
                    strncpy(word, &buffer[i], MAX_WORD_LENGTH - 1);
                } else {
                    strncat(word, &buffer[i], MAX_WORD_LENGTH - word_length - 1);
                }
                word_length++;
            } else {
                in_word = 0;
                word[word_length] = '\0';
                struct word_count key = {.word = word,.count = 1 };
                struct word_count *result = bsearch(&key, word_counts, MAX_WORDS, sizeof(struct word_count), compare_words);
                if (result == NULL) {
                    if (word_counts[0].count == 0) {
                        memmove(word_counts + 1, word_counts, sizeof(struct word_count) * MAX_WORDS);
                        word_counts[0] = key;
                    } else {
                        printf("Maximum number of unique words exceeded\n");
                    }
                } else {
                    result->count++;
                }
                word_length = 0;
            }
        }
    }

    fclose(file);
}

void print_word_counts(struct word_count *word_counts, int num_words) {
    qsort(word_counts, num_words, sizeof(struct word_count), compare_words);

    printf("Word\tFrequency\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct word_count word_counts[MAX_WORDS];
    read_file(argv[1], word_counts);

    int num_words = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_counts[i].count > 0) {
            num_words++;
        }
    }

    print_word_counts(word_counts, num_words);

    return 0;
}
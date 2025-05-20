//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    const struct word *word_a = a;
    const struct word *word_b = b;

    return strcmp(word_a->word, word_b->word);
}

void print_word_count(const struct word *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
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
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char buffer[MAX_WORD_LENGTH];
    int num_words = 0;

    struct word word_counts[MAX_WORDS];
    memset(word_counts, 0, sizeof(word_counts));

    while (fscanf(file, "%s", buffer)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Too many words in file.\n");
            fclose(file);
            return 1;
        }

        int word_length = strlen(buffer);
        if (word_length > MAX_WORD_LENGTH) {
            printf("Word is too long: %s\n", buffer);
            fclose(file);
            return 1;
        }

        strcpy(word_counts[num_words].word, buffer);
        word_counts[num_words].count = 1;
        num_words++;
    }

    fclose(file);

    qsort(word_counts, num_words, sizeof(struct word), compare_words);

    printf("Word count:\n");
    print_word_count(word_counts, num_words);

    return 0;
}
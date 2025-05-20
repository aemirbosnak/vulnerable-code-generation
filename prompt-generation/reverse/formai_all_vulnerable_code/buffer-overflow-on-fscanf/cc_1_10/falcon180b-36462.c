//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    const struct word_count *wc1 = a;
    const struct word_count *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

void count_words(FILE *file, struct word_count *word_counts, int num_words) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word) == 1) {
        if (i >= num_words) {
            printf("Too many words. Increase MAX_WORDS.\n");
            exit(1);
        }

        strcpy(word_counts[i].word, word);
        word_counts[i].count = 1;

        i++;
    }
}

void print_word_counts(struct word_count *word_counts, int num_words) {
    printf("Word\tCount\n");

    for (int i = 0; i < num_words; i++) {
        if (word_counts[i].count > 0) {
            printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    int num_words;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Enter number of words to count: ");
    scanf("%d", &num_words);

    struct word_count *word_counts = malloc(num_words * sizeof(struct word_count));

    if (word_counts == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    count_words(file, word_counts, num_words);

    qsort(word_counts, num_words, sizeof(struct word_count), compare_words);

    print_word_counts(word_counts, num_words);

    free(word_counts);

    fclose(file);

    return 0;
}
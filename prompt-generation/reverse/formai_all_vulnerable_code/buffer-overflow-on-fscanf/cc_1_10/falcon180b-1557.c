//Falcon-180B DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    const struct word_count *word_a = a;
    const struct word_count *word_b = b;

    return strcmp(word_a->word, word_b->word);
}

void count_words(FILE *file, struct word_count words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: too many words in file.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].count = 1;
        i++;
    }
}

void print_word_counts(struct word_count words[MAX_WORDS], int num_words) {
    qsort(words, num_words, sizeof(struct word_count), compare_words);

    printf("Word count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    struct word_count words[MAX_WORDS];
    int num_words = 0;

    count_words(input_file, words);
    print_word_counts(words, num_words);

    fprintf(output_file, "Total words: %d\n", num_words);

    fclose(input_file);
    fclose(output_file);

    return 0;
}
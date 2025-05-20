//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

struct word_count {
    char word[MAX_WORD_LEN];
    int count;
};

int compare_words(const void *a, const void *b) {
    const struct word_count *wc1 = a;
    const struct word_count *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

void print_word_counts(struct word_count *word_counts, int num_words) {
    qsort(word_counts, num_words, sizeof(struct word_count), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char input_file[100];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    FILE *fp = fopen(input_file, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[1000];
    struct word_count word_counts[MAX_WORDS];
    int num_words = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            int len = strlen(token);
            if (len > MAX_WORD_LEN) {
                len = MAX_WORD_LEN;
            }
            strncpy(word_counts[num_words].word, token, len);
            word_counts[num_words].count = 1;
            num_words++;

            if (num_words >= MAX_WORDS) {
                printf("Reached maximum number of words. Exiting.\n");
                exit(0);
            }

            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(fp);

    print_word_counts(word_counts, num_words);

    return 0;
}
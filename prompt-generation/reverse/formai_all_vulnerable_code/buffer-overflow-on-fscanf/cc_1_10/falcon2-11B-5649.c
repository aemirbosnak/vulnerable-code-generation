//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} word_t;

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("fopen");
        return 1;
    }

    char word[MAX_WORD_LEN];
    word_t words[MAX_WORDS];
    int num_words = 0;

    while (fscanf(input_file, "%s", word)!= EOF) {
        strcpy(words[num_words].word, word);
        words[num_words].count = 1;
        num_words++;
    }

    fclose(input_file);

    word_t *sorted_words = malloc(num_words * sizeof(word_t));
    int num_sorted_words = 0;

    for (int i = 0; i < num_words; i++) {
        if (words[i].count > sorted_words[num_sorted_words].count) {
            strcpy(sorted_words[num_sorted_words].word, words[i].word);
            sorted_words[num_sorted_words].count = words[i].count;
            num_sorted_words++;
        } else if (words[i].count == sorted_words[num_sorted_words].count) {
            strcpy(sorted_words[num_sorted_words].word, words[i].word);
            num_sorted_words++;
        }
    }

    FILE *output_file = fopen("summary.txt", "w");
    if (!output_file) {
        perror("fopen");
        return 1;
    }

    for (int i = 0; i < num_sorted_words; i++) {
        fprintf(output_file, "%s %d\n", sorted_words[i].word, sorted_words[i].count);
    }

    fclose(output_file);

    return 0;
}
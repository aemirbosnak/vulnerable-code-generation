//Falcon-180B DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_t {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *input_file, struct word_t *word_table, int *num_words) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(input_file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }

        strcpy(word_table[i].word, word);
        word_table[i].count = 1;

        i++;
    }

    *num_words = i;
}

void count_words(struct word_t *word_table, int num_words, char *output_file) {
    FILE *output = fopen(output_file, "w");

    if (output == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    for (int i = 0; i < num_words; i++) {
        fprintf(output, "%s: %d\n", word_table[i].word, word_table[i].count);
    }

    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    int num_words = 0;
    struct word_t word_table[MAX_WORDS];

    read_file(input_file, word_table, &num_words);

    fclose(input_file);

    count_words(word_table, num_words, argv[2]);

    return 0;
}
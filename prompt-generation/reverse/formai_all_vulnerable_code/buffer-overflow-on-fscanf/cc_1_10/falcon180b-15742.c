//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE *file, WordCount *word_counts, int num_words) {
    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word_counts[i].word, word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == num_words) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many unique words in file.\n");
                exit(1);
            }
            strcpy(word_counts[num_words].word, word);
            word_counts[num_words].count = 1;
            num_words++;
        }
    }
}

void write_file(FILE *file, WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        fprintf(file, "%s %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    int num_words = 0;
    WordCount word_counts[MAX_WORDS];
    read_file(input_file, word_counts, num_words);

    write_file(output_file, word_counts, num_words);

    fclose(input_file);
    fclose(output_file);

    return 0;
}
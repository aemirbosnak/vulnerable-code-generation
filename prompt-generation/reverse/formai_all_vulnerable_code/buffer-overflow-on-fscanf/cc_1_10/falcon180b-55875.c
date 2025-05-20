//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_input(FILE *input_file, struct word_count *word_counts) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(input_file, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // remove newline character
        if (i < MAX_WORDS) {
            strcpy(word_counts[i].word, word);
            word_counts[i].count = 1;
            i++;
        }
    }
}

void count_words(struct word_count *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(word_counts[i].word, word_counts[j].word) == 0) {
                word_counts[i].count += word_counts[j].count;
                word_counts[j].count = 0;
            }
        }
    }
}

void print_word_counts(struct word_count *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main() {
    FILE *input_file;
    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    struct word_count word_counts[MAX_WORDS];
    read_input(input_file, word_counts);

    count_words(word_counts, MAX_WORDS);

    print_word_counts(word_counts, MAX_WORDS);

    fclose(input_file);

    return 0;
}
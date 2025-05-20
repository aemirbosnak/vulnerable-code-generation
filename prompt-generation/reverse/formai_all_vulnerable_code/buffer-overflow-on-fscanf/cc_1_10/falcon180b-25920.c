//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void add_word(struct word *words, int num_words, char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i].word) == 0) {
            words[i].count++;
            return;
        }
    }
    strcpy(words[num_words].word, word);
    words[num_words].count = 1;
    num_words++;
}

void print_misspelled_words(struct word *words, int num_words, FILE *input_file, FILE *output_file) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(input_file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                fprintf(output_file, "%s: %d\n", word, words[i].count);
                break;
            }
        }
        if (i == num_words) {
            fprintf(output_file, "%s: 0\n", word);
        }
    }
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s input_file output_file dictionary_file\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        exit(1);
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        exit(1);
    }

    FILE *dictionary_file = fopen(argv[3], "r");
    if (dictionary_file == NULL) {
        fprintf(stderr, "Error opening dictionary file: %s\n", argv[3]);
        exit(1);
    }

    struct word words[MAX_WORDS];
    int num_words = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(dictionary_file, "%s", word)!= EOF) {
        add_word(words, num_words, word);
    }

    fclose(dictionary_file);

    while (fscanf(input_file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                fprintf(output_file, "%s\n", word);
                break;
            }
        }
        if (i == num_words) {
            fprintf(output_file, "%s\n", word);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
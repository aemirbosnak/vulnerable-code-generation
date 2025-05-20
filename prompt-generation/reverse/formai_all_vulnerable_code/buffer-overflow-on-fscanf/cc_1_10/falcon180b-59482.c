//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

struct word_t {
    char word[MAX_WORD_LENGTH + 1];
    int count;
};

void load_words(struct word_t words[], const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    int num_words = 0;
    while (fscanf(fp, "%s", words[num_words].word)!= EOF) {
        words[num_words++].count = 0;
    }

    fclose(fp);
}

void spell_check(const char *text, struct word_t words[], int num_words) {
    char word[MAX_WORD_LENGTH + 1];
    int word_length = 0;

    while ((word_length = fscanf(stdin, "%s", word))!= EOF) {
        word[word_length] = '\0';

        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == num_words) {
            printf("Unknown word: %s\n", word);
        }
    }
}

void print_misspelled_words(struct word_t words[], int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (words[i].count == 0) {
            printf("%s\n", words[i].word);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <text_file> <words_file>\n", argv[0]);
        exit(1);
    }

    struct word_t words[MAX_WORDS];
    int num_words = 0;

    load_words(words, argv[2]);

    spell_check(argv[1], words, num_words);

    print_misspelled_words(words, num_words);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 30

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *fp, struct word_count *word_counts, int num_words) {
    char word[MAX_WORD_LENGTH];
    char ch;
    int i = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            word[0] = tolower(ch);
            word[1] = '\0';
            i = 0;
        } else if (i < MAX_WORD_LENGTH - 1) {
            strncat(word, &ch, 1);
            i++;
        } else {
            i = 0;
        }
    }

    if (i > 0) {
        word_counts[num_words - 1].word[i] = '\0';
        word_counts[num_words - 1].count++;
    }
}

void print_word_counts(struct word_count *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    int num_words = 0;
    struct word_count word_counts[MAX_WORDS];

    while (num_words < MAX_WORDS && fscanf(fp, "%s", word_counts[num_words].word)!= EOF) {
        num_words++;
    }

    fclose(fp);

    read_file(fp, word_counts, num_words);

    print_word_counts(word_counts, num_words);

    return 0;
}
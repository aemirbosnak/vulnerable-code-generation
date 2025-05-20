//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100

struct word_count {
    char word[MAX_WORD_LEN];
    int count;
};

void read_file(FILE *fp, struct word_count *word_counts, int count) {
    char ch;
    int i = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            word_counts[i].word[0] = tolower(ch);
            word_counts[i].count = 1;
            i++;
        } else if (isalnum(ch)) {
            strcat(word_counts[i-1].word, tolower(ch));
            word_counts[i-1].count++;
        }
    }
}

void sort_word_counts(struct word_count *word_counts, int count) {
    int i, j;
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (word_counts[j].count > word_counts[i].count) {
                struct word_count temp = word_counts[i];
                word_counts[i] = word_counts[j];
                word_counts[j] = temp;
            }
        }
    }
}

void print_word_counts(struct word_count *word_counts, int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    struct word_count word_counts[100];
    int count = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(1);
    }

    read_file(fp, word_counts, count);
    fclose(fp);

    sort_word_counts(word_counts, count);
    print_word_counts(word_counts, count);

    return 0;
}
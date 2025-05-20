//Falcon-180B DATASET v1.0 Category: Educational ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE *fp, char *filename) {
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            ungetc(ch, fp);
            fscanf(fp, "%s", filename);
        }
    }
}

void count_words(FILE *fp, WordCount words[]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            ungetc(ch, fp);
            fscanf(fp, "%s", words[i].word);
            i++;
            if (i >= MAX_WORDS) {
                break;
            }
        }
    }
}

void print_word_counts(WordCount words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    WordCount words[MAX_WORDS];
    int num_words = 0;

    read_file(fp, argv[1]);
    count_words(fp, words);

    for (int i = 0; i < num_words; i++) {
        words[i].count++;
    }

    print_word_counts(words, num_words);

    fclose(fp);
    return 0;
}
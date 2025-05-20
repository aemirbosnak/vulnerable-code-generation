//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct word_count word_list[MAX_WORDS];
int num_words = 0;

void add_word(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word_list[i].word, word) == 0) {
            word_list[i].count++;
            return;
        }
    }
    if (num_words >= MAX_WORDS) {
        printf("Error: Maximum number of words reached\n");
        exit(1);
    }
    strcpy(word_list[num_words].word, word);
    word_list[num_words].count = 1;
    num_words++;
}

void print_word_counts() {
    int i;
    printf("Word\tCount\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_list[i].word, word_list[i].count);
    }
}

int main(int argc, char *argv[]) {
    int i;
    char word[MAX_WORD_LENGTH];
    FILE *fp;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        add_word(word);
    }

    fclose(fp);
    print_word_counts();

    return 0;
}
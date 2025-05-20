//Falcon-180B DATASET v1.0 Category: Data mining ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

struct word_freq {
    char word[MAX_WORD_LENGTH];
    int freq;
};

struct word_freq *build_word_freq_table(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    struct word_freq *table = (struct word_freq *)malloc(sizeof(struct word_freq) * MAX_WORDS);
    int num_words = 0;

    char word[MAX_WORD_LENGTH] = {0};
    while (fscanf(fp, "%s", word)!= EOF) {
        struct word_freq *curr_word = &table[num_words];
        strcpy(curr_word->word, word);
        curr_word->freq = 1;
        num_words++;

        if (num_words == MAX_WORDS) {
            printf("Error: Reached maximum number of words\n");
            exit(1);
        }
    }

    fclose(fp);
    return table;
}

void print_word_freq_table(struct word_freq *table, int num_words) {
    printf("Word\tFrequency\n");

    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", table[i].word, table[i].freq);
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage:./program <filename>\n");
        return 1;
    }

    char *filename = argv[1];
    struct word_freq *table = build_word_freq_table(filename);
    int num_words = 0;

    while (table[num_words].word[0]!= '\0') {
        num_words++;
    }

    print_word_freq_table(table, num_words);

    return 0;
}
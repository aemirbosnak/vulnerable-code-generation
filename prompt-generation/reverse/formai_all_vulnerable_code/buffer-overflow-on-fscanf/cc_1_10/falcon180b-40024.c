//Falcon-180B DATASET v1.0 Category: Data mining ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_words(char *filename, WordCount *word_counts, int num_words) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word_counts[i].word, word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == num_words) {
            strcpy(word_counts[num_words].word, word);
            word_counts[num_words].count = 1;
            num_words++;
        }
    }

    fclose(fp);
}

void print_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    read_words(argv[1], word_counts, num_words);
    print_word_counts(word_counts, num_words);

    return 0;
}
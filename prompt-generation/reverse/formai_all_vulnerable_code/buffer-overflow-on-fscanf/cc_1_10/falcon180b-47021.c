//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *fp, WordCount *word_counts, int num_word_counts) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        if (i >= num_word_counts) {
            printf("Error: too many words in file.\n");
            exit(1);
        }
        word_counts[i].word[0] = tolower(word[0]);
        strcpy(word_counts[i].word + 1, word + 1);
        word_counts[i++].count = 1;
    }
}

void print_word_counts(WordCount *word_counts, int num_word_counts) {
    for (int i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *fp;
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    WordCount word_counts[MAX_WORDS];
    int num_word_counts = 0;
    read_file(fp, word_counts, MAX_WORDS);
    fclose(fp);
    print_word_counts(word_counts, num_word_counts);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    int count;
    char *word;
} WordCount;

int main() {
    FILE *fp;
    char line[MAX_WORD_LEN];
    char *word;
    WordCount *word_counts = (WordCount*) malloc(MAX_WORDS * sizeof(WordCount));

    int num_words = 0;
    int total_words = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        total_words += count_words(line, word_counts, &num_words);
    }

    fclose(fp);

    printf("Total words: %d\n", total_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);
    return 0;
}

int count_words(char *line, WordCount *word_counts, int *num_words) {
    char *word = strtok(line, " ");
    while (word!= NULL) {
        int index = find_word(word, word_counts, *num_words);
        if (index == -1) {
            index = *num_words;
            (*num_words)++;
            word_counts[index].word = strdup(word);
            word_counts[index].count = 1;
        } else {
            word_counts[index].count++;
        }
        word = strtok(NULL, " ");
    }
    return *num_words;
}

int find_word(char *word, WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word_counts[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}
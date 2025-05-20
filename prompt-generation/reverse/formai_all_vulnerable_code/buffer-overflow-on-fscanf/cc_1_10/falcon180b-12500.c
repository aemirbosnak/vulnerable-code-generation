//Falcon-180B DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char *word;
    int count;
};

void read_file(FILE *fp, struct word_count *word_counts, int *num_words) {
    char word[MAX_WORD_LENGTH];
    int word_length;
    char *token;

    while (fscanf(fp, "%s", word)!= EOF) {
        word_length = strlen(word);
        if (word_length > MAX_WORD_LENGTH) {
            printf("Error: Word '%s' exceeds maximum length of %d characters.\n", word, MAX_WORD_LENGTH);
            exit(1);
        }
        token = strtok(word, ",.?!;:");
        while (token!= NULL) {
            int i;
            for (i = 0; i < *num_words; i++) {
                if (strcmp(word_counts[i].word, token) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == *num_words) {
                if (*num_words >= MAX_WORDS) {
                    printf("Error: Maximum number of words (%d) exceeded.\n", MAX_WORDS);
                    exit(1);
                }
                word_counts[*num_words].word = strdup(token);
                word_counts[*num_words].count = 1;
                (*num_words)++;
            }
            token = strtok(NULL, ",.?!;:");
        }
    }
}

void print_word_counts(int num_words, struct word_count *word_counts) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    struct word_count word_counts[MAX_WORDS];
    int num_words = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    read_file(fp, word_counts, &num_words);
    fclose(fp);

    print_word_counts(num_words, word_counts);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_LEN 20

typedef struct {
    char word[WORD_LEN];
    int count;
} Word;

void read_words(Word *words, int n) {
    FILE *fp;
    char line[WORD_LEN];

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: input file not found\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%s", words[i].word);
        words[i].count = 0;
    }

    fclose(fp);
}

void count_words(Word *words, int n) {
    char *line;
    char *token;

    line = malloc(sizeof(char) * (MAX_WORDS * WORD_LEN));
    if (line == NULL) {
        printf("Error: memory allocation failed\n");
        exit(1);
    }

    while (fgets(line, MAX_WORDS * WORD_LEN, stdin)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            for (int i = 0; i < n; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            token = strtok(NULL, " ");
        }
    }

    free(line);
}

void print_word_counts(Word *words, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    Word words[MAX_WORDS];
    int n;

    printf("Enter the number of words to count: ");
    scanf("%d", &n);

    read_words(words, n);
    count_words(words, n);
    print_word_counts(words, n);

    return 0;
}
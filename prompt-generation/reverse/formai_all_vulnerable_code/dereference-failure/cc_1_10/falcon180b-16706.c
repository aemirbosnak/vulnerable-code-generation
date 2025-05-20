//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

struct word_t {
    char *word;
    int count;
};

struct word_t words[MAX_WORDS];
int num_words = 0;

void add_word(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i].word) == 0) {
            words[i].count++;
            return;
        }
    }
    if (num_words >= MAX_WORDS) {
        printf("Error: Too many words!\n");
        exit(1);
    }
    words[num_words].word = strdup(word);
    words[num_words].count = 1;
    num_words++;
}

int main(int argc, char **argv) {
    char *text = NULL;
    size_t len = 0;
    char *line = NULL;
    size_t line_len = 0;
    FILE *fp;
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s!\n", argv[1]);
        return 1;
    }

    while ((getline(&line, &line_len, fp))!= -1) {
        text = realloc(text, len + line_len + 1);
        strcat(text, line);
        len += line_len;
    }

    fclose(fp);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    free(text);
    return 0;
}
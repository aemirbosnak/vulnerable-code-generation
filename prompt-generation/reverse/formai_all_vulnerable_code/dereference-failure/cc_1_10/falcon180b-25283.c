//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 100000

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words = 0;

void add_word(char *word) {
    if (num_words >= MAX_WORDS) {
        printf("Error: Too many words!\n");
        exit(1);
    }
    strcpy(words[num_words], word);
    num_words++;
}

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void count_words(FILE *file) {
    char line[1000];
    char *word = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file))!= -1) {
        char *token = strtok_r(line, " \t\n\r\f\v", &word);
        while (token!= NULL) {
            add_word(token);
            token = strtok_r(NULL, " \t\n\r\f\v", &word);
        }
    }
}

void print_word_counts(void) {
    qsort(words, num_words, sizeof(char *), compare_words);
    for (int i = 0; i < num_words; i++) {
        printf("%d %s\n", i + 1, words[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'!\n", argv[1]);
        return 1;
    }

    count_words(file);
    print_word_counts();

    fclose(file);
    return 0;
}
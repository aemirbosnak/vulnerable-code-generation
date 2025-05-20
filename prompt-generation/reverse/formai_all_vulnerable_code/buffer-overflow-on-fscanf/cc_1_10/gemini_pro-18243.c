//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100
#define MIN_WORD_LENGTH 2

typedef struct word_node {
    char word[MAX_WORD_LENGTH + 1];
    int count;
    struct word_node *next;
} word_node_t;

word_node_t *word_list = NULL;

void add_word(char *word) {
    word_node_t *new_node = malloc(sizeof(word_node_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc() failed\n");
        exit(1);
    }

    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = word_list;
    word_list = new_node;
}

void print_word_list() {
    word_node_t *current_node = word_list;
    while (current_node != NULL) {
        printf("%s: %d\n", current_node->word, current_node->count);
        current_node = current_node->next;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: no input file specified\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open input file\n");
        exit(1);
    }

    char *word = malloc(MAX_WORD_LENGTH + 1);
    if (word == NULL) {
        fprintf(stderr, "Error: malloc() failed\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word) != EOF) {
        if (strlen(word) >= MIN_WORD_LENGTH && strlen(word) <= MAX_WORD_LENGTH) {
            add_word(word);
        }
    }

    fclose(fp);

    print_word_list();

    return 0;
}
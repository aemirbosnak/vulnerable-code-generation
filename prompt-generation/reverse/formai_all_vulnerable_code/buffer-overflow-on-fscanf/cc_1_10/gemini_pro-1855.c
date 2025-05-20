//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word_node {
    char *word;
    int count;
    struct word_node *next;
} word_node_t;

typedef struct word_list {
    word_node_t *head;
    word_node_t *tail;
} word_list_t;

void word_list_init(word_list_t *list) {
    list->head = NULL;
    list->tail = NULL;
}

void word_list_destroy(word_list_t *list) {
    word_node_t *current_node = list->head;
    word_node_t *next_node;

    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node->word);
        free(current_node);
        current_node = next_node;
    }

    list->head = NULL;
    list->tail = NULL;
}

word_node_t *word_list_find(word_list_t *list, char *word) {
    word_node_t *current_node = list->head;

    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            return current_node;
        }

        current_node = current_node->next;
    }

    return NULL;
}

void word_list_insert(word_list_t *list, char *word) {
    word_node_t *new_node = malloc(sizeof(word_node_t));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void word_list_increment(word_list_t *list, char *word) {
    word_node_t *node = word_list_find(list, word);

    if (node != NULL) {
        node->count++;
    } else {
        word_list_insert(list, word);
    }
}

void word_list_print(word_list_t *list) {
    word_node_t *current_node = list->head;

    while (current_node != NULL) {
        printf("%s: %d\n", current_node->word, current_node->count);
        current_node = current_node->next;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    word_list_t word_list;
    word_list_init(&word_list);

    char word[1024];
    while (fscanf(fp, "%s", word) != EOF) {
        word_list_increment(&word_list, word);
    }

    fclose(fp);

    word_list_print(&word_list);

    word_list_destroy(&word_list);

    return EXIT_SUCCESS;
}
//FormAI DATASET v1.0 Category: Word Count Tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

struct node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct node *next;
};

void add_word(struct node **head, char *word) {
    if (*head == NULL) {
        *head = malloc(sizeof(struct node));
        strcpy((*head)->word, word);
        (*head)->count = 1;
        (*head)->next = NULL;
        return;
    }

    struct node *prev_node = NULL;
    struct node *curr_node = *head;

    while (curr_node != NULL) {
        if (strcmp(curr_node->word, word) == 0) {
            curr_node->count += 1;
            return;
        }

        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    prev_node->next = malloc(sizeof(struct node));
    strcpy(prev_node->next->word, word);
    prev_node->next->count = 1;
    prev_node->next->next = NULL;
}

void print_word_counts(struct node *head) {
    struct node *curr_node = head;
    while (curr_node != NULL) {
        printf("%s: %d\n", curr_node->word, curr_node->count);
        curr_node = curr_node->next;
    }
}

int main(int argc, char **argv) {
    FILE *fp;
    char filename[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    struct node *word_counts = NULL;

    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    strcpy(filename, argv[1]);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (fscanf(fp, "%s", word) != EOF) {
        char *p = word;
        while (*p != '\0') {
            *p = tolower(*p);
            p++;
        }
        add_word(&word_counts, word);
    }

    fclose(fp);

    print_word_counts(word_counts);

    return 0;
}
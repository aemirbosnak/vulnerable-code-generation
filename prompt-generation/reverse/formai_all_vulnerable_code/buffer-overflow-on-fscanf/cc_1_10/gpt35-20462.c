//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Ken Thompson
// C Word Frequency Counter by a Ken Thompson Style Chatbot
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define TABLE_SIZE 5000

typedef struct linked_list {
    char *word;
    int count;
    struct linked_list *next;
} linked_list;

int hash(char *word) {
    int hash_val = 0;
    while (*word != '\0') {
        hash_val = (hash_val + *word) % TABLE_SIZE;
        word++;
    }
    return hash_val;
}

linked_list *insert_word(linked_list *head, char *word) {
    linked_list *prev, *cur;
    for (prev = cur = head; cur != NULL && strcmp(word, cur->word) > 0; prev = cur, cur = cur->next);
    if (cur == NULL || strcmp(word, cur->word) != 0) {
        linked_list *node = (linked_list*) malloc(sizeof(linked_list));
        node->word = strdup(word);
        node->count = 1;
        node->next = cur;
        if (cur == head) {
            return node;
        } else {
            prev->next = node;
            return head;
        }
    } else {
        cur->count++;
        return head;
    }
}

void print_words(linked_list **table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (linked_list *cur = table[i]; cur != NULL; cur = cur->next) {
            printf("%s: %d\n", cur->word, cur->count);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    linked_list *table[TABLE_SIZE] = { NULL };
    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word) == 1) {
        for (int i = 0; word[i] != '\0'; i++) {
            word[i] = tolower(word[i]);
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }
        if (strlen(word) > 0) {
            int hash_val = hash(word);
            table[hash_val] = insert_word(table[hash_val], word);
        }
    }
    fclose(fp);
    print_words(table);
    return 0;
}
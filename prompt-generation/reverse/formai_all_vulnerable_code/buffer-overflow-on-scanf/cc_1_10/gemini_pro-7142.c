//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

typedef struct node {
    char word[MAX_WORD_LENGTH];
    struct node *next;
} node_t;

typedef struct hash_table {
    node_t **table;
    int size;
} hash_table_t;

hash_table_t *create_hash_table(int size) {
    hash_table_t *table = malloc(sizeof(hash_table_t));
    if (table == NULL) {
        return NULL;
    }

    table->table = malloc(sizeof(node_t *) * size);
    if (table->table == NULL) {
        free(table);
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        table->table[i] = NULL;
    }

    table->size = size;

    return table;
}

void destroy_hash_table(hash_table_t *table) {
    for (int i = 0; i < table->size; i++) {
        node_t *node = table->table[i];
        while (node != NULL) {
            node_t *next = node->next;
            free(node);
            node = next;
        }
    }

    free(table->table);
    free(table);
}

int hash_function(char *word, int size) {
    int hash = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hash += (int)word[i];
    }

    return hash % size;
}

void insert_word(hash_table_t *table, char *word) {
    int hash = hash_function(word, table->size);

    node_t *node = malloc(sizeof(node_t));
    if (node == NULL) {
        return;
    }

    strcpy(node->word, word);
    node->next = table->table[hash];
    table->table[hash] = node;
}

int lookup_word(hash_table_t *table, char *word) {
    int hash = hash_function(word, table->size);

    node_t *node = table->table[hash];
    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            return 1;
        }
        node = node->next;
    }

    return 0;
}

int main() {
    hash_table_t *table = create_hash_table(1000);

    char word[MAX_WORD_LENGTH];
    while (scanf("%s", word) != EOF) {
        if (!isalpha(word[0])) {
            continue;
        }

        for (int i = 0; word[i] != '\0'; i++) {
            word[i] = tolower(word[i]);
        }

        if (!lookup_word(table, word)) {
            insert_word(table, word);
        }
    }

    destroy_hash_table(table);

    return 0;
}
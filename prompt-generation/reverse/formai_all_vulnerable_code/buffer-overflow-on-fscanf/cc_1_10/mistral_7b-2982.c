//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 101

typedef struct HashNode {
    char word[50];
    int count;
    struct HashNode *next;
} HashNode;

unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

HashNode *create_node(const char *word) {
    HashNode *new_node = (HashNode *) malloc(sizeof(HashNode));
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

void insert_word(HashNode **table, const char *word) {
    unsigned long index = hash(word);

    if (table[index] == NULL) {
        table[index] = create_node(word);
    } else {
        HashNode *current = table[index];
        while (current != NULL) {
            if (strcmp(current->word, word) == 0) {
                current->count++;
                return;
            }
            current = current->next;
        }

        HashNode *new_node = create_node(word);
        new_node->next = table[index];
        table[index] = new_node;
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");
    HashNode *table[TABLE_SIZE] = {NULL};

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char word[50];
    while (fscanf(file, "%s", word) != EOF) {
        for (int i = 0; word[i] != '\0'; i++) {
            word[i] = tolower(word[i]);
        }
        insert_word(table, word);
    }

    fclose(file);

    printf("Word frequencies:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != NULL) {
            printf("%s: %d\n", table[i]->word, table[i]->count);
        }
    }

    return 0;
}
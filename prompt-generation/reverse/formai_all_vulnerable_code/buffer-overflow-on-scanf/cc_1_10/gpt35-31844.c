//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 1000 // size of the hash table

char* remove_punctuations(char* word) {
    int i, j = 0;
    char* cleaned = malloc(strlen(word) + 1);
    for (i = 0; word[i]; i++) {
        if (isalpha(word[i])) {
            cleaned[j++] = tolower(word[i]);
        }
    }
    cleaned[j] = '\0';
    return cleaned;
}

unsigned long hash(char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % TABLE_SIZE;
}

typedef struct Node {
    char* word;
    int count;
    struct Node* next;
} Node;

Node* create_node(char* word) {
    Node* node = malloc(sizeof(Node));
    node->word = word;
    node->count = 1;
    node->next = NULL;
    return node;
}

void insert(Node** hash_table, char* word) {
    int index = hash(word);
    Node* node = hash_table[index];
    while (node) {
        if (strcmp(node->word, word) == 0) {
            node->count++;
            return;
        }
        node = node->next;
    }
    node = create_node(word);
    node->next = hash_table[index];
    hash_table[index] = node;
}

void display(Node** hash_table) {
    int i;
    Node* node;
    for (i = 0; i < TABLE_SIZE; i++) {
        node = hash_table[i];
        while (node) {
            printf("%s: %d\n", node->word, node->count);
            node = node->next;
        }
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found!");
        return 0;
    }

    Node* hash_table[TABLE_SIZE] = { NULL };
    char buffer[1000], *word;
    while (fscanf(file, "%s", buffer) != EOF) {
        word = remove_punctuations(buffer);
        if (strlen(word) > 0) {
            insert(hash_table, word);
        }
    }

    display(hash_table);
    fclose(file);
    return 0;
}
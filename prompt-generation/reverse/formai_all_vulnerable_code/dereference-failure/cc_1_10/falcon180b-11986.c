//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_KEY_LEN 50

typedef struct {
    char *key;
    int value;
    struct node *next;
} Node;

typedef struct {
    Node *nodes[MAX_NODES];
} HashTable;

int hash(char *key) {
    int sum = 0;
    while (*key) {
        sum += *key;
        key++;
    }
    return sum % MAX_NODES;
}

HashTable *createHashTable() {
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    for (int i = 0; i < MAX_NODES; i++) {
        ht->nodes[i] = NULL;
    }
    return ht;
}

void insert(HashTable *ht, char *key, int value) {
    int index = hash(key);
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = ht->nodes[index];
    ht->nodes[index] = new_node;
}

int search(HashTable *ht, char *key) {
    int index = hash(key);
    Node *current_node = ht->nodes[index];
    while (current_node!= NULL) {
        if (strcmp(current_node->key, key) == 0) {
            return current_node->value;
        }
        current_node = current_node->next;
    }
    return -1;
}

int main() {
    HashTable *ht = createHashTable();
    insert(ht, "apple", 5);
    insert(ht, "orange", 10);
    insert(ht, "banana", 3);
    int value1 = search(ht, "apple");
    int value2 = search(ht, "orange");
    int value3 = search(ht, "banana");
    printf("Apple value: %d\n", value1);
    printf("Orange value: %d\n", value2);
    printf("Banana value: %d\n", value3);
    return 0;
}
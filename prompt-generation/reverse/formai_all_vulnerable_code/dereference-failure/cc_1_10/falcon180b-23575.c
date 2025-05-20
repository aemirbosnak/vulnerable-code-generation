//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Node;

typedef struct {
    Node *nodes;
    int size;
} HashTable;

int hashFunction(char *key) {
    int sum = 0;
    while (*key) {
        sum += *key;
        key++;
    }
    return sum % MAX_SIZE;
}

void initHashTable(HashTable *hashTable) {
    hashTable->nodes = (Node *)malloc(MAX_SIZE * sizeof(Node));
    hashTable->size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        hashTable->nodes[i].data = -1;
        hashTable->nodes[i].index = -1;
    }
}

void insertNode(HashTable *hashTable, char *key, int data) {
    int index = hashFunction(key);
    Node *node = &hashTable->nodes[index];
    if (node->data == -1) {
        node->data = data;
        node->index = index;
        hashTable->size++;
    } else if (node->data == data) {
        node->index = index;
    }
}

void printHashTable(HashTable *hashTable) {
    for (int i = 0; i < MAX_SIZE; i++) {
        Node *node = &hashTable->nodes[i];
        if (node->data!= -1) {
            printf("Key: %s, Data: %d, Index: %d\n", node->index == -1? "" : node->index, node->data, node->index);
        }
    }
}

int main() {
    HashTable hashTable;
    initHashTable(&hashTable);

    insertNode(&hashTable, "apple", 10);
    insertNode(&hashTable, "banana", 20);
    insertNode(&hashTable, "cherry", 30);
    insertNode(&hashTable, "date", 40);
    insertNode(&hashTable, "elderberry", 50);

    printf("Hash Table:\n");
    printHashTable(&hashTable);

    return 0;
}
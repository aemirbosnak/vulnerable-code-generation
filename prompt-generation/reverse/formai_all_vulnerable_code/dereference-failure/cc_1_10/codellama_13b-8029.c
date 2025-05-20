//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VAL_SIZE 100

// Structure to represent a key-value pair
typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VAL_SIZE];
} pair;

// Structure to represent a node in the linked list
typedef struct node {
    pair data;
    struct node *next;
} node;

// Structure to represent the hash table
typedef struct {
    node **table;
    int size;
} hash_table;

// Function to create a new node
node *create_node(pair data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new hash table
hash_table *create_hash_table(int size) {
    hash_table *new_hash_table = malloc(sizeof(hash_table));
    new_hash_table->size = size;
    new_hash_table->table = malloc(size * sizeof(node*));
    for (int i = 0; i < size; i++) {
        new_hash_table->table[i] = NULL;
    }
    return new_hash_table;
}

// Function to hash a key
int hash(char *key, int size) {
    int hash_value = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash_value += key[i];
    }
    return hash_value % size;
}

// Function to insert a key-value pair into the hash table
void insert(hash_table *hash_table, char *key, char *value) {
    int index = hash(key, hash_table->size);
    node *new_node = create_node((pair) {key, value});
    new_node->next = hash_table->table[index];
    hash_table->table[index] = new_node;
}

// Function to retrieve a value from the hash table
char *retrieve(hash_table *hash_table, char *key) {
    int index = hash(key, hash_table->size);
    node *current = hash_table->table[index];
    while (current != NULL) {
        if (strcmp(current->data.key, key) == 0) {
            return current->data.value;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a key-value pair from the hash table
void delete(hash_table *hash_table, char *key) {
    int index = hash(key, hash_table->size);
    node *current = hash_table->table[index];
    node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->data.key, key) == 0) {
            if (previous == NULL) {
                hash_table->table[index] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    hash_table *hash_table = create_hash_table(10);
    insert(hash_table, "apple", "red");
    insert(hash_table, "banana", "yellow");
    insert(hash_table, "cherry", "red");
    insert(hash_table, "date", "purple");
    insert(hash_table, "eggplant", "purple");

    printf("%s\n", retrieve(hash_table, "apple"));
    printf("%s\n", retrieve(hash_table, "banana"));
    printf("%s\n", retrieve(hash_table, "cherry"));
    printf("%s\n", retrieve(hash_table, "date"));
    printf("%s\n", retrieve(hash_table, "eggplant"));

    delete(hash_table, "apple");
    delete(hash_table, "banana");
    delete(hash_table, "cherry");
    delete(hash_table, "date");
    delete(hash_table, "eggplant");

    return 0;
}
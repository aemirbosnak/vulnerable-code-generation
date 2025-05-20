//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: rigorous
/*
 * A rigorous C database indexing system example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a record
struct record {
    int id;
    char name[100];
    char email[100];
};

// Structure to store a node in the linked list
struct node {
    struct record *data;
    struct node *next;
};

// Structure to store the hash table
struct hash_table {
    int size;
    struct node **buckets;
};

// Function to initialize the hash table
struct hash_table* init_hash_table(int size) {
    struct hash_table *ht = malloc(sizeof(struct hash_table));
    ht->size = size;
    ht->buckets = malloc(sizeof(struct node*) * size);
    for (int i = 0; i < size; i++) {
        ht->buckets[i] = NULL;
    }
    return ht;
}

// Function to hash a key
int hash(char *key, int size) {
    int hash_val = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash_val += key[i];
    }
    return hash_val % size;
}

// Function to insert a record into the hash table
void insert_record(struct hash_table *ht, struct record *record) {
    int hash_val = hash(record->name, ht->size);
    struct node *node = malloc(sizeof(struct node));
    node->data = record;
    node->next = ht->buckets[hash_val];
    ht->buckets[hash_val] = node;
}

// Function to retrieve a record from the hash table
struct record* retrieve_record(struct hash_table *ht, char *name) {
    int hash_val = hash(name, ht->size);
    struct node *node = ht->buckets[hash_val];
    while (node != NULL) {
        if (strcmp(node->data->name, name) == 0) {
            return node->data;
        }
        node = node->next;
    }
    return NULL;
}

// Function to delete a record from the hash table
void delete_record(struct hash_table *ht, char *name) {
    int hash_val = hash(name, ht->size);
    struct node *node = ht->buckets[hash_val];
    struct node *prev = NULL;
    while (node != NULL) {
        if (strcmp(node->data->name, name) == 0) {
            if (prev != NULL) {
                prev->next = node->next;
            } else {
                ht->buckets[hash_val] = node->next;
            }
            free(node->data);
            free(node);
            break;
        }
        prev = node;
        node = node->next;
    }
}

// Function to print the hash table
void print_hash_table(struct hash_table *ht) {
    for (int i = 0; i < ht->size; i++) {
        struct node *node = ht->buckets[i];
        while (node != NULL) {
            printf("(%d, %s, %s)\n", node->data->id, node->data->name, node->data->email);
            node = node->next;
        }
    }
}

int main() {
    struct hash_table *ht = init_hash_table(10);
    struct record record1 = {1, "John", "john@example.com"};
    struct record record2 = {2, "Jane", "jane@example.com"};
    struct record record3 = {3, "Bob", "bob@example.com"};
    struct record record4 = {4, "Alice", "alice@example.com"};
    insert_record(ht, &record1);
    insert_record(ht, &record2);
    insert_record(ht, &record3);
    insert_record(ht, &record4);
    print_hash_table(ht);
    delete_record(ht, "Jane");
    print_hash_table(ht);
    struct record *retrieved_record = retrieve_record(ht, "Bob");
    printf("Retrieved record: (%d, %s, %s)\n", retrieved_record->id, retrieved_record->name, retrieved_record->email);
    return 0;
}
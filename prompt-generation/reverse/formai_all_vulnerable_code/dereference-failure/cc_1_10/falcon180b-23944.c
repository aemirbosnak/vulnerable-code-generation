//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 10000 // size of the hash table

typedef struct {
    char *key;
    int value;
} hash_entry_t;

hash_entry_t hash_table[HASH_SIZE];

int hash_function(char *key) {
    int hash_value = 0;
    int i = 0;
    while (key[i]) {
        hash_value += key[i];
        i++;
    }
    return hash_value % HASH_SIZE;
}

// function to add a key-value pair to the hash table
void add_entry(char *key, int value) {
    int index = hash_function(key);
    hash_entry_t *entry = &hash_table[index];
    if (entry->key == NULL) {
        entry->key = strdup(key);
        entry->value = value;
    } else {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value;
        } else {
            printf("Error: key already exists in hash table\n");
        }
    }
}

// function to search for a key in the hash table and return its value
int search_entry(char *key) {
    int index = hash_function(key);
    hash_entry_t *entry = &hash_table[index];
    if (entry->key == NULL) {
        return -1; // key not found
    } else {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        } else {
            return -1; // key not found
        }
    }
}

int main() {
    add_entry("apple", 10);
    add_entry("banana", 20);
    add_entry("cherry", 30);
    add_entry("orange", 40);

    int apple_value = search_entry("apple");
    int banana_value = search_entry("banana");
    int cherry_value = search_entry("cherry");
    int orange_value = search_entry("orange");

    printf("apple value: %d\n", apple_value);
    printf("banana value: %d\n", banana_value);
    printf("cherry value: %d\n", cherry_value);
    printf("orange value: %d\n", orange_value);

    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hash function for strings
unsigned int hash(const char *str) {
    unsigned int hash = 0;
    while (*str!= '\0') {
        hash += *str++;
    }
    return hash;
}

// Hash table
unsigned int table[100];

// Function to insert key-value pairs into the hash table
void insert(const char *key, const char *value) {
    unsigned int index = hash(key);
    if (table[index] == 0) {
        table[index] = 1;
    } else {
        table[index] = 2; // collision
    }
    printf("Inserted %s => %s\n", key, value);
}

// Function to search for a key in the hash table
const char *search(const char *key) {
    unsigned int index = hash(key);
    if (table[index] == 0) {
        return NULL;
    } else if (table[index] == 1) {
        return "Value not found";
    } else {
        return "Value found";
    }
}

int main() {
    insert("apple", "fruit");
    insert("banana", "fruit");
    insert("carrot", "vegetable");

    const char *key = "apple";
    printf("Search for %s:\n", key);
    const char *result = search(key);
    printf("%s\n", result);

    return 0;
}
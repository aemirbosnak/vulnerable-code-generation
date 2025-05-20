//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the data
typedef struct {
    char *key;
    int value;
} Data;

// Function to compare two Data structures
int compare(const void *a, const void *b) {
    Data *data1 = (Data*)a;
    Data *data2 = (Data*)b;
    return strcmp(data1->key, data2->key);
}

// Function to print the data
void print_data(Data *data) {
    printf("Key: %s, Value: %d\n", data->key, data->value);
}

// Function to search for a key in the hash table
int search(Data *hash_table, int size, char *key) {
    Data *data = bsearch(key, hash_table, size, sizeof(Data), compare);
    if (data!= NULL) {
        print_data(data);
        return 1;
    } else {
        printf("Key not found\n");
        return 0;
    }
}

// Function to insert a key-value pair into the hash table
void insert(Data *hash_table, int size, char *key, int value) {
    Data *data = malloc(sizeof(Data));
    data->key = strdup(key);
    data->value = value;
    int index = hash(key, size);
    hash_table[index] = *data;
}

// Function to hash the key
int hash(char *key, int size) {
    int hash = 0;
    int i = 0;
    while (key[i]!= '\0') {
        hash += key[i] * i;
        i++;
    }
    return hash % size;
}

// Main function
int main() {
    int size = 10;
    Data *hash_table = malloc(sizeof(Data) * size);
    for (int i = 0; i < size; i++) {
        hash_table[i].key = NULL;
        hash_table[i].value = -1;
    }

    // Insert some data
    insert(hash_table, size, "apple", 1);
    insert(hash_table, size, "banana", 2);
    insert(hash_table, size, "orange", 3);

    // Search for a key
    char key[10];
    printf("Enter a key to search: ");
    scanf("%s", key);
    search(hash_table, size, key);

    // Insert some more data
    insert(hash_table, size, "grape", 4);
    insert(hash_table, size, "pear", 5);

    // Search for a key again
    printf("Enter a key to search: ");
    scanf("%s", key);
    search(hash_table, size, key);

    return 0;
}
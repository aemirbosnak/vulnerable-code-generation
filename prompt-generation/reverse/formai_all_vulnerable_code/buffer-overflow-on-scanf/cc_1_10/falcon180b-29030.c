//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_KEY_LEN 50
#define MAX_VALUE_LEN 1000
#define HASH_TABLE_SIZE (MAX_ENTRIES * 2)

// Struct to hold key-value pairs
typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} entry_t;

// Hash table to store entries
entry_t hash_table[HASH_TABLE_SIZE];

// Function to calculate hash value for a given key
int hash(char* key) {
    int hash_val = 0;
    int i = 0;
    while (key[i]!= '\0') {
        hash_val += key[i];
        i++;
    }
    return hash_val % HASH_TABLE_SIZE;
}

// Function to insert an entry into the hash table
void insert(char* key, char* value) {
    int hash_val = hash(key);
    int i = hash_val;
    while (hash_table[i].key[0]!= '\0') {
        i = (i + 1) % HASH_TABLE_SIZE;
    }
    strcpy(hash_table[i].key, key);
    strcpy(hash_table[i].value, value);
}

// Function to search for an entry in the hash table
char* search(char* key) {
    int hash_val = hash(key);
    int i = hash_val;
    while (hash_table[i].key[0]!= '\0') {
        if (strcmp(hash_table[i].key, key) == 0) {
            return hash_table[i].value;
        }
        i = (i + 1) % HASH_TABLE_SIZE;
    }
    return NULL;
}

// Main function
int main() {
    int choice;
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];

    do {
        printf("\nC Database Indexing System\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%s", value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%s", key);
                char* result = search(key);
                if (result!= NULL) {
                    printf("Value: %s\n", result);
                } else {
                    printf("Key not found\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}
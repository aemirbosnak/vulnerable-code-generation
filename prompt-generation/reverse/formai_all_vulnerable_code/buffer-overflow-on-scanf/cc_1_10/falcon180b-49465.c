//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 500
#define HASH_TABLE_SIZE 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} hash_table_entry_t;

hash_table_entry_t hash_table[HASH_TABLE_SIZE];

unsigned int hash_function(char* key) {
    unsigned int hash = 0;
    int i = 0;
    while(key[i]!= '\0') {
        hash += key[i];
        i++;
    }
    return hash % HASH_TABLE_SIZE;
}

void insert_into_hash_table(char* key, char* value) {
    unsigned int index = hash_function(key);
    if(hash_table[index].key[0] == '\0') {
        strcpy(hash_table[index].key, key);
        strcpy(hash_table[index].value, value);
    }
    else {
        printf("Key already exists in hash table.\n");
    }
}

void search_hash_table(char* key) {
    unsigned int index = hash_function(key);
    if(hash_table[index].key[0]!= '\0') {
        if(strcmp(hash_table[index].key, key) == 0) {
            printf("Value for key %s: %s\n", key, hash_table[index].value);
        }
        else {
            printf("Key not found in hash table.\n");
        }
    }
    else {
        printf("Key not found in hash table.\n");
    }
}

int main() {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];

    printf("Enter key: ");
    scanf("%s", key);
    printf("Enter value: ");
    scanf("%s", value);

    insert_into_hash_table(key, value);

    printf("Search key: ");
    scanf("%s", key);
    search_hash_table(key);

    return 0;
}
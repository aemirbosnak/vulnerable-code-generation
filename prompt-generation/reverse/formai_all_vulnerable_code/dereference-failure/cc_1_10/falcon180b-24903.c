//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} hashTable;

hashTable *createHashTable() {
    hashTable *hash = (hashTable *)malloc(MAX_SIZE * sizeof(hashTable));
    memset(hash, -1, MAX_SIZE * sizeof(hashTable));
    return hash;
}

int hashFunction(char *key) {
    int sum = 0;
    for(int i=0; key[i]!='\0'; i++) {
        sum += key[i];
    }
    return sum % MAX_SIZE;
}

void insert(hashTable *hash, char *key, int value) {
    int index = hashFunction(key);
    if(hash[index].key == NULL) {
        hash[index].key = strdup(key);
        hash[index].value = value;
    } else {
        if(strcmp(hash[index].key, key) == 0) {
            hash[index].value = value;
        } else {
            printf("Key already exists with a different value!\n");
        }
    }
}

int search(hashTable *hash, char *key) {
    int index = hashFunction(key);
    if(hash[index].key!= NULL && strcmp(hash[index].key, key) == 0) {
        return hash[index].value;
    } else {
        return -1;
    }
}

int main() {
    hashTable *hash = createHashTable();

    insert(hash, "apple", 10);
    insert(hash, "banana", 20);
    insert(hash, "orange", 30);

    int value = search(hash, "banana");
    printf("Value of banana is: %d\n", value);

    value = search(hash, "grape");
    if(value == -1) {
        printf("Grape not found!\n");
    } else {
        printf("Value of grape is: %d\n", value);
    }

    return 0;
}
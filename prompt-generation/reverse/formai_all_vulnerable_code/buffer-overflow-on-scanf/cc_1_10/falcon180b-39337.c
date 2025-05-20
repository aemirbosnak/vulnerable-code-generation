//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int key;
    int value;
} Pair;

Pair hashTable[MAX_SIZE];

int hashFunction(int key) {
    return key % MAX_SIZE;
}

void insert(int key, int value) {
    int index = hashFunction(key);
    int i = 0;
    while (hashTable[index].key!= -1 && i < MAX_SIZE) {
        if (hashTable[index].key == key) {
            hashTable[index].value = value;
            return;
        }
        index = (index + 1) % MAX_SIZE;
        i++;
    }
    hashTable[index].key = key;
    hashTable[index].value = value;
}

int search(int key) {
    int index = hashFunction(key);
    int i = 0;
    while (hashTable[index].key!= -1 && i < MAX_SIZE) {
        if (hashTable[index].key == key) {
            return hashTable[index].value;
        }
        index = (index + 1) % MAX_SIZE;
        i++;
    }
    return -1;
}

int main() {
    int i, n, key, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter key-value pair %d: ", i+1);
        scanf("%d%d", &key, &value);
        insert(key, value);
    }

    printf("Enter the key to search for: ");
    scanf("%d", &key);

    value = search(key);

    if (value == -1) {
        printf("Key not found!\n");
    } else {
        printf("Value for key %d is %d\n", key, value);
    }

    return 0;
}
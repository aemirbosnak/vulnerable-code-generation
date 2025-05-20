//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    char* key;
    int value;
} Pair;

Pair arr[MAX_SIZE];
int size = 0;

void insert(char* key, int value) {
    if (size >= MAX_SIZE) {
        printf("Error: Hash table is full\n");
        return;
    }
    Pair* new_pair = (Pair*) malloc(sizeof(Pair));
    new_pair->key = strdup(key);
    new_pair->value = value;
    arr[size++] = *new_pair;
}

int search(char* key) {
    int hash_value = strlen(key) % MAX_SIZE;
    for (int i = 0; i < size; i++) {
        if (arr[i].key!= NULL &&!strcmp(arr[i].key, key)) {
            return arr[i].value;
        } else if (arr[i].key == NULL) {
            continue;
        } else {
            hash_value++;
            if (hash_value >= MAX_SIZE) {
                hash_value = 0;
            }
            i = hash_value;
        }
    }
    return -1;
}

int main() {
    insert("apple", 1);
    insert("banana", 2);
    insert("cherry", 3);
    int result = search("banana");
    printf("%d\n", result);
    return 0;
}
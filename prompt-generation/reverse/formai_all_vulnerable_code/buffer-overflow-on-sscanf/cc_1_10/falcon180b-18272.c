//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} KeyValue;

int compare(const void *a, const void *b) {
    KeyValue *keyA = (KeyValue*)a;
    KeyValue *keyB = (KeyValue*)b;
    return strcmp(keyA->key, keyB->key);
}

int search(KeyValue *array, int size, char *key) {
    KeyValue keyToFind = {key, 0};
    int index = bsearch(&keyToFind, array, size, sizeof(KeyValue), compare);
    if (index == -1) {
        printf("Key not found\n");
        return -1;
    } else {
        printf("Key found, value: %d\n", array[index].value);
        return index;
    }
}

int main() {
    KeyValue array[MAX_SIZE];
    int size = 0;

    char key[100];
    int value;

    while (fgets(key, sizeof(key), stdin)!= NULL) {
        if (sscanf(key, "%s %d", key, &value) == 2) {
            KeyValue kv = {key, value};
            array[size++] = kv;
        } else {
            printf("Invalid input format\n");
        }
    }

    char searchKey[100];
    while (fgets(searchKey, sizeof(searchKey), stdin)!= NULL) {
        int result = search(array, size, searchKey);
        if (result == -1) {
            break;
        }
    }

    return 0;
}
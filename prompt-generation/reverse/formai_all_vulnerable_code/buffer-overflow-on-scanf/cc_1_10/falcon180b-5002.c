//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} KeyValuePair;

int compare(const void *a, const void *b) {
    KeyValuePair *pairA = (KeyValuePair *)a;
    KeyValuePair *pairB = (KeyValuePair *)b;

    return strcmp(pairA->key, pairB->key);
}

int search(KeyValuePair *array, int size, char *key) {
    KeyValuePair keyValuePair;
    keyValuePair.key = key;

    int result = bsearch(&keyValuePair, array, size, sizeof(KeyValuePair), compare);

    if (result == -1) {
        printf("Key not found\n");
    } else {
        printf("Key found with value: %d\n", array[result].value);
    }

    return result;
}

int main() {
    KeyValuePair array[MAX_SIZE];
    int size = 0;

    char *key = "apple";
    int value = 10;

    array[size].key = strdup(key);
    array[size].value = value;
    size++;

    key = "banana";
    value = 20;

    array[size].key = strdup(key);
    array[size].value = value;
    size++;

    key = "cherry";
    value = 30;

    array[size].key = strdup(key);
    array[size].value = value;
    size++;

    qsort(array, size, sizeof(KeyValuePair), compare);

    for (int i = 0; i < size; i++) {
        printf("Key: %s, Value: %d\n", array[i].key, array[i].value);
    }

    char searchKey[20];
    printf("Enter key to search: ");
    scanf("%s", searchKey);

    search(array, size, searchKey);

    return 0;
}
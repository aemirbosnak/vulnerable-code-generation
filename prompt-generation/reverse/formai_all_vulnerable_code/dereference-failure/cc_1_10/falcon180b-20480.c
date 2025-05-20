//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_NUM_KEYS 10

typedef struct {
    char key[MAX_KEY_LENGTH];
    int value;
} KeyValuePair;

typedef struct {
    KeyValuePair *keys;
    int numKeys;
} Index;

void initializeIndex(Index *index) {
    index->keys = (KeyValuePair *)malloc(MAX_NUM_KEYS * sizeof(KeyValuePair));
    index->numKeys = 0;
}

void addKey(Index *index, char *key, int value) {
    if (index->numKeys >= MAX_NUM_KEYS) {
        printf("Error: Maximum number of keys reached!\n");
        return;
    }

    strcpy(index->keys[index->numKeys].key, key);
    index->keys[index->numKeys].value = value;
    index->numKeys++;
}

int searchKey(Index *index, char *key) {
    int i;

    for (i = 0; i < index->numKeys; i++) {
        if (strcmp(index->keys[i].key, key) == 0) {
            return index->keys[i].value;
        }
    }

    return -1;
}

int main() {
    Index index;
    initializeIndex(&index);

    addKey(&index, "John", 23);
    addKey(&index, "Jane", 19);
    addKey(&index, "Doe", 30);

    int johnAge = searchKey(&index, "John");
    int janeAge = searchKey(&index, "Jane");
    int doeAge = searchKey(&index, "Doe");

    printf("John's age: %d\n", johnAge);
    printf("Jane's age: %d\n", janeAge);
    printf("Doe's age: %d\n", doeAge);

    return 0;
}
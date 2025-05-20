//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_KEY_SIZE 50
#define MAX_VALUE_SIZE 200
#define MAX_NUM_KEYS 1000
#define MAX_INDEX_SIZE 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} KeyValue;

typedef struct {
    char indexKey[MAX_KEY_SIZE];
    int indexValue;
} Index;

KeyValue *keyValues;
Index *indexes;
int numKeys;
int numIndexes;

void initialize() {
    keyValues = (KeyValue *)malloc(MAX_NUM_KEYS * sizeof(KeyValue));
    indexes = (Index *)malloc(MAX_INDEX_SIZE * sizeof(Index));
    numKeys = 0;
    numIndexes = 0;
}

void addKeyValue(char *key, char *value) {
    strcpy(keyValues[numKeys].key, key);
    strcpy(keyValues[numKeys].value, value);
    numKeys++;
}

void addIndex(char *key, int value) {
    strcpy(indexes[numIndexes].indexKey, key);
    indexes[numIndexes].indexValue = value;
    numIndexes++;
}

int binarySearch(char *key, int start, int end) {
    int mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (strcmp(key, keyValues[indexes[mid].indexValue].key) == 0) {
            return mid;
        } else if (strcmp(key, keyValues[indexes[mid].indexValue].key) < 0) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    initialize();

    addKeyValue("John", "123 Main St");
    addKeyValue("Jane", "456 Elm St");
    addKeyValue("Bob", "789 Oak St");

    addIndex("John", 0);
    addIndex("Jane", 1);
    addIndex("Bob", 2);

    int index;
    char key[MAX_KEY_SIZE];
    while (1) {
        printf("Enter search key: ");
        scanf("%s", key);
        index = binarySearch(key, 0, numIndexes - 1);
        if (index == -1) {
            printf("Key not found\n");
        } else {
            printf("Value: %s\n", keyValues[indexes[index].indexValue].value);
        }
    }

    return 0;
}
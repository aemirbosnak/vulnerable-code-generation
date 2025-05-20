//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    int key;
    int value;
} KeyValue;

typedef struct {
    KeyValue *data;
    int size;
    int capacity;
} HashTable;

void initHashTable(HashTable *table) {
    table->data = (KeyValue *)malloc(MAX_SIZE * sizeof(KeyValue));
    table->size = 0;
    table->capacity = MAX_SIZE;
}

int hashFunction(int key) {
    return key % MAX_SIZE;
}

void insert(HashTable *table, int key, int value) {
    int index = hashFunction(key);
    KeyValue *pair = &table->data[index];

    while (pair->key!= key && pair->key!= -1) {
        pair++;
    }

    if (pair->key == -1) {
        table->size++;
    }

    pair->key = key;
    pair->value = value;
}

int search(HashTable *table, int key) {
    int index = hashFunction(key);
    KeyValue *pair = &table->data[index];

    while (pair->key!= key && pair->key!= -1) {
        pair++;
    }

    if (pair->key == -1) {
        return -1;
    }

    return pair->value;
}

int delete(HashTable *table, int key) {
    int index = hashFunction(key);
    KeyValue *pair = &table->data[index];

    while (pair->key!= key && pair->key!= -1) {
        pair++;
    }

    if (pair->key == -1) {
        return -1;
    }

    pair->key = -1;
    table->size--;

    return 0;
}

void resize(HashTable *table) {
    KeyValue *newData = (KeyValue *)malloc(table->capacity * 2 * sizeof(KeyValue));
    int newCapacity = table->capacity * 2;

    for (int i = 0; i < table->size; i++) {
        KeyValue *pair = &table->data[i];

        while (pair->key!= -1) {
            int index = hashFunction(pair->key);

            KeyValue *newPair = &newData[index];

            while (newPair->key!= -1) {
                newPair++;
            }

            newPair->key = pair->key;
            newPair->value = pair->value;

            pair->key = -1;
            pair++;
        }
    }

    free(table->data);
    table->data = newData;
    table->capacity = newCapacity;
}

int main() {
    HashTable table;
    initHashTable(&table);

    int i;
    for (i = 0; i < MAX_SIZE * 10; i++) {
        insert(&table, i, i * 2);
    }

    for (i = 0; i < MAX_SIZE * 10; i++) {
        int value = search(&table, i);
        if (value!= -1) {
            printf("%d -> %d\n", i, value);
        }
    }

    for (i = 0; i < MAX_SIZE * 10; i++) {
        delete(&table, i);
    }

    return 0;
}
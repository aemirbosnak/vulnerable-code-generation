//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} Entry;

void insert(Entry *table, int size, char *key, int value) {
    int i = 0;
    while (i < size && table[i].key!= NULL) {
        if (strcmp(table[i].key, key) == 0) {
            table[i].value = value;
            return;
        }
        i++;
    }
    if (i == size) {
        table = realloc(table, sizeof(Entry) * (size + 1));
        table[size].key = strdup(key);
        table[size].value = value;
        size++;
    }
}

int search(Entry *table, int size, char *key) {
    int i = 0;
    while (i < size && table[i].key!= NULL) {
        if (strcmp(table[i].key, key) == 0) {
            return table[i].value;
        }
        i++;
    }
    return -1;
}

void delete(Entry *table, int size, char *key) {
    int i = 0;
    while (i < size && table[i].key!= NULL) {
        if (strcmp(table[i].key, key) == 0) {
            free(table[i].key);
            table[i].key = NULL;
            table[i].value = -1;
            return;
        }
        i++;
    }
}

int main() {
    Entry *table = malloc(sizeof(Entry) * MAX_SIZE);
    int size = 0;

    insert(table, size, "apple", 1);
    insert(table, size, "banana", 2);
    insert(table, size, "cherry", 3);

    int value1 = search(table, size, "apple");
    int value2 = search(table, size, "orange");

    printf("Value for apple: %d\n", value1);
    printf("Value for orange: %d\n", value2);

    delete(table, size, "banana");

    value1 = search(table, size, "banana");
    printf("Value for banana after deletion: %d\n", value1);

    free(table);
    return 0;
}
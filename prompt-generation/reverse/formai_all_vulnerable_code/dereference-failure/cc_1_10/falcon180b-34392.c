//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *key;
    int value;
} Entry;

void insert(Entry *table[], int size, char *key, int value) {
    if (size >= MAX_SIZE) {
        printf("Table is full!\n");
        return;
    }

    int i = 0;
    while (table[i]!= NULL && strcmp(table[i]->key, key)!= 0) {
        i++;
    }

    if (table[i] == NULL) {
        table[i] = (Entry*)malloc(sizeof(Entry));
        strcpy(table[i]->key, key);
        table[i]->value = value;
    } else {
        printf("Key already exists!\n");
    }

    size++;
}

int search(Entry *table[], int size, char *key) {
    int i = 0;

    while (table[i]!= NULL && strcmp(table[i]->key, key)!= 0) {
        i++;
    }

    if (table[i] == NULL) {
        return -1;
    }

    return table[i]->value;
}

void delete(Entry *table[], int size, char *key) {
    int i = 0;

    while (table[i]!= NULL && strcmp(table[i]->key, key)!= 0) {
        i++;
    }

    if (table[i] == NULL) {
        printf("Key not found!\n");
        return;
    }

    free(table[i]->key);
    free(table[i]);
    table[i] = NULL;
    size--;
}

void display(Entry *table[], int size) {
    int i = 0;

    printf("Table:\n");
    while (table[i]!= NULL) {
        printf("%s - %d\n", table[i]->key, table[i]->value);
        i++;
    }
}

int main() {
    Entry *table[MAX_SIZE];
    int size = 0;

    insert(table, size, "apple", 10);
    insert(table, size, "banana", 20);
    insert(table, size, "cherry", 30);

    display(table, size);

    int value = search(table, size, "banana");
    if (value!= -1) {
        printf("Value of banana: %d\n", value);
    }

    delete(table, size, "cherry");
    display(table, size);

    return 0;
}
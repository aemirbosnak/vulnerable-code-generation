//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TABLE_SIZE 101
#define KEY_LENGTH 32

typedef struct {
    char key[KEY_LENGTH];
    int value;
} Record;

unsigned long hash(char *key) {
    unsigned long h = 5381;
    int c;

    while ((c = *key++))
        h = ((h << 5) + h) + c; /* hash function */

    return h % TABLE_SIZE;
}

int search(unsigned long hash, char *key, Record **table) {
    int i;

    for (i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != NULL && strcmp(table[i]->key, key) == 0)
            return i;
    }

    return -1;
}

void insert(unsigned long hash, char *key, int value, Record **table) {
    int i;

    if ((table[hash] = malloc(sizeof(Record))) == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(table[hash]->key, key);
    table[hash]->value = value;
}

int main() {
    Record *table[TABLE_SIZE];
    int i, n;
    char key[KEY_LENGTH];
    int value;

    printf("Enter the number of records: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter key and value for record %d: ", i + 1);
        scanf("%s %d", key, &value);

        insert(hash(key), key, value, table);
    }

    printf("\nEnter key to search: ");
    scanf("%s", key);

    int index = search(hash(key), key, table);

    if (index != -1)
        printf("Record found at index %d with value %d.\n", index, table[index]->value);
    else
        printf("Record not found.\n");

    for (i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != NULL) {
            printf("Index %d: Key = %s, Value = %d\n", i, table[i]->key, table[i]->value);
            free(table[i]);
        }
    }

    return EXIT_SUCCESS;
}
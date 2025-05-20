//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} Entry;

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void search(Entry *table, int size, char *key) {
    int i = 0;

    while (i < size && table[i].value!= -1) {
        if (strcmp(table[i].key, key) == 0) {
            printf("Found key: %s, value: %d\n", table[i].key, table[i].value);
            return;
        }
        i++;
    }

    printf("Key not found\n");
}

int main() {
    Entry table[MAX_SIZE];
    int size = 0;

    table[size].key = "apple";
    table[size].value = 1;
    size++;

    table[size].key = "banana";
    table[size].value = 2;
    size++;

    table[size].key = "cherry";
    table[size].value = 3;
    size++;

    qsort(table, size, sizeof(Entry), compare);

    char key[MAX_SIZE];

    printf("Enter key to search: ");
    scanf("%s", key);

    search(table, size, key);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define NOT_FOUND -1

typedef struct {
    char *key;
    int value;
} Record;

void create_database(Record *database, int size) {
    for (int i = 0; i < size; i++) {
        Record record;
        printf("Enter key for record %d: ", i + 1);
        scanf("%s", record.key);
        printf("Enter value for record %d: ", i + 1);
        scanf("%d", &record.value);
        strcpy(database[i].key, record.key);
        database[i].value = record.value;
    }
}

int binary_search(Record *database, int size, char *key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(database[mid].key, key);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return NOT_FOUND;
}

void main() {
    Record database[MAX_SIZE];
    int size;

    printf("Enter the size of the database: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Error: database size exceeds maximum limit.\n");
        exit(1);
    }

    create_database(database, size);

    char key[100];
    while (1) {
        printf("\nEnter key to search: ");
        scanf("%s", key);
        int index = binary_search(database, size, key);
        if (index == NOT_FOUND) {
            printf("Key not found!\n");
        } else {
            printf("Value: %d\n", database[index].value);
        }
    }
}
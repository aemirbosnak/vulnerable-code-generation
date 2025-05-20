//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_KEY_SIZE 100

typedef struct {
    char key[MAX_KEY_SIZE];
    int value;
} record;

record records[MAX_RECORDS];
int num_records = 0;

int compare_keys(const void *a, const void *b) {
    return strcmp(((record *)a)->key, ((record *)b)->key);
}

int find_key(char *key) {
    record target;
    strcpy(target.key, key);

    record *result = bsearch(&target, records, num_records, sizeof(record), compare_keys);

    if (result == NULL) {
        return -1;
    } else {
        return result - records;
    }
}

int main() {
    // Load records from a file
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    while (!feof(fp)) {
        fscanf(fp, "%s %d", records[num_records].key, &records[num_records].value);
        num_records++;
    }

    fclose(fp);

    // Sort records by key
    qsort(records, num_records, sizeof(record), compare_keys);

    // Search for a specific key
    char *key = "key1";
    int index = find_key(key);

    if (index == -1) {
        printf("Key not found\n");
    } else {
        printf("Key found at index %d\n", index);
    }

    return EXIT_SUCCESS;
}
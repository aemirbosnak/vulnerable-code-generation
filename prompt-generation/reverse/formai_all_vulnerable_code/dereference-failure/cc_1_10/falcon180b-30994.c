//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_SIZE 1000

typedef struct {
    char *key;
    int value;
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

int compare_entries(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void add_entry(char *key, int value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached.\n");
        return;
    }

    entry_t *new_entry = &entries[num_entries];
    new_entry->key = strdup(key);
    new_entry->value = value;

    num_entries++;
}

void search_entries(char *key) {
    qsort(entries, num_entries, sizeof(entry_t), compare_entries);

    char *search_key = strdup(key);
    int result = bsearch(&search_key, entries, num_entries, sizeof(entry_t), compare_entries);

    if (result == -1) {
        printf("Entry not found.\n");
    } else {
        printf("Entry found with value %d.\n", entries[result].value);
    }

    free(search_key);
}

int main() {
    add_entry("apple", 1);
    add_entry("banana", 2);
    add_entry("cherry", 3);

    search_entries("banana");

    return 0;
}
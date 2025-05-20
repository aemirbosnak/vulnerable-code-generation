//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10000
#define MAX_ENTRY_SIZE 100

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
        printf("Error: Index is full.\n");
        return;
    }

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            entries[i].value = value;
            return;
        }
    }

    entries[num_entries].key = strdup(key);
    entries[num_entries].value = value;
    num_entries++;
}

int search_entry(char *key) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            return entries[i].value;
        }
    }

    return -1;
}

void delete_entry(char *key) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            free(entries[i].key);
            entries[i].key = NULL;
            entries[i].value = -1;
            num_entries--;
            return;
        }
    }
}

void print_entries() {
    qsort(entries, num_entries, sizeof(entry_t), compare_entries);

    printf("Index:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s -> %d\n", entries[i].key, entries[i].value);
    }
}

int main() {
    add_entry("apple", 1);
    add_entry("banana", 2);
    add_entry("cherry", 3);

    print_entries();

    int value = search_entry("banana");
    printf("Value of banana: %d\n", value);

    delete_entry("banana");

    print_entries();

    return 0;
}
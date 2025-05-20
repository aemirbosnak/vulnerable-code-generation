//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 100

typedef struct {
    char *key;
    int value;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *key, int value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Database is full!\n");
        return;
    }

    num_entries++;
    entries[num_entries - 1].key = strdup(key);
    entries[num_entries - 1].value = value;
}

void remove_entry(char *key) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            free(entries[i].key);
            entries[i] = entries[--num_entries];
            break;
        }
    }
}

void search_entry(char *key) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            printf("Value: %d\n", entries[i].value);
            return;
        }
    }

    printf("Entry not found!\n");
}

int main() {
    add_entry("apple", 5);
    add_entry("banana", 10);
    add_entry("orange", 15);

    search_entry("apple");
    search_entry("grape");

    remove_entry("banana");

    search_entry("banana");

    return 0;
}
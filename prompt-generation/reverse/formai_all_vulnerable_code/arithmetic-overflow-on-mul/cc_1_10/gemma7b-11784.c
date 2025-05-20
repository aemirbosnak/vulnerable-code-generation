//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1024

typedef struct Entry {
    char name[256];
    int index;
} Entry;

Entry entries[MAX_ENTRIES];

int hash(char *str) {
    int hash_value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash_value = (hash_value * 33) + str[i];
    }
    return hash_value;
}

int find_entry(char *name) {
    int hash_value = hash(name);
    Entry *entry = &entries[hash_value];
    while (entry->name[0] != '\0' && strcmp(entry->name, name) != 0) {
        entry++;
    }
    return entry->index;
}

void insert_entry(char *name) {
    int hash_value = hash(name);
    Entry *entry = &entries[hash_value];
    while (entry->name[0] != '\0') {
        entry++;
    }
    strcpy(entry->name, name);
    entry->index = MAX_ENTRIES - 1;
}

int main() {
    insert_entry("Claude Shannon");
    insert_entry("John von Neumann");
    insert_entry("Alan Turing");
    insert_entry("Richard Feynman");
    insert_entry("Stephen Hawking");

    int index = find_entry("Claude Shannon");
    printf("Index of Claude Shannon: %d\n", index);

    return 0;
}
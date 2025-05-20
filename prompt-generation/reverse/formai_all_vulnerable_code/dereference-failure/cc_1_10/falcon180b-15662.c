//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10000
#define MAX_ENTRY_LENGTH 100

typedef struct {
    char *key;
    int value;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *key, int value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached\n");
        return;
    }

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            entries[i].value = value;
            return;
        }
    }

    strncpy(entries[num_entries].key, key, MAX_ENTRY_LENGTH);
    entries[num_entries].key[MAX_ENTRY_LENGTH - 1] = '\0';
    entries[num_entries].value = value;
    num_entries++;
}

int get_value(char *key) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            return entries[i].value;
        }
    }
    return -1;
}

void print_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s: %d\n", entries[i].key, entries[i].value);
    }
}

int main() {
    add_entry("apple", 10);
    add_entry("banana", 20);
    add_entry("cherry", 30);

    print_entries();

    int value = get_value("banana");
    printf("Value of banana: %d\n", value);

    return 0;
}
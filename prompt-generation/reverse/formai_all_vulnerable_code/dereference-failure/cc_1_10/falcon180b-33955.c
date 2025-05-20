//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_SIZE 1000

typedef struct {
    char* key;
    int value;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

int binary_search(char* key) {
    int left = 0;
    int right = num_entries - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(entries[mid].key, key);

        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void add_entry(char* key, int value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: table is full.\n");
        return;
    }

    int index = binary_search(key);

    if (index >= 0) {
        printf("Entry already exists.\n");
        return;
    }

    strncpy(entries[num_entries].key, key, MAX_ENTRY_SIZE);
    entries[num_entries].key[MAX_ENTRY_SIZE - 1] = '\0';
    entries[num_entries].value = value;
    num_entries++;
}

int get_value(char* key) {
    int index = binary_search(key);

    if (index < 0) {
        printf("Entry not found.\n");
        return -1;
    }

    return entries[index].value;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s -> %d\n", entries[i].key, entries[i].value);
    }
}

int main() {
    add_entry("apple", 1);
    add_entry("banana", 2);
    add_entry("cherry", 3);

    print_entries();

    int value = get_value("banana");
    printf("Value of banana: %d\n", value);

    return 0;
}
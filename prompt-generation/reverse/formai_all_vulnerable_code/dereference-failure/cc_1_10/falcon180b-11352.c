//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 50

typedef struct {
    char *name;
    int age;
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

int compare_entries(const void *a, const void *b) {
    entry_t *entry_a = (entry_t *)a;
    entry_t *entry_b = (entry_t *)b;

    if (entry_a->age < entry_b->age) {
        return -1;
    } else if (entry_a->age > entry_b->age) {
        return 1;
    } else {
        return 0;
    }
}

void add_entry(const char *name, int age) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached.\n");
        return;
    }

    entry_t *entry = &entries[num_entries];
    strncpy(entry->name, name, MAX_ENTRY_SIZE);
    entry->age = age;
    num_entries++;
}

void print_entries() {
    qsort(entries, num_entries, sizeof(entry_t), compare_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("%s (%d)\n", entries[i].name, entries[i].age);
    }
}

int main() {
    add_entry("Alice", 25);
    add_entry("Bob", 30);
    add_entry("Charlie", 20);
    add_entry("David", 25);

    print_entries();

    return 0;
}
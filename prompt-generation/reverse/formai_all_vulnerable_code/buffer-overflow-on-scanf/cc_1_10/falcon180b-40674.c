//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50
#define MAX_NUMBER_SIZE 15
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_SIZE];
    char number[MAX_NUMBER_SIZE];
} entry_t;

int compare_names(const void *a, const void *b) {
    const entry_t *entry_a = (const entry_t *)a;
    const entry_t *entry_b = (const entry_t *)b;

    return strcmp(entry_a->name, entry_b->name);
}

int compare_numbers(const void *a, const void *b) {
    const entry_t *entry_a = (const entry_t *)a;
    const entry_t *entry_b = (const entry_t *)b;

    return strcmp(entry_a->number, entry_b->number);
}

void print_entry(const entry_t *entry) {
    printf("Name: %s\n", entry->name);
    printf("Number: %s\n", entry->number);
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;

    printf("Enter phone book entries (name, number):\n");
    while (num_entries < MAX_ENTRIES && scanf("%s %s", entries[num_entries].name, entries[num_entries].number) == 2) {
        num_entries++;
    }

    if (num_entries == 0) {
        printf("No entries found.\n");
        return 1;
    }

    printf("Sorting by name...\n");
    qsort(entries, num_entries, sizeof(entry_t), compare_names);

    for (int i = 0; i < num_entries; i++) {
        print_entry(&entries[i]);
    }

    printf("\nSorting by number...\n");
    qsort(entries, num_entries, sizeof(entry_t), compare_numbers);

    for (int i = 0; i < num_entries; i++) {
        print_entry(&entries[i]);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_ENTRIES 100

struct entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int compare_numbers(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void print_entry(const struct entry *entry) {
    printf("%s: %s\n", entry->name, entry->number);
}

int main() {
    int num_entries = 0;
    struct entry entries[MAX_ENTRIES];

    while (num_entries < MAX_ENTRIES) {
        printf("Enter a name (or type 'done' to finish): ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter a phone number: ");
        char number[MAX_NUMBER_LENGTH];
        scanf("%s", number);

        strncpy(entries[num_entries].name, name, MAX_NAME_LENGTH);
        strncpy(entries[num_entries].number, number, MAX_NUMBER_LENGTH);
        num_entries++;
    }

    printf("Sorting by name...\n");
    qsort(entries, num_entries, sizeof(struct entry), compare_names);
    for (int i = 0; i < num_entries; i++) {
        print_entry(&entries[i]);
    }

    printf("\nSorting by number...\n");
    qsort(entries, num_entries, sizeof(struct entry), compare_numbers);
    for (int i = 0; i < num_entries; i++) {
        print_entry(&entries[i]);
    }

    return 0;
}
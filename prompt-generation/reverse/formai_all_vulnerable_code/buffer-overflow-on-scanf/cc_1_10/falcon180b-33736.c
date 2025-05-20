//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[51];
    char phone[16];
} entry_t;

void add_entry(entry_t entries[], int *num_entries) {
    printf("Enter name (max 50 characters): ");
    scanf("%[^\n]s", entries[*num_entries].name);
    printf("Enter phone number (max 15 characters): ");
    scanf("%[^\n]s", entries[*num_entries].phone);
    (*num_entries)++;
}

void print_entry(const entry_t entry) {
    printf("%s: %s\n", entry.name, entry.phone);
}

void search_entry(const entry_t entries[], int num_entries, const char *name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            print_entry(entries[i]);
        }
    }
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;

    printf("Phone Book\n");
    while (num_entries < MAX_ENTRIES) {
        printf("1. Add entry\n2. Search entry\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry(entries, &num_entries);
            break;
        case 2:
            printf("Enter name to search: ");
            char name[51];
            scanf("%[^\n]s", name);
            search_entry(entries, num_entries, name);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
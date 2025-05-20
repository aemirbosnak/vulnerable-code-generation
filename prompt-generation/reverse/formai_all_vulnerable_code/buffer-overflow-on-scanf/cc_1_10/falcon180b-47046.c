//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

struct entry {
    char name[MAX_ENTRIES];
    char number[MAX_ENTRIES];
};

void add_entry(struct entry *entries, int num_entries) {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", entries[num_entries].number);
    num_entries++;
}

void search_entry(struct entry *entries, int num_entries) {
    char name[MAX_ENTRIES];
    printf("Enter name to search: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }
    printf("No entry found.\n");
}

void delete_entry(struct entry *entries, int num_entries) {
    char name[MAX_ENTRIES];
    printf("Enter name to delete: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i+1], sizeof(entries[i]) * (num_entries - i - 1));
            num_entries--;
            break;
        }
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry(entries, num_entries);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", entries[num_entries].name);
                search_entry(entries, num_entries);
                break;
            case 3:
                delete_entry(entries, num_entries);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 200

typedef struct {
    char name[50];
    char number[15];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);

    printf("Enter phone number: ");
    scanf("%s", entries[num_entries].number);

    num_entries++;
    printf("Entry added.\n");
}

void delete_entry() {
    if (num_entries == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int index;
    printf("Enter index of entry to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_entries) {
        memmove(&entries[index], &entries[index + 1], (num_entries - index - 1) * sizeof(entry_t));
        num_entries--;
        printf("Entry deleted.\n");
    } else {
        printf("Invalid index.\n");
    }
}

void search_entry() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Entry not found.\n");
    } else {
        printf("Name: %s\n", entries[index].name);
        printf("Number: %s\n", entries[index].number);
    }
}

int main() {
    int choice;

    do {
        printf("\nPhone Book\n");
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            delete_entry();
            break;
        case 3:
            search_entry();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH-1);
    scanf("%s", entries[num_entries].name);

    printf("Enter phone number (up to %d characters): ", MAX_NUMBER_LENGTH-1);
    scanf("%s", entries[num_entries].number);

    num_entries++;
    printf("Entry added successfully!\n");
}

void search_entry() {
    if (num_entries == 0) {
        printf("Phone book is empty!\n");
        return;
    }

    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\n", entries[i].name);
            printf("Phone number: %s\n", entries[i].number);
            return;
        }
    }

    printf("Entry not found!\n");
}

void delete_entry() {
    if (num_entries == 0) {
        printf("Phone book is empty!\n");
        return;
    }

    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", search_name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            memmove(&entries[i], &entries[i+1], sizeof(entry_t)*(num_entries-i-1));
            num_entries--;
            printf("Entry deleted successfully!\n");
            return;
        }
    }

    printf("Entry not found!\n");
}

int main() {
    int choice;
    do {
        printf("\nPhone Book\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            search_entry();
            break;
        case 3:
            delete_entry();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
    } while (choice!= 4);

    return 0;
}
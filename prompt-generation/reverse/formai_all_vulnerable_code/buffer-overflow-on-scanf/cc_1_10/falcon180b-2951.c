//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 64
#define MAX_NUMBER_LENGTH 16
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", entries[num_entries].name);

    printf("Enter phone number (up to %d characters): ", MAX_NUMBER_LENGTH - 1);
    scanf("%s", entries[num_entries].number);

    num_entries++;
}

void delete_entry() {
    if (num_entries == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Enter name to delete: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i+1], sizeof(entry_t) * (num_entries - i - 1));
            num_entries--;
            return;
        }
    }

    printf("Entry not found.\n");
}

void search_entry() {
    if (num_entries == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Enter name to search: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void list_entries() {
    if (num_entries == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    int choice;
    do {
        printf("Phone book:\n");
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. List entries\n5. Exit\n");
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
            list_entries();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}
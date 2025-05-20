//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_NUMBER_LEN 20
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Entry;

int num_entries = 0;
Entry entries[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);

    printf("Enter number: ");
    scanf("%s", entries[num_entries].number);

    num_entries++;
}

void search_entry() {
    char name[MAX_NAME_LEN];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry() {
    char name[MAX_NAME_LEN];

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            strcpy(entries[i].name, "");
            strcpy(entries[i].number, "");
            printf("Entry deleted.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

void view_entries() {
    for (int i = 0; i < num_entries; i++) {
        if (entries[i].name[0]!= '\0' && entries[i].number[0]!= '\0') {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
        }
    }
}

int main() {
    int choice;

    do {
        printf("Phone Book\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. View all entries\n5. Exit\n");
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
            view_entries();
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
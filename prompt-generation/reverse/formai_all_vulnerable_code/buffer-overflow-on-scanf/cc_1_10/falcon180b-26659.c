//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry;

void add_entry(entry entries[], int num_entries) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);

    printf("Enter phone number: ");
    scanf("%s", entries[num_entries].number);

    num_entries++;
}

void search_entry(entry entries[], int num_entries, char name[]) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\n", entries[i].name);
            printf("Number: %s\n", entries[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry(entry entries[], int num_entries) {
    int i;

    printf("Enter name to delete: ");
    scanf("%s", entries[num_entries - 1].name);

    for (i = 0; i < num_entries - 1; i++) {
        strcpy(entries[i].name, entries[i + 1].name);
        strcpy(entries[i].number, entries[i + 1].number);
    }

    num_entries--;
}

int main() {
    entry entries[MAX_ENTRIES];
    int num_entries = 0;

    printf("Welcome to the phone book!\n");

    while (1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_entries >= MAX_ENTRIES) {
                printf("Phone book is full!\n");
            } else {
                add_entry(entries, num_entries);
            }
            break;

        case 2:
            printf("Enter name to search: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);

            search_entry(entries, num_entries, name);
            break;

        case 3:
            if (num_entries == 0) {
                printf("Phone book is empty!\n");
            } else {
                delete_entry(entries, num_entries);
            }
            break;

        case 4:
            printf("Goodbye!\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
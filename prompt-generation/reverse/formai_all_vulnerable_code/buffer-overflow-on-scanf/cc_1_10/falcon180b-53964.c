//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

void add_entry(entry_t entries[], int num_entries) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full. ");
        return;
    }

    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);

    printf("Enter phone number: ");
    scanf("%s", entries[num_entries].number);

    num_entries++;
}

void delete_entry(entry_t entries[], int num_entries) {
    if (num_entries == 0) {
        printf("Phone book is empty. ");
        return;
    }

    printf("Enter name to delete: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i + 1], (num_entries - i - 1) * sizeof(entry_t));
            num_entries--;
            break;
        }
    }
}

void search_entry(entry_t entries[], int num_entries) {
    if (num_entries == 0) {
        printf("Phone book is empty. ");
        return;
    }

    printf("Enter name to search: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }

    printf("Name not found. ");
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("\nPhone book options:\n");
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry(entries, num_entries);
            break;
        case 2:
            delete_entry(entries, num_entries);
            break;
        case 3:
            search_entry(entries, num_entries);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. ");
        }
    }

    return 0;
}
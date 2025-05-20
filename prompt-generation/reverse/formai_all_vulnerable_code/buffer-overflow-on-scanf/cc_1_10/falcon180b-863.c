//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);

    printf("Enter number: ");
    scanf("%s", entries[num_entries].number);

    num_entries++;
}

void delete_entry() {
    int index;

    printf("Enter name to delete: ");
    scanf("%s", entries[0].name);

    for (index = 0; index < num_entries; index++) {
        if (strcmp(entries[index].name, entries[0].name) == 0) {
            break;
        }
    }

    if (index == num_entries) {
        printf("Entry not found.\n");
    } else {
        num_entries--;
        printf("Entry deleted.\n");
    }
}

void search_entry() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", name);

    int index;
    for (index = 0; index < num_entries; index++) {
        if (strcmp(entries[index].name, name) == 0) {
            printf("Number: %s\n", entries[index].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    int choice;

    do {
        printf("Phone Book\n");
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
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}
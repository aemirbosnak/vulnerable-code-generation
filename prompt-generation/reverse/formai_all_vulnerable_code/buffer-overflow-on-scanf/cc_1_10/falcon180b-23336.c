//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: inquisitive
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

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", phonebook[num_entries].name);

    printf("Enter phone number (up to %d characters): ", MAX_NUMBER_LENGTH - 1);
    scanf("%s", phonebook[num_entries].number);

    num_entries++;
}

void search_entry() {
    char search_name[MAX_NAME_LENGTH];

    printf("Enter name to search for: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].number);
            found = 1;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }
}

void delete_entry() {
    char search_name[MAX_NAME_LENGTH];

    printf("Enter name to delete: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            memset(&phonebook[i], 0, sizeof(entry_t));
            num_entries--;
            found = 1;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }
}

int main() {
    printf("Welcome to the phone book!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        int choice;
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
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: inquisitive
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

int num_entries = 0;
entry_t phonebook[MAX_ENTRIES];

void add_entry() {
    printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", phonebook[num_entries].name);

    printf("Enter phone number (up to %d characters): ", MAX_NUMBER_LENGTH - 1);
    scanf("%s", phonebook[num_entries].number);

    num_entries++;
    printf("Entry added successfully!\n");
}

void search_entry() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].number);
        }
    }
}

void delete_entry() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            memset(&phonebook[i], 0, sizeof(entry_t));
            num_entries--;
            printf("Entry deleted successfully!\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    int choice;
    do {
        printf("\nPhone Book\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
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
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}
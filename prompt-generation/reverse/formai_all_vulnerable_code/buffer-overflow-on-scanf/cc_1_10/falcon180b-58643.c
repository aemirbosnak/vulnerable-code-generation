//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

int num_entries = 0;
entry_t phonebook[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name (up to %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", phonebook[num_entries].name);

    printf("Enter number (up to %d characters): ", MAX_NUMBER_LEN - 1);
    scanf("%s", phonebook[num_entries].number);

    num_entries++;
    printf("Entry added.\n");
}

void search_entry() {
    char search_name[MAX_NAME_LEN];

    printf("Enter name to search: ");
    scanf("%s", search_name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry() {
    char search_name[MAX_NAME_LEN];

    printf("Enter name to delete: ");
    scanf("%s", search_name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].number, "");
            printf("Entry deleted.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

void view_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (phonebook[i].name[0]!= '\0' && phonebook[i].number[0]!= '\0') {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\nPhone Book\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. View entries\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
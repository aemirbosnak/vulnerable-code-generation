//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUMBER_LENGTH 20
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry;

entry phonebook[MAX_ENTRIES];
int num_entries = 0;

// Function to add a new entry to the phone book
void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter number: ");
    scanf("%s", phonebook[num_entries].number);

    num_entries++;

    printf("Entry added successfully.\n");
}

// Function to search for an entry in the phone book
void search_entry() {
    char search_name[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", search_name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Number: %s\n", phonebook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

// Function to delete an entry from the phone book
void delete_entry() {
    char delete_name[MAX_NAME_LENGTH];

    printf("Enter name to delete: ");
    scanf("%s", delete_name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, delete_name) == 0) {
            memset(&phonebook[i], 0, sizeof(entry));
            num_entries--;
            printf("Entry deleted successfully.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

// Function to display all entries in the phone book
void display_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Name: %s\n", phonebook[i].name);
        printf("Number: %s\n\n", phonebook[i].number);
    }
}

int main() {
    int choice;

    do {
        printf("---------------------\n");
        printf("Phone Book\n");
        printf("---------------------\n");

        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. Delete Entry\n");
        printf("4. Display Entries\n");
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
            display_entries();
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
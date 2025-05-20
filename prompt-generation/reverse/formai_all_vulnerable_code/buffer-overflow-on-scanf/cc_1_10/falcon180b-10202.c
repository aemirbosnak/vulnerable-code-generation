//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 40
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

int num_entries = 0;
entry_t phonebook[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Phone book is full.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            printf("Error: Name must only contain letters.\n");
            return;
        }
    }

    printf("Enter number: ");
    scanf("%s", number);
    for (int i = 0; i < strlen(number); i++) {
        if (!isdigit(number[i])) {
            printf("Error: Number must only contain digits.\n");
            return;
        }
    }

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);
    num_entries++;

    printf("Entry added successfully.\n");
}

void search_entry() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memmove(&phonebook[i], &phonebook[i + 1], (num_entries - i - 1) * sizeof(entry_t));
            num_entries--;
            printf("Entry deleted successfully.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    printf("Phone Book\n");
    printf("=========\n");

    while (1) {
        printf("\n1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
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
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
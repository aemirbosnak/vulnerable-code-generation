//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

int add_entry(const char* name, const char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return 1;
    }

    strncpy(phonebook[num_entries].name, name, MAX_NAME_LENGTH);
    strncpy(phonebook[num_entries].number, number, MAX_NUMBER_LENGTH);

    num_entries++;

    return 0;
}

int search_entry(const char* name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return 0;
        }
    }

    printf("Entry not found.\n");
    return 1;
}

int main() {
    char choice;

    printf("Welcome to the Phone Book!\n");
    printf("A - Add entry\n");
    printf("S - Search entry\n");
    printf("Q - Quit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case 'A':
            printf("Enter name: ");
            scanf(" %s", phonebook[num_entries].name);

            printf("Enter number: ");
            scanf(" %s", phonebook[num_entries].number);

            break;

        case 'S':
            printf("Enter name to search: ");
            scanf(" %s", phonebook[num_entries].name);

            search_entry(phonebook[num_entries].name);

            break;

        case 'Q':
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 15
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phonebook is full.\n");
        return;
    }

    printf("Enter name (up to %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", phonebook[num_entries].name);

    printf("Enter phone number (up to %d characters): ", MAX_NUMBER_LEN - 1);
    scanf("%s", phonebook[num_entries].number);

    num_entries++;
}

void search_entry() {
    char name[MAX_NAME_LEN];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
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
        if (strcmp(name, phonebook[i].name) == 0) {
            memmove(&phonebook[i], &phonebook[i + 1], (num_entries - i - 1) * sizeof(entry_t));
            num_entries--;
            printf("Entry deleted.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    printf("Phonebook\n");

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
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
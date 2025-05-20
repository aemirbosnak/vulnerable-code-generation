//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char number[15];
} entry;

entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry(void) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries].number);

    num_entries++;
    printf("Entry added successfully.\n");
}

void search_entry(void) {
    char name[50];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry(void) {
    char name[50];

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                strcpy(phonebook[j].name, phonebook[j + 1].name);
                strcpy(phonebook[j].number, phonebook[j + 1].number);
            }

            num_entries--;
            printf("Entry deleted successfully.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

int main(void) {
    int choice;

    do {
        printf("\nPhone Book\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        printf("Enter choice: ");
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
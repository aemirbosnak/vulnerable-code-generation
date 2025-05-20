//FormAI DATASET v1.0 Category: Phone Book ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[30];
    char phone_number[20];
};

int num_contacts = 0;  // number of contacts added to the phone book
struct Contact phone_book[MAX_CONTACTS];  // array to store phone book contacts

void add_contact() {
    if (num_contacts < MAX_CONTACTS) {
        // get user input for new contact
        printf("Enter name: ");
        scanf(" %[^\n]", phone_book[num_contacts].name);
        printf("Enter phone number: ");
        scanf(" %s", phone_book[num_contacts].phone_number);

        printf("Contact added successfully!\n");
        num_contacts++;
    }
    else {
        printf("Phone book is full! Unable to add new contact.\n");
    }
}

void search_contact() {
    char name[30];
    printf("Enter name to search: ");
    scanf(" %[^\n]", name);

    // search for matching contact by name
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(name, phone_book[i].name) == 0) {
            printf("%s: %s\n", phone_book[i].name, phone_book[i].phone_number);
            return;
        }
    }
    printf("Contact not found!\n");
}

void list_contacts() {
    if (num_contacts > 0) {
        printf("==========================\n");
        printf("Name\t\tPhone Number\n");
        printf("==========================\n");

        int i;
        for (i = 0; i < num_contacts; i++) {
            printf("%s\t\t%s\n", phone_book[i].name, phone_book[i].phone_number);
        }
        printf("==========================\n");
    }
    else {
        printf("Phone book is empty! No contacts to display.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n\nPhone Book\n");
        printf("===========\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. List Contacts\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // add new contact
                add_contact();
                break;
            case 2:  // search contact
                search_contact();
                break;
            case 3:  // list all contacts
                list_contacts();
                break;
            case 4:  // exit program
                printf("Exiting Phone Book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
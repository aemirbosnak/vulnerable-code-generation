//FormAI DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[30];
    char phone[15];
};

int addContact(struct Contact contacts[], int numContacts) {
    if (numContacts == MAX_CONTACTS) {
        printf("Unable to add contact. Phone book is full.\n");
        return numContacts;
    }

    struct Contact newContact;
    printf("Enter name: ");
    scanf("%s", newContact.name);
    printf("Enter phone number: ");
    scanf("%s", newContact.phone);

    contacts[numContacts] = newContact;
    numContacts++;

    printf("Contact added successfully!\n");
    return numContacts;
}

void displayContacts(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].phone);
    }
}

void searchContacts(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char searchName[30];
    printf("Enter name of contact to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("%s: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }

    printf("No contacts found with name '%s'\n", searchName);
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;

    int menuChoice = 0;
    while (menuChoice != 4) {
        printf("\nPhone Book\n");
        printf("-----------\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search for Contact\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                numContacts = addContact(contacts, numContacts);
                break;
            case 2:
                displayContacts(contacts, numContacts);
                break;
            case 3:
                searchContacts(contacts, numContacts);
                break;
            case 4:
                printf("Exiting Phone Book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} Contact;

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("The contact list is full!\n");
        return;
    }

    Contact newContact;
    printf("Enter name: ");
    getchar(); // consume newline left by previous input
    fgets(newContact.name, sizeof(newContact.name), stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // remove newline

    printf("Enter phone number: ");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // remove newline

    contacts[*count] = newContact;
    (*count)++;
    printf("Contact added!\n");
}

void viewContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\n--- Phone Book Contacts ---\n");
    for (int i = 0; i < count; i++) {
        printf("Contact %d: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
    printf("---------------------------\n");
}

void searchContact(Contact contacts[], int count) {
    char name[MAX_NAME_LEN];
    printf("Enter the contact name to search: ");
    getchar(); // consume the newline
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found - Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("No contact found with the name %s.\n", name);
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    do {
        printf("\n----- Phone Book Menu -----\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                viewContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                printf("Exiting the Phone Book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
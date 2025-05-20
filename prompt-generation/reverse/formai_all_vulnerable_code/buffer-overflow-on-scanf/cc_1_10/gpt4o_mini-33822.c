//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACT_NAME_LENGTH 50
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_CONTACT_NAME_LENGTH];
    char phone[15];
} Contact;

void addContact(Contact *contacts, int *count);
void viewContacts(Contact *contacts, int count);
void searchContact(Contact *contacts, int count);
void clearInputBuffer();

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear the input buffer to remove any trailing newline

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
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addContact(Contact *contacts, int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Cannot add more contacts, contact list is full.\n");
        return;
    }

    Contact newContact;
    printf("Enter contact name: ");
    fgets(newContact.name, MAX_CONTACT_NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline character

    printf("Enter phone number: ");
    fgets(newContact.phone, 15, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // Remove newline character

    contacts[*count] = newContact;
    (*count)++;
    printf("Contact added successfully.\n");
}

void viewContacts(Contact *contacts, int count) {
    if (count == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Contact %d: Name: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void searchContact(Contact *contacts, int count) {
    if (count == 0) {
        printf("No contacts to search through.\n");
        return;
    }

    char searchName[MAX_CONTACT_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, MAX_CONTACT_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline character

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(contacts[i].name, searchName) == 0) {
            printf("Contact found: Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer to remove any leftover characters
}
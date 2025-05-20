//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    struct Contact* next;
} Contact;

Contact* head = NULL;

void addContact() {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    if (!newContact) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]%*c", newContact->name);
    printf("Enter phone number: ");
    scanf(" %[^\n]%*c", newContact->phone);
    newContact->next = head;
    head = newContact;

    printf("Contact added successfully!\n");
}

void searchContact() {
    char searchName[NAME_LENGTH];
    int found = 0;

    printf("Enter name to search: ");
    scanf(" %[^\n]%*c", searchName);

    Contact* current = head;
    while (current != NULL) {
        if (strcasecmp(current->name, searchName) == 0) {
            printf("Name: %s, Phone: %s\n", current->name, current->phone);
            found = 1;
            break;
        }
        current = current->next;
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void viewContacts() {
    if (head == NULL) {
        printf("No contacts available.\n");
        return;
    }

    printf("Contact List:\n");
    Contact* current = head;
    while (current != NULL) {
        printf("Name: %s, Phone: %s\n", current->name, current->phone);
        current = current->next;
    }
}

void deleteContact() {
    char deleteName[NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf(" %[^\n]%*c", deleteName);

    Contact *current = head, *prev = NULL;
    while (current != NULL && strcasecmp(current->name, deleteName) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Contact not found.\n");
        return;
    }

    if (prev == NULL) {
        head = current->next; // Deleting the head
    } else {
        prev->next = current->next; // Skipping the current
    }
    free(current);
    printf("Contact deleted successfully.\n");
}

void freeContacts() {
    Contact* current = head;
    Contact* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

void displayMenu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. View All Contacts\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                viewContacts();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                freeContacts();
                printf("Exiting the Phone Book application. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
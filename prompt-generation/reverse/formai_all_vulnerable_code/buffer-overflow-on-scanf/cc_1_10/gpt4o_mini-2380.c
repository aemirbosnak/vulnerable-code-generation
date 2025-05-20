//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define PHONE_LEN 15

typedef struct Contact {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    struct Contact* next;
} Contact;

Contact* head = NULL;

void addContact() {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    if (newContact == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]s", newContact->name);
    printf("Enter phone number: ");
    scanf(" %[^\n]s", newContact->phone);
    newContact->next = head;
    head = newContact;

    printf("Contact added successfully!\n");
}

void displayContacts() {
    if (head == NULL) {
        printf("No contacts available!\n");
        return;
    }
    printf("\n--- Phone Book ---\n");
    Contact* current = head;
    while (current != NULL) {
        printf("Name: %s, Phone: %s\n", current->name, current->phone);
        current = current->next;
    }
    printf("------------------\n");
}

void searchContact() {
    char name[NAME_LEN];
    printf("Enter name to search: ");
    scanf(" %[^\n]s", name);
    
    Contact* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Found: Name: %s, Phone: %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("Contact not found!\n");
}

void deleteContact() {
    char name[NAME_LEN];
    printf("Enter name to delete: ");
    scanf(" %[^\n]s", name);
    
    Contact* current = head;
    Contact* previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Contact not found!\n");
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    printf("Contact deleted successfully!\n");
}

void freeContacts() {
    Contact* current = head;
    Contact* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                freeContacts();
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
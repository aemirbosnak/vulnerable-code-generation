//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define PHONE_LEN 15

// Structure for a contact
typedef struct Contact {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    struct Contact* next;
} Contact;

// Function prototypes
Contact* createContact(const char* name, const char* phone);
void addContact(Contact** head, const char* name, const char* phone);
void viewContacts(Contact* head);
Contact* searchContact(Contact* head, const char* name);
void deleteContact(Contact** head, const char* name);
void freeContacts(Contact* head);

int main() {
    Contact* phoneBook = NULL;
    int choice;
    char name[NAME_LEN], phone[PHONE_LEN];

    while (1) {
        printf("\n=== Phone Book Menu ===\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("=======================\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                addContact(&phoneBook, name, phone);
                printf("Contact added successfully.\n");
                break;

            case 2:
                printf("=== Contacts ===\n");
                viewContacts(phoneBook);
                break;

            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                Contact* foundContact = searchContact(phoneBook, name);
                if (foundContact) {
                    printf("Found: %s - %s\n", foundContact->name, foundContact->phone);
                } else {
                    printf("Contact not found.\n");
                }
                break;

            case 4:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteContact(&phoneBook, name);
                printf("Contact deleted if it existed.\n");
                break;

            case 5:
                freeContacts(phoneBook);
                printf("Exiting the phone book.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new contact
Contact* createContact(const char* name, const char* phone) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    if (newContact) {
        strncpy(newContact->name, name, NAME_LEN);
        strncpy(newContact->phone, phone, PHONE_LEN);
        newContact->next = NULL;
    }
    return newContact;
}

// Function to add a contact to the phone book
void addContact(Contact** head, const char* name, const char* phone) {
    Contact* newContact = createContact(name, phone);
    if (!newContact) return;

    if (*head == NULL) {
        *head = newContact;
    } else {
        newContact->next = *head;
        *head = newContact;
    }
}

// Function to view all contacts
void viewContacts(Contact* head) {
    if (head == NULL) {
        printf("No contacts found.\n");
        return;
    }
    Contact* current = head;
    while (current != NULL) {
        printf("Name: %s, Phone: %s\n", current->name, current->phone);
        current = current->next;
    }
}

// Function to search for a contact by name
Contact* searchContact(Contact* head, const char* name) {
    Contact* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Not found
}

// Function to delete a contact
void deleteContact(Contact** head, const char* name) {
    Contact* current = *head;
    Contact* previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) { // Contact found
        if (previous == NULL) { // Contact to delete is the head
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

// Function to free all contacts
void freeContacts(Contact* head) {
    Contact* current = head;
    while (current != NULL) {
        Contact* temp = current;
        current = current->next;
        free(temp);
    }
}
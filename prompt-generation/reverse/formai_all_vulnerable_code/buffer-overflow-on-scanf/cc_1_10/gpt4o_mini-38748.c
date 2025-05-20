//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for our contact
typedef struct Contact {
    char name[100];
    char email[100];
    struct Contact *next;
} Contact;

// Function to create a new contact
Contact* createContact(const char* name, const char* email) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    if (newContact == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newContact->name, name, sizeof(newContact->name));
    strncpy(newContact->email, email, sizeof(newContact->email));
    newContact->next = NULL;
    return newContact;
}

// Function to add a contact to the end of the list
void addContact(Contact** head, const char* name, const char* email) {
    Contact* newContact = createContact(name, email);
    if (*head == NULL) {
        *head = newContact;
    } else {
        Contact* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newContact;
    }
}

// Function to display all contacts
void displayContacts(Contact* head) {
    Contact* temp = head;
    printf("\nContacts List:\n");
    while (temp != NULL) {
        printf("Name: %s, Email: %s\n", temp->name, temp->email);
        temp = temp->next;
    }
}

// Function to delete a contact by name
void deleteContact(Contact** head, const char* name) {
    Contact* temp = *head, *prev = NULL;

    // If the head is the contact to delete
    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next; // Change head
        free(temp);         // Free old head
        return;
    }

    // Search for the contact to delete
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If the contact wasn't found
    if (temp == NULL) {
        printf("Contact not found.\n");
        return;
    }

    // Unlink the contact from the list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to find a contact by name
Contact* findContact(Contact* head, const char* name) {
    Contact* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Not found
}

// Function to free all contacts
void freeContacts(Contact* head) {
    Contact* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function for testing
int main() {
    Contact* contactsList = NULL;
    int choice;
    char name[100], email[100];

    do {
        printf("\n*** Contacts Management System ***\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Find Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Get user input

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addContact(&contactsList, name, email);
                break;
            case 2:
                displayContacts(contactsList);
                break;
            case 3:
                printf("Enter name of the contact to delete: ");
                scanf("%s", name);
                deleteContact(&contactsList, name);
                break;
            case 4:
                printf("Enter name of the contact to find: ");
                scanf("%s", name);
                Contact* foundContact = findContact(contactsList, name);
                if (foundContact) {
                    printf("Found Contact - Name: %s, Email: %s\n", foundContact->name, foundContact->email);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            case 5:
                printf("Exiting... Freeing contacts memory.\n");
                freeContacts(contactsList);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
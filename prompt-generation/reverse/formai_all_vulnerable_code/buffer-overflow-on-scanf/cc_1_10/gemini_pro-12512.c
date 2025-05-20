//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Structure to store a contact
typedef struct Contact {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

// Function to compare two contacts
int compareContacts(const void *a, const void *b) {
    return strcmp(((Contact *)a)->name, ((Contact *)b)->name);
}

// Function to print a contact
void printContact(Contact *contact) {
    printf("%-20s %-20s %-20s\n", contact->name, contact->phone, contact->email);
}

// Function to add a new contact
void addContact(Contact *contacts, int *numContacts) {
    // Get the contact details from the user
    printf("Enter name: ");
    scanf("%s", contacts[*numContacts].name);
    printf("Enter phone: ");
    scanf("%s", contacts[*numContacts].phone);
    printf("Enter email: ");
    scanf("%s", contacts[*numContacts].email);

    // Increment the number of contacts
    (*numContacts)++;
}

// Function to search for a contact
void searchContact(Contact *contacts, int numContacts) {
    // Get the search term from the user
    char searchTerm[50];
    printf("Enter search term: ");
    scanf("%s", searchTerm);

    // Search for the contact
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strstr(contacts[i].name, searchTerm) != NULL) {
            // Print the contact details
            printContact(&contacts[i]);
            found = 1;
        }
    }

    // If the contact was not found, print a message
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact
void deleteContact(Contact *contacts, int *numContacts) {
    // Get the name of the contact to be deleted
    char name[50];
    printf("Enter name of contact to be deleted: ");
    scanf("%s", name);

    // Search for the contact
    int found = 0;
    int index = -1;
    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            found = 1;
            index = i;
            break;
        }
    }

    // If the contact was found, delete it
    if (found) {
        // Shift the contacts after the deleted contact to the left
        for (int i = index; i < *numContacts - 1; i++) {
            contacts[i] = contacts[i + 1];
        }

        // Decrement the number of contacts
        (*numContacts)--;
    } else {
        // If the contact was not found, print a message
        printf("Contact not found.\n");
    }
}

// Function to print the phone book
void printPhoneBook(Contact *contacts, int numContacts) {
    // Print the header
    printf("%-20s %-20s %-20s\n", "Name", "Phone", "Email");

    // Print the contacts
    for (int i = 0; i < numContacts; i++) {
        printContact(&contacts[i]);
    }
}

// Main function
int main() {
    // Create an array of contacts
    Contact contacts[MAX_CONTACTS];

    // Initialize the number of contacts to 0
    int numContacts = 0;

    // Loop until the user quits
    int choice;
    do {
        // Print the menu
        printf("\n1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Delete a contact\n");
        printf("4. Print the phone book\n");
        printf("5. Quit\n");

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                searchContact(contacts, numContacts);
                break;
            case 3:
                deleteContact(contacts, &numContacts);
                break;
            case 4:
                printPhoneBook(contacts, numContacts);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
//FormAI DATASET v1.0 Category: Phone Book ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100 // Maximum number of contacts that can be stored

// Structure for storing a contact entry
struct Contact {
    char name[50];
    char phone[15];
};

// List of contacts
struct Contact phonebook[MAX_CONTACTS];

// Number of contacts currently in the phonebook
int numContacts = 0;

// Function prototypes
void addContact();
void displayContacts();
void searchContacts();
void deleteContact();

int main() {
    int choice;

    // Display menu and process user input until they choose to exit
    while (1) {
        printf("\n---Phonebook Menu---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contacts\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");

        // Get user choice and clear input buffer
        scanf("%d", &choice);
        fflush(stdin);

        switch(choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContacts();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function for adding a contact to the phonebook
void addContact() {
    printf("\n---Add Contact---\n");

    // Check if phonebook is already full
    if (numContacts == MAX_CONTACTS) {
        printf("Phonebook is full. Cannot add new contact.\n");
        return;
    }

    // Get name and phone number for the new contact
    printf("Enter name: ");
    fgets(phonebook[numContacts].name, 50, stdin);
    printf("Enter phone number: ");
    fgets(phonebook[numContacts].phone, 15, stdin);

    // Increment number of contacts and print success message
    numContacts++;
    printf("Contact added successfully.\n");
}

// Function for displaying all contacts in the phonebook
void displayContacts() {
    printf("\n---Display Contacts---\n");

    // Check if phonebook is empty
    if (numContacts == 0) {
        printf("Phonebook is empty.\n");
        return;
    }

    // Print header row
    printf("%-20s %-15s\n", "Name", "Phone Number");

    // Print each contact's name and phone number
    for (int i = 0; i < numContacts; i++) {
        printf("%-20s %-15s\n", phonebook[i].name, phonebook[i].phone);
    }
}

// Function for searching for a contact in the phonebook
void searchContacts() {
    printf("\n---Search Contacts---\n");

    char searchTerm[50];

    // Get search term from user
    printf("Enter name to search for: ");
    fgets(searchTerm, 50, stdin);

    // Remove newline character from end of search term
    searchTerm[strcspn(searchTerm, "\n")] = '\0';

    // Search for contact with matching name
    int matchFound = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phonebook[i].name, searchTerm) == 0) {
            printf("%-20s %-15s\n", phonebook[i].name, phonebook[i].phone);
            matchFound = 1;
        }
    }

    // Print message if no matching contact was found
    if (!matchFound) {
        printf("No matching contacts found.\n");
    }
}

// Function for deleting a contact from the phonebook
void deleteContact() {
    printf("\n---Delete Contact---\n");

    char searchTerm[50];

    // Get search term from user
    printf("Enter name of contact to delete: ");
    fgets(searchTerm, 50, stdin);

    // Remove newline character from end of search term
    searchTerm[strcspn(searchTerm, "\n")] = '\0';

    // Search for contact with matching name
    int matchFound = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phonebook[i].name, searchTerm) == 0) {
            // Remove contact by shifting all subsequent contacts earlier in the array
            for (int j = i + 1; j < numContacts; j++) {
                strcpy(phonebook[j-1].name, phonebook[j].name);
                strcpy(phonebook[j-1].phone, phonebook[j].phone);
            }

            // Decrement number of contacts and print success message
            numContacts--;
            printf("Contact deleted successfully.\n");
            matchFound = 1;
            break;
        }
    }

    // Print message if no matching contact was found
    if (!matchFound) {
        printf("No matching contacts found.\n");
    }
}
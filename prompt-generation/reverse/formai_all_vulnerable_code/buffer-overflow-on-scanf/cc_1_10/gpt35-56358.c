//FormAI DATASET v1.0 Category: Phone Book ; Style: multivariable
#include <stdio.h>
#include <string.h>

// Defining maximum number of contacts
#define MAX_CONTACTS 100

// Defining maximum length of name and phone number
#define NAME_LENGTH 50
#define PHONE_NUMBER_LENGTH 20

// Struct for each contact
struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_NUMBER_LENGTH];
};

// Array of contacts
struct Contact contacts[MAX_CONTACTS];

// Variable to keep track of number of contacts
int numContacts = 0;

// Function to add a new contact
void addContact(char name[], char phone[]) {
    // Checking if maximum number of contacts has been reached
    if (numContacts == MAX_CONTACTS) {
        printf("Error: Maximum number of contacts reached.\n");
        return;
    }
    // Creating new contact and adding to array
    struct Contact newContact;
    strcpy(newContact.name, name);
    strcpy(newContact.phone, phone);
    contacts[numContacts] = newContact;
    numContacts++;
}

// Function to search for a contact by name
void searchContact(char name[]) {
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact Found:\nName: %s\nPhone Number: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

// Function to display all contacts
void displayContacts() {
    printf("All Contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s\nPhone Number: %s\n\n", contacts[i].name, contacts[i].phone);
    }
    if (numContacts == 0) {
        printf("No contacts found.\n");
    }
}

int main() {
    while (1) {
        // Getting user input for menu option
        printf("Menu:\n1. Add Contact\n2. Search Contact\n3. Display All Contacts\n4. Exit\nEnter option (1-4): ");
        int option;
        scanf("%d", &option);
        
        if (option == 1) {
            // Getting user input for new contact information
            printf("Enter name: ");
            char name[NAME_LENGTH];
            scanf("%s", name);
            printf("Enter phone number: ");
            char phone[PHONE_NUMBER_LENGTH];
            scanf("%s", phone);
            // Adding new contact
            addContact(name, phone);
        }
        else if (option == 2) {
            // Getting user input for contact name to search
            printf("Enter name to search: ");
            char name[NAME_LENGTH];
            scanf("%s", name);
            // Searching for contact
            searchContact(name);
        }
        else if (option == 3) {
            // Displaying all contacts
            displayContacts();
        }
        else if (option == 4) {
            // Exiting program
            printf("Exiting program.\n");
            return 0;
        }
        else {
            printf("Invalid option. Please enter a number between 1 and 4.\n");
        }
    }
}
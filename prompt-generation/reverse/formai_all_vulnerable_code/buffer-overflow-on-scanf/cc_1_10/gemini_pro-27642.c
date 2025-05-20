//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a contact
typedef struct contact {
    char name[50];
    char number[20];
} contact;

// Function to add a contact
void addContact(contact *contacts, int *numContacts) {
    // Get the contact details from the user
    printf("Enter the name of the contact: ");
    scanf("%s", contacts[*numContacts].name);
    printf("Enter the phone number of the contact: ");
    scanf("%s", contacts[*numContacts].number);

    // Increment the number of contacts
    (*numContacts)++;
}

// Function to search for a contact
int searchContact(contact *contacts, int numContacts, char *name) {
    // Iterate over the contacts and search for the given name
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return i;
        }
    }

    // Return -1 if the contact is not found
    return -1;
}

// Function to delete a contact
void deleteContact(contact *contacts, int *numContacts, char *name) {
    // Search for the contact
    int index = searchContact(contacts, *numContacts, name);

    // If the contact is found, delete it
    if (index != -1) {
        for (int i = index; i < *numContacts - 1; i++) {
            contacts[i] = contacts[i + 1];
        }

        // Decrement the number of contacts
        (*numContacts)--;
    }
}

// Function to print the phone book
void printPhoneBook(contact *contacts, int numContacts) {
    // Iterate over the contacts and print their details
    for (int i = 0; i < numContacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].number);
    }
}

int main() {
    // Create an array of contacts
    contact contacts[100];

    // Initialize the number of contacts to 0
    int numContacts = 0;

    // Add some contacts to the phone book
    addContact(contacts, &numContacts);
    addContact(contacts, &numContacts);
    addContact(contacts, &numContacts);

    // Print the phone book
    printPhoneBook(contacts, numContacts);

    // Search for a contact
    char name[50];
    printf("Enter the name of the contact you want to search for: ");
    scanf("%s", name);
    int index = searchContact(contacts, numContacts, name);

    // If the contact is found, print their details
    if (index != -1) {
        printf("Contact found:\n");
        printf("Name: %s\n", contacts[index].name);
        printf("Phone number: %s\n", contacts[index].number);
    } else {
        printf("Contact not found.\n");
    }

    // Delete a contact
    printf("Enter the name of the contact you want to delete: ");
    scanf("%s", name);
    deleteContact(contacts, &numContacts, name);

    // Print the phone book
    printPhoneBook(contacts, numContacts);

    return 0;
}
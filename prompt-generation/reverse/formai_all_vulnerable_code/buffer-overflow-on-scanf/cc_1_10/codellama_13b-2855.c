//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: unmistakable
/*
 * A unique C phone book example program in a unmistakable style.
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store contact information
typedef struct {
    char name[256];
    char phone[20];
} Contact;

// Function to add a contact to the phone book
void addContact(Contact *contacts, int *numContacts, char *name, char *phone) {
    // Make sure there is space for the new contact
    if (*numContacts >= 100) {
        printf("Phone book is full.\n");
        return;
    }

    // Add the new contact to the end of the list
    strcpy(contacts[*numContacts].name, name);
    strcpy(contacts[*numContacts].phone, phone);
    (*numContacts)++;
}

// Function to find a contact in the phone book
int findContact(Contact *contacts, int numContacts, char *name) {
    // Loop through all contacts
    for (int i = 0; i < numContacts; i++) {
        // If the name matches, return the index
        if (strcmp(contacts[i].name, name) == 0) {
            return i;
        }
    }

    // If no match found, return -1
    return -1;
}

// Function to print all contacts in the phone book
void printContacts(Contact *contacts, int numContacts) {
    // Loop through all contacts
    for (int i = 0; i < numContacts; i++) {
        // Print the contact's name and phone number
        printf("%s: %s\n", contacts[i].name, contacts[i].phone);
    }
}

// Function to delete a contact from the phone book
void deleteContact(Contact *contacts, int *numContacts, int index) {
    // Check if the index is valid
    if (index < 0 || index >= *numContacts) {
        printf("Invalid index.\n");
        return;
    }

    // Shift all contacts after the deleted contact to the left
    for (int i = index; i < *numContacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    // Decrement the number of contacts
    (*numContacts)--;
}

int main() {
    // Declare variables
    Contact contacts[100];
    int numContacts = 0;
    char name[256];
    char phone[20];
    int index;

    // Loop until the user quits
    while (1) {
        // Print the menu
        printf("Phone Book\n");
        printf("1. Add Contact\n");
        printf("2. Find Contact\n");
        printf("3. Print Contacts\n");
        printf("4. Delete Contact\n");
        printf("5. Quit\n");

        // Get the user's input
        int choice;
        scanf("%d", &choice);

        // Handle the user's input
        switch (choice) {
            case 1:
                // Add a contact
                printf("Enter the name: ");
                scanf("%s", name);
                printf("Enter the phone number: ");
                scanf("%s", phone);
                addContact(contacts, &numContacts, name, phone);
                break;
            case 2:
                // Find a contact
                printf("Enter the name to find: ");
                scanf("%s", name);
                index = findContact(contacts, numContacts, name);
                if (index == -1) {
                    printf("Contact not found.\n");
                } else {
                    printf("Contact found at index %d.\n", index);
                }
                break;
            case 3:
                // Print all contacts
                printContacts(contacts, numContacts);
                break;
            case 4:
                // Delete a contact
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                deleteContact(contacts, &numContacts, index);
                break;
            case 5:
                // Quit the program
                return 0;
        }
    }

    return 0;
}
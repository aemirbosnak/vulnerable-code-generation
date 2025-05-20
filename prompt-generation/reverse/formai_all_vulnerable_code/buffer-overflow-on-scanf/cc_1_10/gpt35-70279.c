//FormAI DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold contact information
typedef struct {
    char name[30];
    char phone[15];
} Contact;

// Function to add a new contact
void addContact(Contact *book, int *numContacts) {
    if (*numContacts >= 100) { // Check if phone book is full
        printf("Phone book is full. Contact cannot be added.\n");
        return;
    }
    // Prompt user for contact information
    char name[30], phone[15];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", phone);
    // Create new contact
    Contact newContact;
    strcpy(newContact.name, name);
    strcpy(newContact.phone, phone);
    // Add new contact to phone book
    book[*numContacts] = newContact;
    *numContacts += 1;
    printf("Contact added successfully.\n");
}

// Function to remove a contact
void removeContact(Contact *book, int *numContacts) {
    if (*numContacts == 0) { // Check if phone book is empty
        printf("Phone book is empty. No contacts to remove.\n");
        return;
    }
    // Prompt user for contact name to remove
    char name[30];
    printf("Enter name to remove: ");
    scanf("%s", name);
    int i, j;
    for (i = 0; i < *numContacts; i++) {
        if (strcmp(book[i].name, name) == 0) { // If contact found, remove it
            for (j = i; j < *numContacts-1; j++) {
                book[j] = book[j+1];
            }
            *numContacts -= 1;
            printf("Contact removed successfully.\n");
            return;
        }
    }
    printf("Contact not found. Please try again.\n");
}

// Function to display all contacts
void displayContacts(Contact *book, int numContacts) {
    if (numContacts == 0) { // Check if phone book is empty
        printf("Phone book is empty. No contacts to display.\n");
        return;
    }
    printf("Phone Book:\n");
    int i;
    for (i = 0; i < numContacts; i++) {
        printf("%s: %s\n", book[i].name, book[i].phone);
    }
}

// Main function
int main() {
    Contact phoneBook[100];
    int numContacts = 0;
    int choice;
    while (1) { // Loop until user quits
        printf("\n1. Add Contact\n2. Remove Contact\n3. Display All Contacts\n4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: // Add contact
                addContact(phoneBook, &numContacts);
                break;
            case 2: // Remove contact
                removeContact(phoneBook, &numContacts);
                break;
            case 3: // Display all contacts
                displayContacts(phoneBook, numContacts);
                break;
            case 4: // Quit
                printf("Goodbye!\n");
                exit(0);
            default: // Invalid choice
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}
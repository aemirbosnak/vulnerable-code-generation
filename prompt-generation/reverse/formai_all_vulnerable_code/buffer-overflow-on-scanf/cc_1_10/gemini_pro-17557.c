//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a contact
typedef struct contact {
    char name[50];
    char phone[20];
} contact;

// Function to add a contact
void addContact(contact *contacts, int *numContacts) {
    // Get the name and phone number of the contact
    printf("Enter name: ");
    scanf("%s", contacts[*numContacts].name);
    printf("Enter phone: ");
    scanf("%s", contacts[*numContacts].phone);

    // Increment the number of contacts
    (*numContacts)++;
}

// Function to delete a contact
void deleteContact(contact *contacts, int *numContacts) {
    // Get the name of the contact to delete
    char name[50];
    printf("Enter name to delete: ");
    scanf("%s", name);

    // Find the contact to delete
    int index = -1;
    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If the contact was found, delete it
    if (index != -1) {
        for (int i = index; i < *numContacts - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        (*numContacts)--;
    } else {
        printf("Contact not found\n");
    }
}

// Function to search for a contact
void searchContact(contact *contacts, int numContacts) {
    // Get the name of the contact to search for
    char name[50];
    printf("Enter name to search for: ");
    scanf("%s", name);

    // Find the contact
    int index = -1;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If the contact was found, print it
    if (index != -1) {
        printf("Name: %s\n", contacts[index].name);
        printf("Phone: %s\n", contacts[index].phone);
    } else {
        printf("Contact not found\n");
    }
}

// Function to print all contacts
void printContacts(contact *contacts, int numContacts) {
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
    }
}

// Main function
int main() {
    // Initialize the phone book
    contact contacts[100];
    int numContacts = 0;

    // Get the user's choice
    int choice;
    do {
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Search for contact\n");
        printf("4. Print all contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                deleteContact(contacts, &numContacts);
                break;
            case 3:
                searchContact(contacts, numContacts);
                break;
            case 4:
                printContacts(contacts, numContacts);
                break;
        }
    } while (choice != 5);

    return 0;
}
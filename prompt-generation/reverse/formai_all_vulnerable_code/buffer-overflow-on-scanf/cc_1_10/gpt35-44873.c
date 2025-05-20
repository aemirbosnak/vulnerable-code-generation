//FormAI DATASET v1.0 Category: Phone Book ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts that can be stored
#define MAX_CONTACTS 10

// Define the structure for a contact
struct Contact {
    char name[30];
    char phone[15];
};

// Define a function to add a contact
void addContact(struct Contact* contacts, int numContacts) {
    if (numContacts >= MAX_CONTACTS) {
        printf("Cannot add more contacts.\n");
        return;
    }

    struct Contact* newContact = &contacts[numContacts];
    printf("Enter name: ");
    scanf("%s", newContact->name);
    printf("Enter phone number: ");
    scanf("%s", newContact->phone);
    printf("Contact added successfully.\n");
}

// Define a function to display all contacts
void displayContacts(struct Contact* contacts, int numContacts) {
    printf("Contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%s - %s\n", contacts[i].name, contacts[i].phone);
    }
}

// Define the main function
int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;

    while (1) {
        // Display the menu
        printf("\nEnter 1 to add contact\n");
        printf("Enter 2 to display all contacts\n");
        printf("Enter 3 to exit\n");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, numContacts++);
                break;
            case 2:
                displayContacts(contacts, numContacts);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
                break;
        }
    }

    return 0;
}
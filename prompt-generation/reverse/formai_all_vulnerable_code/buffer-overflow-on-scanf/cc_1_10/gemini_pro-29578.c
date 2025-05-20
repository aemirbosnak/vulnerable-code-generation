//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a contact
typedef struct Contact {
    char name[50];
    char number[20];
} Contact;

// Array to store the contacts
Contact contacts[100];

// Current number of contacts
int num_contacts = 0;

// Function to add a contact
void add_contact() {
    // Get the contact's name and number
    printf("Enter the contact's name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter the contact's number: ");
    scanf("%s", contacts[num_contacts].number);

    // Increment the number of contacts
    num_contacts++;
}

// Function to search for a contact
void search_contact() {
    // Get the contact's name
    char name[50];
    printf("Enter the contact's name: ");
    scanf("%s", name);

    // Search for the contact
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // Contact found
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Number: %s\n", contacts[i].number);
            return;
        }
    }

    // Contact not found
    printf("Contact not found.\n");
}

// Function to delete a contact
void delete_contact() {
    // Get the contact's name
    char name[50];
    printf("Enter the contact's name: ");
    scanf("%s", name);

    // Search for the contact
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // Contact found
            // Shift the contacts after the deleted contact to the left
            for (int j = i; j < num_contacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }

            // Decrement the number of contacts
            num_contacts--;

            // Contact deleted
            printf("Contact deleted.\n");
            return;
        }
    }

    // Contact not found
    printf("Contact not found.\n");
}

// Function to print all contacts
void print_contacts() {
    // Print the contacts
    for (int i = 0; i < num_contacts; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Number: %s\n", contacts[i].number);
        printf("\n");
    }
}

// Main function
int main() {
    // Welcome message
    printf("Welcome to the Phone Book!\n");

    // Loop until the user quits
    int choice;
    do {
        // Display the menu
        printf("Choose an option:\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Delete a contact\n");
        printf("4. Print all contacts\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                print_contacts();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}
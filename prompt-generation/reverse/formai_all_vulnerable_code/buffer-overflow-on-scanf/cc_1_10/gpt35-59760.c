//FormAI DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Structure for each contact in phone book
struct Contact {
    char name[50];
    char phone_number[20];
};

// Array of contacts in phone book
struct Contact contacts[MAX_CONTACTS];

// Keep track of number of contacts
int contact_count = 0;

// Function to add a new contact
void add_contact() {
    // Only allow addition if there is space in phone book
    if (contact_count == MAX_CONTACTS) {
        printf("Phone book full. Cannot add more contacts.\n");
        return;
    }

    // Get details of new contact
    struct Contact new_contact;
    printf("Enter name: ");
    fgets(new_contact.name, 50, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0; // Remove newline character
    printf("Enter phone number: ");
    fgets(new_contact.phone_number, 20, stdin);
    new_contact.phone_number[strcspn(new_contact.phone_number, "\n")] = 0; // Remove newline character

    // Add new contact to phone book
    contacts[contact_count] = new_contact;
    contact_count++;

    printf("Contact added successfully.\n");
}

// Function to search for a contact by name
void search_contact() {
    // Get name to search for
    char search_name[50];
    printf("Enter name to search for: ");
    fgets(search_name, 50, stdin);
    search_name[strcspn(search_name, "\n")] = 0; // Remove newline character

    // Search for contact with matching name
    int match_found = 0;
    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone number: %s\n", contacts[i].phone_number);
            match_found = 1;
            break;
        }
    }

    // Print message if contact not found
    if (!match_found) {
        printf("Contact not found.\n");
    }
}

// Function to print all contacts in phone book
void print_contacts() {
    printf("Contacts in phone book:\n");
    for (int i = 0; i < contact_count; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone number: %s\n", contacts[i].phone_number);
    }
}

// Main function to run phone book program
int main() {
    // Display menu and prompt user for choice
    int choice;
    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Print all contacts\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Remove extra newline character from input buffer

        // Perform action based on user choice
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                print_contacts();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
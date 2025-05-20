//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct {
    char name[50];
    char phone[20];
} contact;

// Create an array of contacts
contact contacts[MAX_CONTACTS];

// Initialize the number of contacts to 0
int num_contacts = 0;

// Function to add a new contact
void add_contact() {
    // Get the name of the contact
    printf("Enter the name of the contact: ");
    scanf("%s", contacts[num_contacts].name);

    // Get the phone number of the contact
    printf("Enter the phone number of the contact: ");
    scanf("%s", contacts[num_contacts].phone);

    // Increment the number of contacts
    num_contacts++;
}

// Function to search for a contact
void search_contact() {
    // Get the name of the contact to search for
    char name[50];
    printf("Enter the name of the contact to search for: ");
    scanf("%s", name);

    // Search for the contact
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // Contact found
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            return;
        }
    }

    // Contact not found
    printf("Contact not found.\n");
}

// Function to delete a contact
void delete_contact() {
    // Get the name of the contact to delete
    char name[50];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);

    // Search for the contact
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // Contact found
            // Shift the contacts after the deleted contact to the left
            for (int j = i + 1; j < num_contacts; j++) {
                contacts[j - 1] = contacts[j];
            }
            // Decrement the number of contacts
            num_contacts--;
            printf("Contact deleted.\n");
            return;
        }
    }

    // Contact not found
    printf("Contact not found.\n");
}

// Function to print all contacts
void print_contacts() {
    // Print the header
    printf("Contacts:\n");

    // Print the contacts
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].phone);
    }
}

// Main function
int main() {
    // Add some sample contacts
    add_contact("John Doe", "555-1212");
    add_contact("Jane Doe", "555-1213");
    add_contact("Bob Smith", "555-1214");

    // Print the contacts
    print_contacts();

    // Search for a contact
    search_contact();

    // Delete a contact
    delete_contact();

    // Print the contacts
    print_contacts();

    return 0;
}
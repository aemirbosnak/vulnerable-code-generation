//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a contact
typedef struct contact {
    char name[50];
    char number[20];
} Contact;

// Array to store the contacts
Contact contacts[100];

// Counter to keep track of the number of contacts
int num_contacts = 0;

// Function to add a new contact
void add_contact() {
    // Get the contact details from the user
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter number: ");
    scanf("%s", contacts[num_contacts].number);

    // Increment the number of contacts
    num_contacts++;
}

// Function to search for a contact
void search_contact() {
    // Get the name of the contact to search for
    char name[50];
    printf("Enter name to search for: ");
    scanf("%s", name);

    // Search for the contact
    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // Contact found
            printf("Name: %s\n", contacts[i].name);
            printf("Number: %s\n", contacts[i].number);
            found = 1;
            break;
        }
    }

    // If the contact was not found
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact
void delete_contact() {
    // Get the name of the contact to delete
    char name[50];
    printf("Enter name to delete: ");
    scanf("%s", name);

    // Search for the contact
    int found = 0;
    int index = -1;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // Contact found
            index = i;
            found = 1;
            break;
        }
    }

    // If the contact was not found
    if (!found) {
        printf("Contact not found.\n");
        return;
    }

    // Delete the contact
    for (int i = index; i < num_contacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    // Decrement the number of contacts
    num_contacts--;
}

// Function to print the phone book
void print_phone_book() {
    // Print the contacts
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Number: %s\n", contacts[i].number);
        printf("\n");
    }
}

// Main function
int main() {
    // Add some sample contacts
    add_contact("John Doe", "555-123-4567");
    add_contact("Jane Doe", "555-234-5678");
    add_contact("John Smith", "555-345-6789");

    // Print the phone book
    print_phone_book();

    // Add a new contact
    add_contact();

    // Print the phone book
    print_phone_book();

    // Search for a contact
    search_contact();

    // Delete a contact
    delete_contact();

    // Print the phone book
    print_phone_book();

    return 0;
}
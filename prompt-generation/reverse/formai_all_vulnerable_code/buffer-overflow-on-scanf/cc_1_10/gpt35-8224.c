//FormAI DATASET v1.0 Category: Phone Book ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 10000

// Define a structure to represent a contact
typedef struct {
    char name[50];
    char phone_number[15];
    char email[50];
} contact_t;

// Define an array to hold all the contacts
contact_t phone_book[MAX_CONTACTS];

// Keep track of the number of contacts that have been added
int num_contacts = 0;

// Function to add a new contact to the phone book
void add_contact() {
    // Check if the phone book is full
    if (num_contacts == MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    // Prompt the user for the contact information
    printf("Enter the name: ");
    scanf("%s", phone_book[num_contacts].name);

    printf("Enter the phone number (format: xxx-xxx-xxxx): ");
    scanf("%s", phone_book[num_contacts].phone_number);

    printf("Enter the email address: ");
    scanf("%s", phone_book[num_contacts].email);

    // Increment the number of contacts
    num_contacts++;

    // Print a message to confirm the contact was added
    printf("Contact added to phone book.\n");
}

// Function to search for a contact by name
void search_contact() {
    // Prompt the user for the name to search for
    char search_name[50];
    printf("Enter the name to search for: ");
    scanf("%s", search_name);

    // Loop through all the contacts and look for a match
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(search_name, phone_book[i].name) == 0) {
            // Print out the contact information
            printf("Name: %s\n", phone_book[i].name);
            printf("Phone Number: %s\n", phone_book[i].phone_number);
            printf("Email Address: %s\n", phone_book[i].email);
            return; // Exit the function after finding the first match
        }
    }

    // If we get here, we didn't find a match
    printf("Contact not found.\n");
}

// Function to display all contacts in the phone book
void display_contacts() {
    // Loop through all the contacts and print out their information
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", phone_book[i].name);
        printf("Phone Number: %s\n", phone_book[i].phone_number);
        printf("Email Address: %s\n", phone_book[i].email);
        printf("\n");
    }
}

// Main program loop
int main() {
    while (1) {
        // Print the main menu
        printf("Main Menu\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Exit\n");

        // Prompt the user for a menu choice
        int choice;
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                display_contacts();
                break;
            case 4:
                printf("Exiting phone book program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}
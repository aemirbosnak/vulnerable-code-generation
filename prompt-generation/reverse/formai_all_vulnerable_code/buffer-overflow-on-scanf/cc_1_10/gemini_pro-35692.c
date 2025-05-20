//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct contact {
    char name[50];
    char phone[20];
    char email[50];
} contact;

// Create an array of contacts
contact contacts[MAX_CONTACTS];

// Define the number of contacts
int num_contacts = 0;

// Function to add a new contact
void add_contact() {
    // Check if the maximum number of contacts has been reached
    if (num_contacts == MAX_CONTACTS) {
        printf("Sorry, the maximum number of contacts has been reached.\n");
        return;
    }

    // Get the contact details from the user
    printf("Enter the name of the contact: ");
    gets(contacts[num_contacts].name);
    printf("Enter the phone number of the contact: ");
    gets(contacts[num_contacts].phone);
    printf("Enter the email address of the contact: ");
    gets(contacts[num_contacts].email);

    // Increment the number of contacts
    num_contacts++;
}

// Function to search for a contact
void search_contact() {
    // Get the search term from the user
    char search_term[50];
    printf("Enter the search term: ");
    gets(search_term);

    // Search for the contact
    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strstr(contacts[i].name, search_term) != NULL) {
            // Contact found
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
            break;
        }
    }

    // If the contact was not found
    if (!found) {
        printf("Sorry, no contact found with the search term '%s'.\n", search_term);
    }
}

// Function to display all contacts
void display_contacts() {
    // Check if there are any contacts
    if (num_contacts == 0) {
        printf("Sorry, there are no contacts to display.\n");
        return;
    }

    // Display the contacts
    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s\n", i + 1, contacts[i].name);
    }
}

// Main function
int main() {
    // Display the menu
    printf("Welcome to the Phone Book!\n");
    printf("1. Add a new contact\n");
    printf("2. Search for a contact\n");
    printf("3. Display all contacts\n");
    printf("4. Exit\n");

    // Get the user's choice
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Loop until the user chooses to exit
    while (choice != 4) {
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
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }

        // Display the menu again
        printf("\nWelcome to the Phone Book!\n");
        printf("1. Add a new contact\n");
        printf("2. Search for a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    // Exit the program
    printf("Thank you for using the Phone Book!\n");
    return 0;
}
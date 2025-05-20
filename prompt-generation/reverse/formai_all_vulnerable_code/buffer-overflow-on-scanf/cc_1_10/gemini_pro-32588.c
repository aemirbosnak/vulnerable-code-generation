//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct {
    char name[50];
    char phone_number[20];
    char email[50];
} Contact;

// Function to add a contact to the phone book
void add_contact(Contact *phone_book, int *num_contacts) {
    // Get the contact's name, phone number, and email
    printf("Enter the contact's name: ");
    scanf(" %[^\n]%*c", phone_book[*num_contacts].name);

    printf("Enter the contact's phone number: ");
    scanf(" %[^\n]%*c", phone_book[*num_contacts].phone_number);

    printf("Enter the contact's email: ");
    scanf(" %[^\n]%*c", phone_book[*num_contacts].email);

    // Increment the number of contacts
    (*num_contacts)++;
}

// Function to search for a contact in the phone book
void search_contact(Contact *phone_book, int num_contacts) {
    // Get the contact's name to search for
    char search_name[50];
    printf("Enter the contact's name to search for: ");
    scanf(" %[^\n]%*c", search_name);

    // Search for the contact
    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, search_name) == 0) {
            // Contact found
            printf("Contact found:\n");
            printf("Name: %s\n", phone_book[i].name);
            printf("Phone number: %s\n", phone_book[i].phone_number);
            printf("Email: %s\n", phone_book[i].email);
            found = 1;
            break;
        }
    }

    // If the contact was not found
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact from the phone book
void delete_contact(Contact *phone_book, int *num_contacts) {
    // Get the contact's name to delete
    char delete_name[50];
    printf("Enter the contact's name to delete: ");
    scanf(" %[^\n]%*c", delete_name);

    // Search for the contact
    int found = 0;
    int index = -1;
    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp(phone_book[i].name, delete_name) == 0) {
            // Contact found
            found = 1;
            index = i;
            break;
        }
    }

    // If the contact was not found
    if (!found) {
        printf("Contact not found.\n");
        return;
    }

    // Delete the contact
    for (int i = index; i < *num_contacts - 1; i++) {
        phone_book[i] = phone_book[i + 1];
    }

    // Decrement the number of contacts
    (*num_contacts)--;
}

// Function to print the phone book
void print_phone_book(Contact *phone_book, int num_contacts) {
    // Print the header
    printf("Phone Book:\n");
    printf("==================================================================================\n");
    printf("| Name | Phone Number | Email |\n");
    printf("----------------------------------------------------------------------------------\n");

    // Print the contacts
    for (int i = 0; i < num_contacts; i++) {
        printf("| %-25s | %-15s | %-25s |\n",
            phone_book[i].name,
            phone_book[i].phone_number,
            phone_book[i].email);
    }

    // Print the footer
    printf("==================================================================================\n");
}

// Main function
int main() {
    // Create the phone book
    Contact phone_book[MAX_CONTACTS];

    // Initialize the number of contacts to 0
    int num_contacts = 0;

    // Run the main loop
    int choice;
    do {
        // Print the menu
        printf("\nPhone Book Management System\n");
        printf("===========================\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Delete a contact\n");
        printf("4. Print the phone book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                add_contact(phone_book, &num_contacts);
                break;
            case 2:
                search_contact(phone_book, num_contacts);
                break;
            case 3:
                delete_contact(phone_book, &num_contacts);
                break;
            case 4:
                print_phone_book(phone_book, num_contacts);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
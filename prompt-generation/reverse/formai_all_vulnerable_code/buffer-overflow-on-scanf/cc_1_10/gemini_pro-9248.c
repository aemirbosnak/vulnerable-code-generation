//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a contact
typedef struct contact {
    char name[50];
    char number[20];
} contact;

// Function to print a contact
void print_contact(contact c) {
    printf("%s: %s\n", c.name, c.number);
}

// Function to add a contact to the phone book
void add_contact(contact *phone_book, int *num_contacts) {
    // Get the name and number of the contact
    printf("Enter the name of the contact: ");
    scanf(" %[^\n]%*c", phone_book[*num_contacts].name);
    printf("Enter the number of the contact: ");
    scanf(" %[^\n]%*c", phone_book[*num_contacts].number);

    // Increment the number of contacts
    (*num_contacts)++;
}

// Function to search for a contact in the phone book
void search_contact(contact *phone_book, int num_contacts) {
    // Get the name of the contact to search for
    char name[50];
    printf("Enter the name of the contact to search for: ");
    scanf(" %[^\n]%*c", name);

    // Search for the contact
    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            // Contact found
            print_contact(phone_book[i]);
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
void delete_contact(contact *phone_book, int *num_contacts) {
    // Get the name of the contact to delete
    char name[50];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]%*c", name);

    // Search for the contact
    int found = 0;
    int index = -1;
    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
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
void print_phone_book(contact *phone_book, int num_contacts) {
    printf("Phone Book:\n");
    for (int i = 0; i < num_contacts; i++) {
        print_contact(phone_book[i]);
    }
}

// Main function
int main() {
    // Create the phone book
    contact phone_book[100];

    // Initialize the number of contacts to 0
    int num_contacts = 0;

    // Main loop
    while (1) {
        // Print the menu
        printf("\nPhone Book Menu:\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Delete a contact\n");
        printf("4. Print the phone book\n");
        printf("5. Quit\n");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

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
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
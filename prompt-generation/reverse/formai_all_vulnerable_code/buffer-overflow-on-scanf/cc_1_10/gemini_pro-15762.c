//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts in the phone book
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct contact{
    char name[50];
    char phone_number[20];
    char email[50];
} contact;

// Initialize the phone book with some sample contacts
contact phone_book[MAX_CONTACTS] = {
    {"John Doe", "555-1234", "john.doe@example.com"},
    {"Jane Doe", "555-5678", "jane.doe@example.com"},
    {"Bob Smith", "555-9876", "bob.smith@example.com"}
};

// Get the number of contacts in the phone book
int get_num_contacts() {
    int num_contacts = 0;
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (strlen(phone_book[i].name) > 0) {
            num_contacts++;
        }
    }
    return num_contacts;
}

// Print the phone book
void print_phone_book() {
    int num_contacts = get_num_contacts();
    printf("Phone Book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s, %s\n", phone_book[i].name, phone_book[i].phone_number, phone_book[i].email);
    }
}

// Add a new contact to the phone book
void add_contact() {
    int num_contacts = get_num_contacts();
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    // Get the contact information from the user
    printf("Enter the contact's name: ");
    scanf(" %[^\n]", phone_book[num_contacts].name);

    printf("Enter the contact's phone number: ");
    scanf(" %[^\n]", phone_book[num_contacts].phone_number);

    printf("Enter the contact's email: ");
    scanf(" %[^\n]", phone_book[num_contacts].email);

    printf("Contact added!\n");
}

// Delete a contact from the phone book
void delete_contact() {
    int num_contacts = get_num_contacts();

    // Get the name of the contact to delete from the user
    char name_to_delete[50];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]", name_to_delete);

    // Find the contact to delete
    int contact_index = -1;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name_to_delete) == 0) {
            contact_index = i;
            break;
        }
    }

    // If the contact was found, delete it
    if (contact_index != -1) {
        for (int i = contact_index; i < num_contacts - 1; i++) {
            phone_book[i] = phone_book[i + 1];
        }

        printf("Contact deleted!\n");
    } else {
        printf("Contact not found!\n");
    }
}

// Search for a contact in the phone book
void search_contact() {
    int num_contacts = get_num_contacts();

    // Get the name of the contact to search for from the user
    char name_to_search[50];
    printf("Enter the name of the contact to search for: ");
    scanf(" %[^\n]", name_to_search);

    // Find the contact
    int contact_index = -1;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name_to_search) == 0) {
            contact_index = i;
            break;
        }
    }

    // If the contact was found, print it
    if (contact_index != -1) {
        printf("Contact found:\n");
        printf("%s: %s, %s\n", phone_book[contact_index].name, phone_book[contact_index].phone_number, phone_book[contact_index].email);
    } else {
        printf("Contact not found!\n");
    }
}

// Main function
int main() {
    // Print the welcome message
    printf("Welcome to the phone book!\n");

    // Loop until the user exits the program
    int choice;
    do {
        // Print the menu
        printf("\nPlease select an option:\n");
        printf("1. Print phone book\n");
        printf("2. Add contact\n");
        printf("3. Delete contact\n");
        printf("4. Search contact\n");
        printf("5. Exit\n");

        // Get the user's choice
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                print_phone_book();
                break;
            case 2:
                add_contact();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                search_contact();
                break;
        }
    } while (choice != 5);

    // Print the goodbye message
    printf("\nGoodbye!\n");

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct contact {
    char name[50];
    char phone_number[20];
} contact;

// Function to add a new contact to the phone book
void add_contact(contact phone_book[], int *num_contacts) {
    // Get the name and phone number of the new contact
    printf("Enter the name of the new contact: ");
    scanf("%s", phone_book[*num_contacts].name);
    printf("Enter the phone number of the new contact: ");
    scanf("%s", phone_book[*num_contacts].phone_number);

    // Increment the number of contacts
    (*num_contacts)++;
}

// Function to search for a contact in the phone book
void search_contact(contact phone_book[], int num_contacts) {
    // Get the name of the contact to search for
    char name[50];
    printf("Enter the name of the contact to search for: ");
    scanf("%s", name);

    // Search for the contact
    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            // Contact found
            printf("Contact found:\n");
            printf("Name: %s\n", phone_book[i].name);
            printf("Phone number: %s\n", phone_book[i].phone_number);
            found = 1;
            break;
        }
    }

    // If the contact was not found, print an error message
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact from the phone book
void delete_contact(contact phone_book[], int *num_contacts) {
    // Get the name of the contact to delete
    char name[50];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);

    // Search for the contact
    int found = 0;
    int index = -1;
    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            // Contact found
            index = i;
            found = 1;
            break;
        }
    }

    // If the contact was not found, print an error message
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
void print_phone_book(contact phone_book[], int num_contacts) {
    // Print the header
    printf("Phone Book:\n");
    printf("---------------------\n");

    // Print the contacts
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t%s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

// Main function
int main() {
    // Create the phone book
    contact phone_book[MAX_CONTACTS];

    // Initialize the number of contacts to 0
    int num_contacts = 0;

    // Add some contacts to the phone book
    add_contact(phone_book, &num_contacts);
    add_contact(phone_book, &num_contacts);
    add_contact(phone_book, &num_contacts);

    // Print the phone book
    print_phone_book(phone_book, num_contacts);

    // Search for a contact in the phone book
    search_contact(phone_book, num_contacts);

    // Delete a contact from the phone book
    delete_contact(phone_book, &num_contacts);

    // Print the phone book again
    print_phone_book(phone_book, num_contacts);

    return 0;
}
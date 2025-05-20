//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct contact {
    char name[50];
    char phone_number[20];
    char email[50];
} contact;

// Create an array of contacts
contact contacts[MAX_CONTACTS];

// Get the number of contacts from the user
int get_num_contacts() {
    int num_contacts;
    printf("Enter the number of contacts you want to store: ");
    scanf("%d", &num_contacts);
    return num_contacts;
}

// Get the details of a contact from the user
void get_contact_details(contact *contact) {
    printf("Enter the name of the contact: ");
    scanf(" %[^\n]%*c", contact->name); // Read a string with spaces
    printf("Enter the phone number of the contact: ");
    scanf("%s", contact->phone_number);
    printf("Enter the email address of the contact: ");
    scanf(" %[^\n]%*c", contact->email); // Read a string with spaces
}

// Add a contact to the array of contacts
void add_contact(int *num_contacts, contact *contact) {
    contacts[*num_contacts] = *contact;
    (*num_contacts)++;
}

// Search for a contact in the array of contacts
contact* search_contact(char *name) {
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return &contacts[i];
        }
    }
    return NULL;
}

// Print the details of a contact
void print_contact(contact *contact) {
    printf("Name: %s\n", contact->name);
    printf("Phone number: %s\n", contact->phone_number);
    printf("Email address: %s\n", contact->email);
}

// Print the details of all contacts
void print_all_contacts(int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        print_contact(&contacts[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Get the number of contacts from the user
    int num_contacts = get_num_contacts();

    // Get the details of each contact from the user
    for (int i = 0; i < num_contacts; i++) {
        printf("Enter the details of contact %d:\n", i + 1);
        get_contact_details(&contacts[i]);
    }

    // Search for a contact by name
    char name[50];
    printf("Enter the name of the contact you want to search for: ");
    scanf(" %[^\n]%*c", name); // Read a string with spaces
    contact *contact = search_contact(name);

    // Print the details of the contact
    if (contact != NULL) {
        print_contact(contact);
    } else {
        printf("Contact not found.\n");
    }

    // Print the details of all contacts
    printf("\nAll contacts:\n");
    print_all_contacts(num_contacts);

    return 0;
}
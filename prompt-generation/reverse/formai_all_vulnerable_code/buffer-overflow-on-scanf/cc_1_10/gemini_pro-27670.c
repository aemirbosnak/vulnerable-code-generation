//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: all-encompassing
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
    printf("Enter the number of contacts: ");
    scanf("%d", &num_contacts);
    return num_contacts;
}

// Get the contact information from the user
void get_contact_info(contact *c) {
    printf("Enter the contact's name: ");
    scanf("%s", c->name);
    printf("Enter the contact's phone number: ");
    scanf("%s", c->phone_number);
    printf("Enter the contact's email address: ");
    scanf("%s", c->email);
}

// Print the contact information
void print_contact(contact *c) {
    printf("Name: %s\n", c->name);
    printf("Phone number: %s\n", c->phone_number);
    printf("Email address: %s\n", c->email);
}

// Search for a contact by name
contact* search_contact(char *name) {
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return &contacts[i];
        }
    }
    return NULL;
}

// Delete a contact by name
void delete_contact(char *name) {
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < MAX_CONTACTS - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            break;
        }
    }
}

// Print the phone book
void print_phone_book() {
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (strlen(contacts[i].name) > 0) {
            print_contact(&contacts[i]);
            printf("\n");
        }
    }
}

// Main function
int main() {
    // Get the number of contacts from the user
    int num_contacts = get_num_contacts();

    // Get the contact information from the user
    for (int i = 0; i < num_contacts; i++) {
        get_contact_info(&contacts[i]);
    }

    // Print the phone book
    print_phone_book();

    // Search for a contact by name
    char name[50];
    printf("Enter the name of the contact to search for: ");
    scanf("%s", name);
    contact *c = search_contact(name);
    if (c != NULL) {
        print_contact(c);
    } else {
        printf("Contact not found.\n");
    }

    // Delete a contact by name
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);
    delete_contact(name);

    // Print the phone book
    print_phone_book();

    return 0;
}
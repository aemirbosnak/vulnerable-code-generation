//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct {
    char name[50];
    char phone_number[20];
} contact;

// Create an array of contacts
contact contacts[MAX_CONTACTS];

// Get the number of contacts from the user
int get_num_contacts() {
    int num_contacts;
    printf("How many contacts do you want to enter? ");
    scanf("%d", &num_contacts);
    return num_contacts;
}

// Get the contact information from the user
void get_contact_info(contact *c) {
    printf("Enter the contact's name: ");
    scanf("%s", c->name);
    printf("Enter the contact's phone number: ");
    scanf("%s", c->phone_number);
}

// Print the contact information
void print_contact(contact *c) {
    printf("Name: %s\n", c->name);
    printf("Phone number: %s\n\n", c->phone_number);
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

// Main function
int main() {
    // Get the number of contacts from the user
    int num_contacts = get_num_contacts();

    // Get the contact information from the user
    for (int i = 0; i < num_contacts; i++) {
        get_contact_info(&contacts[i]);
    }

    // Print the contact information
    for (int i = 0; i < num_contacts; i++) {
        print_contact(&contacts[i]);
    }

    // Search for a contact by name
    char name[50];
    printf("Enter the name of the contact you want to search for: ");
    scanf("%s", name);
    contact *c = search_contact(name);
    if (c != NULL) {
        print_contact(c);
    } else {
        printf("Contact not found.\n");
    }

    return 0;
}
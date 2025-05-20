//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a contact
typedef struct contact {
    char name[50];
    char number[20];
    char email[50];
} contact;

// Function to compare two contacts
int compare_contacts(const void *a, const void *b) {
    contact *contact1 = (contact *)a;
    contact *contact2 = (contact *)b;
    return strcmp(contact1->name, contact2->name);
}

// Function to print a contact
void print_contact(contact *contact) {
    printf("Name: %s\n", contact->name);
    printf("Number: %s\n", contact->number);
    printf("Email: %s\n\n", contact->email);
}

// Function to add a contact
void add_contact(contact **contacts, int *num_contacts) {
    // Allocate memory for the new contact
    contact *new_contact = (contact *)malloc(sizeof(contact));

    // Get the contact's name, number, and email
    printf("Enter the contact's name: ");
    scanf("%s", new_contact->name);
    printf("Enter the contact's number: ");
    scanf("%s", new_contact->number);
    printf("Enter the contact's email: ");
    scanf("%s", new_contact->email);

    // Add the new contact to the array of contacts
    contacts[*num_contacts] = new_contact;
    (*num_contacts)++;
}

// Function to search for a contact
void search_contact(contact **contacts, int num_contacts) {
    // Get the contact's name
    char name[50];
    printf("Enter the contact's name: ");
    scanf("%s", name);

    // Search for the contact
    contact *found_contact = NULL;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i]->name, name) == 0) {
            found_contact = contacts[i];
            break;
        }
    }

    // Print the contact if it was found
    if (found_contact != NULL) {
        print_contact(found_contact);
    } else {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact
void delete_contact(contact **contacts, int *num_contacts) {
    // Get the contact's name
    char name[50];
    printf("Enter the contact's name: ");
    scanf("%s", name);

    // Search for the contact
    int index = -1;
    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i]->name, name) == 0) {
            index = i;
            break;
        }
    }

    // Delete the contact if it was found
    if (index != -1) {
        free(contacts[index]);
        for (int i = index; i < *num_contacts - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        (*num_contacts)--;
    } else {
        printf("Contact not found.\n");
    }
}

// Function to print the phone book
void print_phone_book(contact **contacts, int num_contacts) {
    // Sort the contacts by name
    qsort(contacts, num_contacts, sizeof(contact), compare_contacts);

    // Print the contacts
    for (int i = 0; i < num_contacts; i++) {
        print_contact(contacts[i]);
    }
}

// Main function
int main() {
    // Initialize the phone book
    contact *contacts[100];
    int num_contacts = 0;

    // Add some contacts to the phone book
    add_contact(contacts, &num_contacts);
    add_contact(contacts, &num_contacts);
    add_contact(contacts, &num_contacts);

    // Search for a contact
    search_contact(contacts, num_contacts);

    // Delete a contact
    delete_contact(contacts, &num_contacts);

    // Print the phone book
    print_phone_book(contacts, num_contacts);

    return 0;
}
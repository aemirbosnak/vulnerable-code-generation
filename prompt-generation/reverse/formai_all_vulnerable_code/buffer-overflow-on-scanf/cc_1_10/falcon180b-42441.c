//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts that can be stored in the phone book
#define MAX_CONTACTS 100

// Define the structure for each contact in the phone book
typedef struct {
    char name[50];
    char phone_number[15];
} Contact;

// Function to add a new contact to the phone book
void add_contact(Contact* phone_book, int num_contacts) {
    printf("Enter the name of the contact: ");
    scanf("%s", phone_book[num_contacts].name);

    printf("Enter the phone number of the contact: ");
    scanf("%s", phone_book[num_contacts].phone_number);

    printf("Contact added successfully!\n");
}

// Function to search for a contact in the phone book
int search_contact(Contact* phone_book, int num_contacts, char* name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Contact found!\n");
            printf("Name: %s\n", phone_book[i].name);
            printf("Phone number: %s\n", phone_book[i].phone_number);
            return 1;
        }
    }

    printf("Contact not found.\n");
    return 0;
}

// Function to display all the contacts in the phone book
void display_contacts(Contact* phone_book, int num_contacts) {
    printf("All contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", phone_book[i].name);
        printf("Phone number: %s\n\n", phone_book[i].phone_number);
    }
}

int main() {
    // Initialize the phone book with empty contacts
    Contact phone_book[MAX_CONTACTS];
    int num_contacts = 0;

    // Add a new contact
    add_contact(phone_book, num_contacts);

    // Add another new contact
    add_contact(phone_book, num_contacts);

    // Search for a contact
    char name[50];
    printf("Enter the name of the contact you want to search for: ");
    scanf("%s", name);
    int result = search_contact(phone_book, num_contacts, name);

    // Display all the contacts
    display_contacts(phone_book, num_contacts);

    return 0;
}
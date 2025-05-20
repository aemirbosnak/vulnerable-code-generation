//FormAI DATASET v1.0 Category: Database simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 30
#define MAX_CONTACTS 100

// Define a structure for a contact
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

// Define an array of contacts
Contact contacts[MAX_CONTACTS];
// Keep track of the current number of contacts
int num_contacts = 0;

// Function to add a new contact to the database
void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Sorry, the database is full. Cannot add new contact.\n");
        return;
    }
    Contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter email: ");
    scanf("%s", new_contact.email);
    contacts[num_contacts] = new_contact;
    num_contacts++;
    printf("Contact added successfully!\n");
}

// Function to search for a contact by name
void search_contact() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to print all contacts in the database
void print_contacts() {
    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s (%s)\n", i+1, contacts[i].name, contacts[i].email);
    }
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\nDatabase Menu:\n");
        printf("1. Add contact\n");
        printf("2. Search for contact\n");
        printf("3. Print all contacts\n");
        printf("4. Quit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                print_contacts();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
    return 0;
}
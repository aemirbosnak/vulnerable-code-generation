//FormAI DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold contact information
struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

// Function to add a new contact
void add_contact(struct Contact* contacts, int* num_contacts) {
    // Prompt user for contact information
    printf("Enter name: ");
    scanf("%s", contacts[*num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[*num_contacts].phone);
    printf("Enter email address: ");
    scanf("%s", contacts[*num_contacts].email);
    
    // Increment number of contacts
    (*num_contacts)++;
    
    // Print success message
    printf("Contact added successfully!\n");
}

// Function to search for a contact by name
void search_contact(struct Contact* contacts, int num_contacts) {
    char name[50];
    printf("Enter name: ");
    scanf("%s", name);
    
    // Search for contact with given name
    int i, found = 0;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found!\n");
    }
}

// Function to display all contacts
void display_contacts(struct Contact* contacts, int num_contacts) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("%s\t%s\t%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

int main() {
    // Allocate space for 100 contacts
    struct Contact* contacts = (struct Contact*) malloc(100 * sizeof(struct Contact));
    
    // Variable to hold number of contacts
    int num_contacts = 0;
    
    // Menu loop
    int choice = 1;
    while (choice != 0) {
        printf("\nPhone Book\n");
        printf("---------------------\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Display all contacts\n");
        printf("0. Quit\n");
        printf("\nEnter choice (0-3): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                search_contact(contacts, num_contacts);
                break;
            case 3:
                display_contacts(contacts, num_contacts);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    // Free allocated memory
    free(contacts);
    
    // Return success
    return 0;
}
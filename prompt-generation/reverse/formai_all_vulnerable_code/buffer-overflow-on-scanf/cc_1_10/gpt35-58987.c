//FormAI DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to store contact information
struct contact {
    char name[50];
    char phone[15];
    char email[50];
};

// Function to add a new contact
void addContact(struct contact cont[], int *num_contacts) {
    printf("Enter name: ");
    scanf("%s", cont[*num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", cont[*num_contacts].phone);
    printf("Enter email address: ");
    scanf("%s", cont[*num_contacts].email);
    (*num_contacts)++;
    printf("\nContact added successfully!\n\n");
}

// Function to search for a contact
void searchContact(struct contact cont[], int num_contacts) {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, cont[i].name) == 0) {
            printf("Name: %s\nPhone: %s\nEmail: %s\n\n", cont[i].name, cont[i].phone, cont[i].email);
            return;
        }
    }
    printf("No contact found with the name %s\n\n", name);
}

// Function to display all contacts
void displayAll(struct contact cont[], int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\nPhone: %s\nEmail: %s\n\n", cont[i].name, cont[i].phone, cont[i].email);
    }
}

int main() {
    // Declare variables
    struct contact contacts[100];
    int num_contacts = 0;
    char choice;

    // Welcome message
    printf("Welcome to Future Phone Book!\n");

    do {
        // Menu options
        printf("Enter your choice:\n");
        printf("a. Add a new contact\n");
        printf("b. Search for a contact\n");
        printf("c. Display all contacts\n");
        printf("x. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                addContact(contacts, &num_contacts);
                break;
            case 'b':
                searchContact(contacts, num_contacts);
                break;
            case 'c':
                displayAll(contacts, num_contacts);
                break;
            case 'x':
                printf("Thank you for using Future Phone Book!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n\n");
        }
    } while (choice != 'x');

    return 0;
}
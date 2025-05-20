//FormAI DATASET v1.0 Category: Phone Book ; Style: all-encompassing
/* A C Program to implement a Phone Book */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 100

// Structure for storing contact information
struct contact {
    char name[50];
    char phone[20];
};

// Function prototypes
void add_contact();
void search_contact();
void list_contacts();

// Global variables
struct contact contacts[MAX_CONTACTS];
int num_contacts = 0;

// Main function
int main() {
    int choice;

    // Display menu and get user's choice
    do {
        printf("\nPhone Book");
        printf("\n1. Add Contact");
        printf("\n2. Search Contact");
        printf("\n3. List Contacts");
        printf("\n4. Exit");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        // Perform action based on user's choice
        switch (choice) {
            case 1: add_contact(); break;
            case 2: search_contact(); break;
            case 3: list_contacts(); break;
            case 4: exit(0); break;
            default: printf("Invalid choice. Try again.");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a new contact
void add_contact() {
    // Check if phone book is full
    if (num_contacts == MAX_CONTACTS) {
        printf("Phone book is full!");
        return;
    }

    struct contact c;

    // Get contact information from user
    printf("\nEnter name: ");
    scanf("%s", c.name);
    printf("Enter phone number: ");
    scanf("%s", c.phone);

    // Add contact to phone book
    contacts[num_contacts++] = c;

    printf("\nContact added successfully.");
}

// Function to search for a contact
void search_contact() {
    char name[50];
    int i, found = 0;

    // Get name from user
    printf("\nEnter name to search for: ");
    scanf("%s", name);

    // Search phone book for matching names
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("\n%s's phone number is %s", contacts[i].name, contacts[i].phone);
            found = 1;
        }
    }

    // Display message if no matching names found
    if (!found) {
        printf("\nNo contacts found with that name.");
    }
}

// Function to list all contacts
void list_contacts() {
    int i;

    // Check if phone book is empty
    if (num_contacts == 0) {
        printf("\nPhone book is empty!");
        return;
    }

    printf("\nList of contacts:");

    // Display all contacts in phone book
    for (i = 0; i < num_contacts; i++) {
        printf("\n%s - %s", contacts[i].name, contacts[i].phone);
    }
}
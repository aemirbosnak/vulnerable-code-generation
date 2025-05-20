//FormAI DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 15
#define MAX_CONTACTS 100

// Structure for storing contact information
struct Contact {
    char name[MAX_NAME_LEN];
    char phone[MAX_NUM_LEN];
};

// Global array of contacts
struct Contact contacts[MAX_CONTACTS];
int numContacts = 0;

// Function to add a new contact
void addContact() {
    if (numContacts >= MAX_CONTACTS) {
        printf("Sorry, the phone book is full!\n");
        return;
    }
    
    struct Contact contact;
    
    printf("Enter contact name: ");
    fgets(contact.name, MAX_NAME_LEN, stdin);
    // remove newline character at the end
    contact.name[strcspn(contact.name, "\n")] = '\0';
    
    printf("Enter phone number (format xxx-xxx-xxxx): ");
    fgets(contact.phone, MAX_NUM_LEN, stdin);
    // remove newline character at the end
    contact.phone[strcspn(contact.phone, "\n")] = '\0';
    
    contacts[numContacts] = contact;
    numContacts++;
    
    printf("Contact added!\n");
}

// Function to display all contacts
void displayContacts() {
    if (numContacts == 0) {
        printf("The phone book is empty!\n");
        return;
    }
    
    for (int i = 0; i < numContacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].phone);
    }
}

// Main function
int main() {
    int choice;
    
    printf("Welcome to the Phone Book!\n");
    
    do {
        // Display menu
        printf("\nPlease choose an option:\n");
        printf("1. Add contact\n");
        printf("2. Display all contacts\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar(); // remove newline character
        
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}
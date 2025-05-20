//FormAI DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Define a struct for the contacts
typedef struct Contact {
    char name[50];
    char phone[15];
} Contact;

// Define the phone book array and the current number of contacts
Contact phoneBook[MAX_CONTACTS];
int numContacts = 0;

// Function to add a new contact to the phone book
void addContact(char name[], char phone[]) {
    // Make sure we haven't exceeded the max number of contacts
    if (numContacts >= MAX_CONTACTS) {
        printf("Sorry, the phone book is already full!\n");
        return;
    }
    
    // Create a new contact and add it to the phone book
    Contact newContact;
    strcpy(newContact.name, name);
    strcpy(newContact.phone, phone);
    phoneBook[numContacts] = newContact;
    numContacts++;
    
    printf("Contact added successfully!\n");
}

// Function to search for a contact by name
void searchContact(char name[]) {
    // Loop through all the contacts and see if we find a match
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Contact Found!\n");
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone: %s\n", phoneBook[i].phone);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Sorry, no contacts found with that name.\n");
    }
}

// Function to display all the contacts in the phone book
void displayContacts() {
    printf("Phone Book:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s\n", phoneBook[i].name);
        printf("Phone: %s\n\n", phoneBook[i].phone);
    }
}

int main() {
    // Welcome message
    printf("Welcome to the Phone Book!\n\n");
    
    // Main menu loop
    int choice = 0;
    while (choice != 4) {
        printf("Choose an option:\n");
        printf("1. Add a new contact\n");
        printf("2. Search for a contact by name\n");
        printf("3. Display all contacts\n");
        printf("4. Quit\n");
        
        scanf("%d", &choice);
        
        // Handle each menu option
        switch (choice) {
            case 1:
                // Add a new contact
                printf("Enter the contact's name: ");
                char name[50];
                scanf("%s", name);
                
                printf("Enter the contact's phone number: ");
                char phone[15];
                scanf("%s", phone);
                
                addContact(name, phone);
                break;
            case 2:
                // Search for a contact
                printf("Enter the name to search for: ");
                char searchName[50];
                scanf("%s", searchName);
                
                searchContact(searchName);
                break;
            case 3:
                // Display all contacts
                displayContacts();
                break;
            case 4:
                // Quit
                printf("Goodbye!\n");
                break;
            default:
                printf("Sorry, that is not a valid option.\n");
                break;
        }
    }
    
    return 0;
}
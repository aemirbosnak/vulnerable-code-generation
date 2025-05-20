//FormAI DATASET v1.0 Category: Phone Book ; Style: lively
// Hey there! Welcome to the C Phone Book example program.
// This program is designed to help you store and manage your contacts in a phone book.

#include <stdio.h>

// Define the maximum number of contacts that the phone book can hold
#define MAX_CONTACTS 100

// Define the structure of a contact
struct Contact {
    char name[50];
    char phone[20];
};

// Declare an array to hold the contacts
struct Contact phoneBook[MAX_CONTACTS];

// Declare a counter of the number of contacts in the phone book
int numContacts = 0;

// Define a function to add a new contact to the phone book
void addContact() {
    // Check if the phone book is already full
    if (numContacts >= MAX_CONTACTS) {
        printf("Sorry, the phone book is full.\n");
        return;
    }
    
    // Prompt the user to enter the name of the new contact
    printf("Name: ");
    scanf("%s", phoneBook[numContacts].name);
    
    // Prompt the user to enter the phone number of the new contact
    printf("Phone: ");
    scanf("%s", phoneBook[numContacts].phone);
    
    // Increment the counter of the number of contacts in the phone book
    numContacts++;
    
    printf("Contact added successfully!\n");
}

// Define a function to search for a contact in the phone book by name
void searchContactByName() {
    // Prompt the user to enter the name to search for
    char nameToSearch[50];
    printf("Enter name to search for: ");
    scanf("%s", nameToSearch);
    
    // Loop through all the contacts in the phone book
    for (int i = 0; i < numContacts; i++) {
        // Check if the name of the current contact matches the name to search for
        if (strcmp(phoneBook[i].name, nameToSearch) == 0) {
            // Print the details of the contact
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone: %s\n", phoneBook[i].phone);
            return;
        }
    }
    
    // If the function has not yet returned, the contact was not found
    printf("Contact with name \"%s\" not found.\n", nameToSearch);
}

// Define a function to search for a contact in the phone book by phone number
void searchContactByPhone() {
    // Prompt the user to enter the phone number to search for
    char phoneToSearch[20];
    printf("Enter phone number to search for: ");
    scanf("%s", phoneToSearch);
    
    // Loop through all the contacts in the phone book
    for (int i = 0; i < numContacts; i++) {
        // Check if the phone number of the current contact matches the phone number to search for
        if (strcmp(phoneBook[i].phone, phoneToSearch) == 0) {
            // Print the details of the contact
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone: %s\n", phoneBook[i].phone);
            return;
        }
    }
    
    // If the function has not yet returned, the contact was not found
    printf("Contact with phone number \"%s\" not found.\n", phoneToSearch);
}

// Define the main function
int main() {
    // Print a welcome message
    printf("Welcome to the C Phone Book example program!\n");
    
    // Loop indefinitely until the user chooses to exit
    while (1) {
        // Print the menu of options
        printf("\nMENU:\n");
        printf("1. Add a new contact\n");
        printf("2. Search for a contact by name\n");
        printf("3. Search for a contact by phone number\n");
        printf("4. Exit\n");
        
        // Prompt the user to choose an option
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        // Check the user's choice and call the appropriate function
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContactByName();
                break;
            case 3:
                searchContactByPhone();
                break;
            case 4:
                printf("Thank you for using the C Phone Book example program!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
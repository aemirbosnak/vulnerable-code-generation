//FormAI DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of contacts in the phone book
#define MAX_CONTACTS 100

// Struct to store a contact's information
typedef struct {
    char name[50];
    char number[20];
} Contact;

// Function to add a new contact to the phone book
void addContact(Contact phonebook[], int *numContacts) {
    // Check if maximum number of contacts have been reached
    if (*numContacts == MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }
    
    // Get the name and number from the user
    printf("Enter name: ");
    scanf("%s", phonebook[*numContacts].name);
    printf("Enter number: ");
    scanf("%s", phonebook[*numContacts].number);
    
    // Increment the number of contacts in the phone book
    (*numContacts)++;
    
    printf("Contact added successfully!\n");
}

// Function to search for a contact in the phone book
void searchContact(Contact phonebook[], int numContacts) {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    
    // Loop through the phone book to find the contact
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("%s's number is %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }
    
    printf("Contact not found!\n");
}

// Function to display all the contacts in the phone book
void displayContacts(Contact phonebook[], int numContacts) {
    printf("\nAll contacts in the phone book:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%s\t%s\n", phonebook[i].name, phonebook[i].number);
    }
}

// Main function
int main() {
    // Initialize the phone book with 0 contacts
    Contact phonebook[MAX_CONTACTS];
    int numContacts = 0;
    
    // Display the menu and get user input
    int choice;
    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact(phonebook, &numContacts);
                break;
            case 2:
                searchContact(phonebook, numContacts);
                break;
            case 3:
                displayContacts(phonebook, numContacts);
                break;
            case 4:
                printf("Exiting Phone Book...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (1);
    
    return 0;
}
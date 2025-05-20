//FormAI DATASET v1.0 Category: Phone Book ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for contact in phone book
struct contact {
    char name[50];
    char number[12];
    int id;
};

// Function declarations
void displayMenu();
int getNextId();
void addContact(struct contact[], int*);
void searchContact(struct contact[], int);
void editContact(struct contact[], int);
void deleteContact(struct contact[], int*);

int main() {

    // Initialize phone book with capacity of 100 contacts
    struct contact phoneBook[100];
    int numOfContacts = 0;

    // Display menu and handle user choices until they exit
    int choice = 0;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(phoneBook, &numOfContacts);
                break;
            case 2:
                searchContact(phoneBook, numOfContacts);
                break;
            case 3:
                editContact(phoneBook, numOfContacts);
                break;
            case 4:
                deleteContact(phoneBook, &numOfContacts);
                break;
            case 5:
                printf("Thank you for using the phone book.\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function to display the menu of choices
void displayMenu() {
    printf("Phone Book\n");
    printf("-----------\n");
    printf("1. Add contact\n");
    printf("2. Search for contact\n");
    printf("3. Edit existing contact\n");
    printf("4. Delete contact\n");
    printf("5. Quit\n");
    printf("\nEnter your choice: ");
}

// Function to generate the next available ID for new contacts
int getNextId() {
    static int id = 0;
    return ++id;
}

// Function to add a new contact to the phone book
void addContact(struct contact phoneBook[], int *numOfContacts) {
    // Check if phone book is already full
    if (*numOfContacts == 100) {
        printf("Phone book is full. Cannot add new contact.\n\n");
        return;
    }

    // Create a new contact
    struct contact newContact;
    printf("Enter contact name: ");
    scanf("%s", newContact.name);
    printf("Enter contact number: ");
    scanf("%s", newContact.number);
    newContact.id = getNextId();

    // Add new contact to phone book
    phoneBook[*numOfContacts] = newContact;
    (*numOfContacts)++;

    printf("Contact added successfully.\n\n");
}

// Function to search for a contact by name or number
void searchContact(struct contact phoneBook[], int numOfContacts) {
    // Get search query from user
    char query[50];
    printf("Enter name or number to search: ");
    scanf("%s", query);

    // Search for contact
    printf("Search Results:\n");
    int resultsFound = 0;
    for (int i = 0; i < numOfContacts; i++) {
        if (strstr(phoneBook[i].name, query) != NULL || strstr(phoneBook[i].number, query) != NULL) {
            printf("%d. Name: %s - Number: %s\n", resultsFound+1, phoneBook[i].name, phoneBook[i].number);
            resultsFound++;
        }
    }

    // Display message if no results were found
    if (resultsFound == 0) {
        printf("No results found.\n");
    }

    printf("\n");
}

// Function to edit an existing contact
void editContact(struct contact phoneBook[], int numOfContacts) {
    // Get contact ID from user
    int contactId;
    printf("Enter ID of contact to edit: ");
    scanf("%d", &contactId);

    // Find contact with matching ID
    struct contact *contactToEdit = NULL;
    for (int i = 0; i < numOfContacts; i++) {
        if (phoneBook[i].id == contactId) {
            contactToEdit = &phoneBook[i];
            break;
        }
    }

    // Display error message if contact was not found
    if (contactToEdit == NULL) {
        printf("Contact with ID %d not found.\n\n", contactId);
        return;
    }

    // Edit contact
    printf("Enter new name (or leave blank to keep current): ");
    char newName[50];
    fflush(stdin);
    fgets(newName, 50, stdin);
    newName[strcspn(newName, "\r\n")] = 0; // Remove newline character at end of string

    if (strcmp(newName, "") != 0) {
        strcpy(contactToEdit->name, newName);
    }

    printf("Enter new number (or leave blank to keep current): ");
    char newNumber[12];
    fflush(stdin);
    fgets(newNumber, 12, stdin);
    newNumber[strcspn(newNumber, "\r\n")] = 0; // Remove newline character at end of string

    if (strcmp(newNumber, "") != 0) {
        strcpy(contactToEdit->number, newNumber);
    }

    printf("Contact edited successfully.\n\n");
}

// Function to delete an existing contact
void deleteContact(struct contact phoneBook[], int *numOfContacts) {
    // Get contact ID from user
    int contactId;
    printf("Enter ID of contact to delete: ");
    scanf("%d", &contactId);

    // Find index of contact with matching ID
    int indexToDelete = -1;
    for (int i = 0; i < *numOfContacts; i++) {
        if (phoneBook[i].id == contactId) {
            indexToDelete = i;
            break;
        }
    }

    // Display error message if contact was not found
    if (indexToDelete == -1) {
        printf("Contact with ID %d not found.\n\n", contactId);
        return;
    }

    // Shift all contacts after the one to be deleted back one index
    for (int i = indexToDelete; i < (*numOfContacts)-1; i++) {
        phoneBook[i] = phoneBook[i+1];
    }

    // Decrement number of contacts in phone book
    (*numOfContacts)--;

    printf("Contact deleted successfully.\n\n");
}
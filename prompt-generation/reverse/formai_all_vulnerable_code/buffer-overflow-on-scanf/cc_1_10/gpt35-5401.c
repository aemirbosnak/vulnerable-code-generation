//FormAI DATASET v1.0 Category: Mailing list manager ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 20
#define MAX_ENTRIES 10

// Struct for storing contact information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

int numContacts = 0;
Contact contactList[MAX_ENTRIES];

// Function prototypes
void addContact();
void deleteContact();
void listContacts();
void saveContacts();

int main() {
    char choice = ' ';
    while (choice != 'q') {
        // Print menu options
        printf("\nMailing List Manager\n");
        printf("--------------------\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. List Contacts\n");
        printf("4. Save Contacts\n");
        printf("q. Quit\n");
        
        // Get user input
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);
        
        // Process user choice
        switch (choice) {
            case '1': addContact(); break;
            case '2': deleteContact(); break;
            case '3': listContacts(); break;
            case '4': saveContacts(); break;
            case 'q': printf("\nGoodbye!\n"); break;
            default: printf("\nInvalid choice. Try again.\n"); break;
        }
    }
    return 0;
}

// Function to add a new contact to the list
void addContact() {
    // Check if there's room for more contacts
    if (numContacts == MAX_ENTRIES) {
        printf("\nThe contact list is full!\n");
        return;
    }
    
    // Get contact information from user
    Contact newContact;
    printf("\nEnter the contact's name: ");
    scanf("%s", newContact.name);
    printf("Enter the contact's email address: ");
    scanf("%s", newContact.email);
    printf("Enter the contact's phone number: ");
    scanf("%s", newContact.phone);
    
    // Add contact to list
    contactList[numContacts++] = newContact;
    printf("\nContact added successfully!\n");
}

// Function to delete a contact from the list
void deleteContact() {
    // Check if there are any contacts to delete
    if (numContacts == 0) {
        printf("\nThe contact list is empty!\n");
        return;
    }
    
    // Get contact to delete from user
    char name[MAX_NAME_LENGTH];
    printf("\nEnter the name of the contact to delete: ");
    scanf("%s", name);
    
    // Search for contact in list and remove it if found
    int index = -1; // -1 means contact not found
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contactList[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("\nContact not found!\n");
        return;
    }
    
    for (int i = index; i < numContacts - 1; i++) {
        contactList[i] = contactList[i+1];
    }
    numContacts--;
    printf("\nContact deleted successfully!\n");
}

// Function to list all contacts in the list
void listContacts() {
    // Check if there are any contacts to list
    if (numContacts == 0) {
        printf("\nThe contact list is empty!\n");
        return;
    }
    
    // Print header for contact list
    printf("\n%-20s| %-30s| %-15s\n", "Name", "Email Address", "Phone Number");
    printf("---------------------------------------------------------\n");
    
    // Print each contact's information
    for (int i = 0; i < numContacts; i++) {
        printf("%-20s| %-30s| %-15s\n", contactList[i].name, contactList[i].email, contactList[i].phone);
    }
}

// Function to save the contact list to a file
void saveContacts() {
    char filename[MAX_NAME_LENGTH];
    printf("\nEnter the name of the file to save the contacts to: ");
    scanf("%s", filename);
    
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("\nError opening file!\n");
        return;
    }
    
    for (int i = 0; i < numContacts; i++) {
        fprintf(file, "%s,%s,%s\n", contactList[i].name, contactList[i].email, contactList[i].phone);
    }
    
    fclose(file);
    printf("\nContacts saved successfully!\n");
}
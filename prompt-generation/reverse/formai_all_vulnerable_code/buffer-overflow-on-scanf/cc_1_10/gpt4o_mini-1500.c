//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display the menu to the user
void displayMenu() {
    printf("Welcome to the Simple Contact Management System\n");
    printf("==============================================\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

// Structure to hold contact details
typedef struct {
    char name[50];
    char phone[15];
} Contact;

// Function to add a new contact
void addContact(Contact *contacts, int *size) {
    if (*size >= 100) {
        printf("Contact list is full.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", contacts[*size].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[*size].phone);
    (*size)++;
    printf("Contact added successfully!\n");
}

// Function to display all contacts
void displayContacts(Contact *contacts, int size) {
    if (size == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("Contacts:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

// Function to search for a contact
void searchContact(Contact *contacts, int size) {
    char name[50];
    printf("Enter the name of the contact to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found: Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact
void deleteContact(Contact *contacts, int *size) {
    char name[50];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            found = 1;
            // Shift contacts to delete the selected contact
            for (int j = i; j < *size - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*size)--;
            printf("Contact deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Main function to run the contact management system
int main() {
    Contact contacts[100];
    int size = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact(contacts, &size);
                break;
            case 2:
                displayContacts(contacts, size);
                break;
            case 3:
                searchContact(contacts, size);
                break;
            case 4:
                deleteContact(contacts, &size);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
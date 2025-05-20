//FormAI DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Define a structure for a contact in the phone book
typedef struct contact {
    char name[30];
    char phone[15];
} Contact;

// Define an array to hold the contacts
Contact phoneBook[MAX_CONTACTS];

// Define the number of contacts currently in the phone book
int numContacts = 0;

// Function to add a contact to the phone book
void addContact() {
    printf("\nADDING A NEW CONTACT\n");
    printf("Enter the name: ");
    scanf("%s", phoneBook[numContacts].name);
    printf("Enter the phone number: ");
    scanf("%s", phoneBook[numContacts].phone);
    numContacts++;
    printf("Contact added successfully!\n");
}

// Function to display all the contacts in the phone book
void displayContacts() {
    printf("\nDISPLAYING ALL CONTACTS\n");
    if (numContacts == 0) {
        printf("No contacts found\n");
        return;
    }
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s\nPhone: %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

// Function to search for a contact by name
void searchContact() {
    printf("\nSEARCHING FOR A CONTACT\n");
    if (numContacts == 0) {
        printf("No contacts found\n");
        return;
    }
    char name[30];
    printf("Enter the name of the contact to search: ");
    scanf("%s", name);
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(name, phoneBook[i].name) == 0) {
            printf("Name: %s\nPhone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found\n");
}

// Function to delete a contact by name
void deleteContact() {
    printf("\nDELETING A CONTACT\n");
    if (numContacts == 0) {
        printf("No contacts found\n");
        return;
    }
    char name[30];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(name, phoneBook[i].name) == 0) {
            // Remove the contact by shifting all the subsequent contacts up by one index
            for (int j = i; j < numContacts - 1; j++) {
                phoneBook[j] = phoneBook[j+1];
            }
            numContacts--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found\n");
}

// Main function to display the menu and handle user input
int main() {
    int choice;
    printf("Welcome to Phone Book\n");
    do {
        printf("\nMENU\n");
        printf("1. Add a contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: printf("\nGoodbye!"); break;
            default: printf("\nInvalid choice\n");
        }
    } while (choice != 5);
    return 0;
}
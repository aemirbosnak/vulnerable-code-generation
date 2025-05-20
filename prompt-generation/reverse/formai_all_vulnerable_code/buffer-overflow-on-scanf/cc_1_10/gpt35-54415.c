//FormAI DATASET v1.0 Category: Phone Book ; Style: cheerful
// Welcome to the Happy Phone Book program!
// Here we can store all of our friends' contact information and keep track of them.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Struct to hold contact information
typedef struct contact {
    char name[50];
    char phone[15];
    char email[50];
} contact;

// Function to display main menu
void displayMenu() {
    printf("\nWelcome to the Happy Phone Book!\n");
    printf("1. Add a contact\n");
    printf("2. Edit a contact\n");
    printf("3. Delete a contact\n");
    printf("4. Search for a contact\n");
    printf("5. View all contacts\n");
    printf("6. Exit program\n");
}

// Function to add a contact
void addContact(contact* contacts, int* numContacts) {
    printf("\nEnter the contact's name: ");
    scanf("%s", contacts[*numContacts].name);
    printf("Enter the contact's phone number: ");
    scanf("%s", contacts[*numContacts].phone);
    printf("Enter the contact's email: ");
    scanf("%s", contacts[*numContacts].email);
    *numContacts += 1;
    printf("\nContact added successfully!\n");
}

// Function to edit a contact
void editContact(contact* contacts, int numContacts) {
    char name[50];
    int found = 0;  // Flag to indicate if contact was found
    printf("\nEnter the name of the contact you want to edit: ");
    scanf("%s", name);
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("\nEnter new phone number for %s: ", name);
            scanf("%s", contacts[i].phone);
            printf("Enter new email address for %s: ", name);
            scanf("%s", contacts[i].email);
            printf("\nContact updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nContact not found!\n");
    }
}

// Function to delete a contact
void deleteContact(contact* contacts, int* numContacts) {
    char name[50];
    int found = 0;  // Flag to indicate if contact was found
    printf("\nEnter the name of the contact you want to delete: ");
    scanf("%s", name);
    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            // Shift all contacts after the one to be deleted down by 1
            for (int j = i; j < *numContacts - 1; j++) {
                strcpy(contacts[j].name, contacts[j+1].name);
                strcpy(contacts[j].phone, contacts[j+1].phone);
                strcpy(contacts[j].email, contacts[j+1].email);
            }
            *numContacts -= 1;
            printf("\nContact deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nContact not found!\n");
    }
}

// Function to search for a contact
void searchContact(contact* contacts, int numContacts) {
    char name[50];
    int found = 0;  // Flag to indicate if contact was found
    printf("\nEnter the name of the contact you want to search for: ");
    scanf("%s", name);
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("\nName: %s\n", contacts[i].name);
            printf("Phone number: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nContact not found!\n");
    }
}

// Function to display all contacts
void viewContacts(contact* contacts, int numContacts) {
    printf("\nContact list:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%d. Name: %s\n", i+1, contacts[i].name);
        printf("   Phone number: %s\n", contacts[i].phone);
        printf("   Email: %s\n", contacts[i].email);
    }
}

int main() {
    contact contacts[MAX_CONTACTS];
    int numContacts = 0;  // Number of contacts currently stored
    int choice;
    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                editContact(contacts, numContacts);
                break;
            case 3:
                deleteContact(contacts, &numContacts);
                break;
            case 4:
                searchContact(contacts, numContacts);
                break;
            case 5:
                viewContacts(contacts, numContacts);
                break;
            case 6:
                printf("\nThank you for using the Happy Phone Book!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (1);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_CONTACTS 100

// Structure to hold contact information
typedef struct {
    char name[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
} Contact;

// Function declarations
void addContact(Contact contacts[], int *count);
void viewContacts(Contact contacts[], int count);
void searchContact(Contact contacts[], int count);
void deleteContact(Contact contacts[], int *count);
void displayMenu();

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                viewContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                deleteContact(contacts, &count);
                break;
            case 5:
                printf("Exiting the contact manager.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("\nContact Manager Menu:\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a contact
void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Contact list is full! Cannot add more contacts.\n");
        return;
    }
    printf("Enter name: ");
    fgets(contacts[*count].name, MAX_LENGTH, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = 0; // Remove newline

    printf("Enter phone number: ");
    fgets(contacts[*count].phone, MAX_LENGTH, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = 0; // Remove newline

    printf("Enter email: ");
    fgets(contacts[*count].email, MAX_LENGTH, stdin);
    contacts[*count].email[strcspn(contacts[*count].email, "\n")] = 0; // Remove newline

    (*count)++;
    printf("Contact added successfully!\n");
}

// Function to view all contacts
void viewContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("\nList of Contacts:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Phone: %s, Email: %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

// Function to search for a contact by name
void searchContact(Contact contacts[], int count) {
    char name[MAX_LENGTH];
    printf("Enter the name of the contact to search: ");
    fgets(name, MAX_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(contacts[i].name, name) == 0) {
            printf("Contact found!\n");
            printf("Name: %s, Phone: %s, Email: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact by name
void deleteContact(Contact contacts[], int *count) {
    char name[MAX_LENGTH];
    printf("Enter the name of the contact to delete: ");
    fgets(name, MAX_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    int found = -1;
    for (int i = 0; i < *count; i++) {
        if (strcasecmp(contacts[i].name, name) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        for (int i = found; i < *count - 1; i++) {
            contacts[i] = contacts[i + 1]; // Shift contacts left
        }
        (*count)--; // Decrease count
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found.\n");
    }
}
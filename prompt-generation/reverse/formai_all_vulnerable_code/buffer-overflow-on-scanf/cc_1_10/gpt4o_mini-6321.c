//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

// Structure to hold contact information
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

// Function prototypes
void addContact(Contact contacts[], int *count);
void searchContact(Contact contacts[], int count);
void displayContacts(Contact contacts[], int count);
void clearBuffer();

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    do {
        printf("\nPhone Book Menu\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        // Read user input for menu choice
        scanf("%d", &choice);
        clearBuffer(); // clear the input buffer

        switch (choice) {
            case 1:
                if (count < MAX_CONTACTS) {
                    addContact(contacts, &count);
                } else {
                    printf("Phone book is full! Cannot add more contacts.\n");
                }
                break;
            case 2:
                searchContact(contacts, count);
                break;
            case 3:
                displayContacts(contacts, count);
                break;
            case 4:
                printf("Exiting the Phone Book application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a contact
void addContact(Contact contacts[], int *count) {
    printf("Enter Name: ");
    fgets(contacts[*count].name, NAME_LENGTH, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = '\0'; // Remove newline character

    printf("Enter Phone Number: ");
    fgets(contacts[*count].phone, PHONE_LENGTH, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = '\0'; // Remove newline character

    (*count)++;
    printf("Contact added successfully!\n");
}

// Function to search for a contact
void searchContact(Contact contacts[], int count) {
    char name[NAME_LENGTH];
    printf("Enter Name to Search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found Contact: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

// Function to display all contacts
void displayContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\nList of Contacts:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

// Function to clear input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void clearInputBuffer() {
    while (getchar() != '\n');
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Database full! Unable to add more contacts.\n");
        return;
    }
    
    Contact newContact;
    
    printf("Enter name: ");
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline character
    
    printf("Enter phone number: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // Remove newline character
    
    if (strlen(newContact.name) == 0 || strlen(newContact.phone) == 0) {
        printf("Error: Name and phone number cannot be empty!\n");
        return;
    }
    
    contacts[*count] = newContact;
    (*count)++;
    printf("Contact added successfully!\n");
}

void searchContact(Contact contacts[], int count) {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline character
    
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Found Contact: %s - %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found. Double-check the name entered.\n");
}

void displayContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts to display. Ensure you've added contacts first.\n");
        return;
    }
    
    printf("\n--- Phone Book ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int contactCount = 0;
    int choice;

    while (1) {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Exit\n");
        printf("Please make a choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer(); // Clear invalid input
            continue; // Start over
        }
        clearInputBuffer(); // Clear input buffer for next use

        switch (choice) {
            case 1:
                addContact(contacts, &contactCount);
                break;
            case 2:
                searchContact(contacts, contactCount);
                break;
            case 3:
                displayContacts(contacts, contactCount);
                break;
            case 4:
                printf("Exiting the phone book. Remember to keep your contacts safe!\n");
                exit(0); // Exit safely
                break;
            default:
                printf("Invalid choice! Please select a valid option from the menu.\n");
        }
    }

    return 0;
}
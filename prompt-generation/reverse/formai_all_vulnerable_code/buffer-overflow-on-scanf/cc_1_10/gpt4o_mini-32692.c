//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: recursive
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

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

// Function to add a contact
void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", phoneBook[contactCount].name);
    printf("Enter phone number: ");
    scanf("%s", phoneBook[contactCount].phone);
    contactCount++;
    printf("Contact added successfully.\n");
}

// Recursive function to display contacts
void displayContactsHelper(int index) {
    if (index >= contactCount) {
        return;
    }
    printf("Name: %s, Phone: %s\n", phoneBook[index].name, phoneBook[index].phone);
    displayContactsHelper(index + 1);
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts to display.\n");
    } else {
        printf("Contacts in Phone Book:\n");
        displayContactsHelper(0);
    }
}

// Search contact by name using recursion
void searchContactHelper(char *name, int index) {
    if (index >= contactCount) {
        printf("Contact not found.\n");
        return;
    }

    if (strcmp(phoneBook[index].name, name) == 0) {
        printf("Found Contact - Name: %s, Phone: %s\n", phoneBook[index].name, phoneBook[index].phone);
    } else {
        searchContactHelper(name, index + 1);
    }
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);
    searchContactHelper(name, 0);
}

// Main menu function
void showMenu() {
    int choice;

    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                printf("Exiting phone book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    showMenu();
    return 0;
}
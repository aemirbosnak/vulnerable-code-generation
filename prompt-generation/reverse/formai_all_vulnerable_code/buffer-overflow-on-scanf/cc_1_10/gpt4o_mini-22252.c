//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

/* Structure to hold contact information */
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

/* Phone Book - an array of Contacts */
Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

/* Function Declarations */
void addContact();
void displayContacts();
void searchContact();
void deleteContact();
void showMenu();
int findContactIndex(const char *name);

/* Main function */
int main() {
    int choice;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: exit(0);
            default: printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}

/* Function to display the menu */
void showMenu() {
    printf("\n=== Phone Book Menu ===\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

/* Function to add a new contact */
void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }

    Contact newContact;
    printf("Enter name: ");
    getchar(); // To consume newline from previous input
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline character

    printf("Enter phone number: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // Remove newline character

    phoneBook[contactCount++] = newContact;
    printf("Contact added successfully!\n");
}

/* Function to display all contacts */
void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts available!\n");
        return;
    }

    printf("\n=== List of Contacts ===\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

/* Function to search for a contact by name */
void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    getchar(); // To consume newline
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    int index = findContactIndex(name);
    if (index != -1) {
        printf("Found Contact - Name: %s, Phone: %s\n", phoneBook[index].name, phoneBook[index].phone);
    } else {
        printf("Contact not found!\n");
    }
}

/* Function to delete a contact by name */
void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter name to delete: ");
    getchar(); // To consume newline
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    int index = findContactIndex(name);
    if (index != -1) {
        for (int i = index; i < contactCount - 1; i++) {
            phoneBook[i] = phoneBook[i + 1];
        }
        contactCount--;
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}

/* Helper function to find a contact index by name */
int findContactIndex(const char *name) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Not found
}
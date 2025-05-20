//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
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

void addContact();
void viewContacts();
void searchContact();
void deleteContact();
void displayMenu();

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        printf("Select an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // consumed newline
        
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting Phone Book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }

    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline character

    printf("Enter phone number: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // Remove newline character

    phoneBook[contactCount++] = newContact;
    printf("Contact added successfully!\n");
}

void viewContacts() {
    if (contactCount == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\n--- Contacts ---\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Contact %d: %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Found: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            contactCount--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found. Cannot delete.\n");
}
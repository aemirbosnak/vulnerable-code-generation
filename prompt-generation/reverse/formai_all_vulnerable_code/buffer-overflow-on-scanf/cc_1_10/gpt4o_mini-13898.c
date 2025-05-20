//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: ephemeral
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

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }

    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline

    printf("Enter phone number: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // Remove newline

    phoneBook[contactCount++] = newContact; 
    printf("Contact added successfully!\n");
}

void listContacts() {
    if (contactCount == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("\nContacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    printf("\nSearch Results:\n");
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, searchName) == 0) {
            printf("Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("No contact found with name %s.\n", searchName);
    }
}

void deleteContact() {
    char deleteName[NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(deleteName, NAME_LENGTH, stdin);
    deleteName[strcspn(deleteName, "\n")] = 0; // Remove newline

    int deleted = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, deleteName) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1]; // Shift left
            }
            contactCount--;
            deleted = 1;
            printf("Contact %s deleted successfully.\n", deleteName);
            break;
        }
    }

    if (!deleted) {
        printf("No contact found with name %s to delete.\n", deleteName);
    }
}

void menu() {
    int choice;
    do {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character from input buffer

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                listContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting Phone Book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    printf("Welcome to the Phone Book Program!\n");
    menu();
    return 0;
}
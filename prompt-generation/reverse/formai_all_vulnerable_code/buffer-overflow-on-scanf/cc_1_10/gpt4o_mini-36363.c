//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    
    Contact newContact;
    printf("Enter name: ");
    getchar(); // consume newline
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0;  // Remove newline character

    printf("Enter phone number: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0;  // Remove newline character
    
    printf("Enter email: ");
    fgets(newContact.email, EMAIL_LENGTH, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = 0;  // Remove newline character

    phoneBook[contactCount] = newContact;
    contactCount++;
    printf("Contact added successfully!\n");
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter the name to search: ");
    getchar(); // consume newline
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;  // Remove newline character

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone: %s\n", phoneBook[i].phone);
            printf("Email: %s\n", phoneBook[i].email);
            return;
        }
    }
    printf("Contact not found.\n");
}

void listContacts() {
    if (contactCount == 0) {
        printf("No contacts in phone book.\n");
        return;
    }

    printf("Contacts list:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s, Phone: %s, Email: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone, phoneBook[i].email);
    }
}

void clearScreen() {
    printf("\033[H\033[J");  // ANSI escape codes to clear the terminal screen
}

int main() {
    int choice;

    while (1) {
        clearScreen();
        printf("Phone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. List Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                listContacts();
                break;
            case 4:
                printf("Exiting. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("Press Enter to continue...");
        getchar(); // consume newline and wait for user input to continue
    }
    return 0;
}
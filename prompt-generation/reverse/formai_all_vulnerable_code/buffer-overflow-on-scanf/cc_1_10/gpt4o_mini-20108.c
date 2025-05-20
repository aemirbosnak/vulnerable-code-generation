//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: inquisitive
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

void addContact(Contact contacts[], int *count);
void viewContacts(Contact contacts[], int count);
void searchContact(Contact contacts[], int count);
void displayMenu();

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    do {
        displayMenu();
        printf("Please select an option: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character after the integer input

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
                printf("Exiting the Phone Book. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n=== Phone Book Menu ===\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Exit\n");
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Contact book is full! Cannot add more contacts.\n");
        return;
    }

    printf("Enter name: ");
    fgets(contacts[*count].name, NAME_LENGTH, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = 0; // Remove newline

    printf("Enter phone number: ");
    fgets(contacts[*count].phone, PHONE_LENGTH, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = 0; // Remove newline

    (*count)++;
    printf("Contact added successfully!\n");
}

void viewContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts available!\n");
        return;
    }

    printf("\n=== Contacts List ===\n");
    for (int i = 0; i < count; i++) {
        printf("Contact %d: %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void searchContact(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts available!\n");
        return;
    }

    char name[NAME_LENGTH];
    printf("Enter a name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    int found = 0;
    printf("\n=== Search Results ===\n");
    for (int i = 0; i < count; i++) {
        if (strcasecmp(contacts[i].name, name) == 0) {
            printf("Found: %s - %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("No contact found with the name %s.\n", name);
    }
}
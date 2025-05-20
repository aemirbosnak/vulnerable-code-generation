//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: retro
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

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %[^\n]", contacts[*count].name);
    printf("Enter phone number: ");
    scanf(" %[^\n]", contacts[*count].phone);
    (*count)++;
    printf("Contact added successfully!\n");
}

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

void searchContact(Contact contacts[], int count) {
    char searchTerm[NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf(" %[^\n]", searchTerm);

    printf("\nSearch Results:\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(contacts[i].name, searchTerm) != NULL) {
            printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("No contacts found.\n");
    }
}

void displayMenu() {
    printf("\n=== Retro Phone Book ===\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Exit\n");
    printf("========================\n");
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    do {
        displayMenu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                displayContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                printf("Exiting the phone book. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
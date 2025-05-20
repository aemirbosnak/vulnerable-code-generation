//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
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

void addContact(Contact contacts[], int *contactCount) {
    if (*contactCount >= MAX_CONTACTS) {
        printf("Error: Phone book is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", contacts[*contactCount].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[*contactCount].phone);
    (*contactCount)++;
    printf("Contact added successfully!\n");
}

void viewContacts(Contact contacts[], int contactCount) {
    if (contactCount == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s, Phone: %s\n", i+1, contacts[i].name, contacts[i].phone);
    }
}

void searchContact(Contact contacts[], int contactCount) {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found contact: Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void deleteContact(Contact contacts[], int *contactCount) {
    char name[NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < *contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*contactCount)--;
            printf("Contact deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void displayMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int contactCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact(contacts, &contactCount);
                break;
            case 2:
                viewContacts(contacts, contactCount);
                break;
            case 3:
                searchContact(contacts, contactCount);
                break;
            case 4:
                deleteContact(contacts, &contactCount);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
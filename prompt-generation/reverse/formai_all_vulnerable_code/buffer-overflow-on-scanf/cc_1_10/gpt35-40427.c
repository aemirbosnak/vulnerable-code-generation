//FormAI DATASET v1.0 Category: Phone Book ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 1000
#define MAX_NAME_LENGTH 30
#define MAX_PHONE_LENGTH 15

typedef struct contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts == MAX_CONTACTS) {
        printf("Phone book is full. Cannot add new contact.\n");
        return;
    }
    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, MAX_NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; // remove newline character
    printf("Enter phone number: ");
    fgets(newContact.phone, MAX_PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0'; // remove newline character
    phoneBook[numContacts] = newContact;
    numContacts++;
    printf("Contact added successfully.\n");
}

void searchContact() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // remove newline character
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(searchName, phoneBook[i].name) == 0) {
            printf("Phone number for %s: %s\n", searchName, phoneBook[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add contact\n2. Search contact\n3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar(); // remove newline character from input buffer
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 3);
    return 0;
}
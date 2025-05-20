//FormAI DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50    // Maximum length of name or phone number
#define MAX_CONTACTS 100   // Maximum number of contacts that can be stored

typedef struct Contact {
    char name[MAX_LEN];
    char phone[MAX_LEN];
} contact_t;

contact_t phoneBook[MAX_CONTACTS];   // Array to store contacts
int numContacts = 0;   // Number of contacts currently stored in phone book

void addContact() {
    if (numContacts == MAX_CONTACTS) {
        printf("Phone book is full, cannot add another contact\n");
        return;
    }

    contact_t newContact;

    printf("Enter name: ");
    fgets(newContact.name, MAX_LEN, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0';   // Remove trailing newline character

    printf("Enter phone number: ");
    fgets(newContact.phone, MAX_LEN, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';   // Remove trailing newline character

    phoneBook[numContacts] = newContact;
    numContacts++;

    printf("Contact added successfully!\n");
}

void searchContact() {
    if (numContacts == 0) {
        printf("Phone book is empty, cannot search for a contact\n");
        return;
    }

    char search[MAX_LEN];
    printf("Enter name or phone number to search: ");
    fgets(search, MAX_LEN, stdin);
    search[strcspn(search, "\n")] = '\0';   // Remove trailing newline character

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].name, search) == 0 || strcmp(phoneBook[i].phone, search) == 0) {
            found = 1;
            printf("Contact found:\n");
            printf("Name: %s\nPhone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            break;
        }
    }

    if (!found) {
        printf("Contact not found\n");
    }
}

void listContacts() {
    if (numContacts == 0) {
        printf("Phone book is empty, no contacts to list\n");
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%s, %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

int main() {
    int option;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. List Contacts\n");
        printf("4. Quit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        getchar();   // Consume the newline character left in the input buffer

        switch (option) {
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
                printf("Quitting Phone Book...\n");
                exit(0);
            default:
                printf("Invalid option, please try again\n");
        }
    }

    return 0;
}
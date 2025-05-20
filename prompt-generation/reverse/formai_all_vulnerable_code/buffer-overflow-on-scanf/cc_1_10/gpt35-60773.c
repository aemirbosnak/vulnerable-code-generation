//FormAI DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20
#define MAX_ADDRESS_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char address[MAX_ADDRESS_LEN];
} Contact;

void addContact(Contact* contacts, int* numContacts);
void removeContact(Contact* contacts, int* numContacts);
void searchContacts(Contact* contacts, int numContacts);
void printContacts(Contact* contacts, int numContacts);

int main() {
    Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    // main menu loop
    do {
        printf("\nPhone Book\n");
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Search Contacts\n");
        printf("4. Print Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                removeContact(contacts, &numContacts);
                break;
            case 3:
                searchContacts(contacts, numContacts);
                break;
            case 4:
                printContacts(contacts, numContacts);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void addContact(Contact* contacts, int* numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add contact.\n");
    } else {
        Contact newContact;
        printf("Enter name: ");
        scanf("%s", newContact.name);
        printf("Enter phone number: ");
        scanf("%s", newContact.phone);
        printf("Enter address: ");
        scanf("%s", newContact.address);
        contacts[*numContacts] = newContact;
        (*numContacts)++;
        printf("Contact added successfully.\n");
    }
}

void removeContact(Contact* contacts, int* numContacts) {
    if (*numContacts == 0) {
        printf("Phone book is empty. Cannot remove contact.\n");
    } else {
        char name[MAX_NAME_LEN];
        printf("Enter the name of the contact to remove: ");
        scanf("%s", name);
        int i;
        for (i = 0; i < *numContacts; i++) {
            if (strcmp(contacts[i].name, name) == 0) {
                int j;
                for (j = i; j < *numContacts - 1; j++) {
                    contacts[j] = contacts[j+1];
                }
                (*numContacts)--;
                printf("Contact removed successfully.\n");
                return;
            }
        }
        printf("Contact not found.\n");
    }
}

void searchContacts(Contact* contacts, int numContacts) {
    char name[MAX_NAME_LEN];
    printf("Enter the name of the contact to search for: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Address: %s\n", contacts[i].address);
            return;
        }
    }
    printf("Contact not found.\n");
}

void printContacts(Contact* contacts, int numContacts) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
    } else {
        int i;
        printf("Name\t\tPhone\t\tAddress\n");
        for (i = 0; i < numContacts; i++) {
            printf("%s\t\t%s\t\t%s\n", contacts[i].name, contacts[i].phone, contacts[i].address);
        }
    }
}
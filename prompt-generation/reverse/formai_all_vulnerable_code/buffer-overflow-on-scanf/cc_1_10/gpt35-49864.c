//FormAI DATASET v1.0 Category: Phone Book ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 10

typedef struct contact {
    char name[30];
    char phone[15];
} Contact;

void addContact(Contact*, int*);
void deleteContact(Contact*, int*);
void printContacts(Contact*, int*);
void searchContacts(Contact*, int*);

int main() {
    Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    do {
        printf("C Phone Book Menu \n"
                "1. Add Contact\n"
                "2. Delete Contact\n"
                "3. Search Contacts\n"
                "4. Print Contacts\n"
                "5. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;

            case 2:
                deleteContact(contacts, &numContacts);
                break;

            case 3:
                searchContacts(contacts, &numContacts);
                break;

            case 4:
                printContacts(contacts, &numContacts);
                break;

            case 5:
                printf("Exiting C Phone Book\n");
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void addContact(Contact* contacts, int* numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Phone book is full\n");
        return;
    }

    Contact newContact;
    printf("Enter name: ");
    gets(newContact.name);

    printf("Enter phone number: ");
    gets(newContact.phone);

    contacts[*numContacts] = newContact;
    (*numContacts)++;
    printf("Contact added successfully\n");
}

void deleteContact(Contact* contacts, int* numContacts) {
    if (*numContacts == 0) {
        printf("Phone book is empty\n");
        return;
    }

    char name[30];
    printf("Enter name of contact to delete: ");
    gets(name);

    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            for (int j = i; j < *numContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*numContacts)--;
            printf("Contact deleted successfully\n");
            return;
        }
    }

    printf("Contact not found\n");
}

void printContacts(Contact* contacts, int* numContacts) {
    if (*numContacts == 0) {
        printf("Phone book is empty\n");
        return; 
    }

    printf("Name\t\tPhone Number\n");
    for (int i = 0; i < *numContacts; i++) {
        printf("%s\t\t%s\n", contacts[i].name, contacts[i].phone);
    }
}

void searchContacts(Contact* contacts, int* numContacts) {
    if (*numContacts == 0) {
        printf("Phone book is empty\n");
        return;
    }

    char name[30];
    printf("Enter name of contact to search: ");
    gets(name);

    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }

    printf("Contact not found\n");
}
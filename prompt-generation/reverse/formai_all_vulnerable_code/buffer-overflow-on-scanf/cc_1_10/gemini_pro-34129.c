//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Contact {
    char name[50];
    char phone[20];
} Contact;

Contact contacts[100];
int numContacts = 0;

void addContact() {
    printf("Enter contact name: ");
    scanf(" %[^\n]", contacts[numContacts].name);
    printf("Enter contact phone: ");
    scanf(" %[^\n]", contacts[numContacts].phone);
    numContacts++;
}

void deleteContact() {
    char name[50];
    printf("Enter contact name to delete: ");
    scanf(" %[^\n]", name);
    for (int i=0; i<numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j=i; j<numContacts-1; j++) {
                contacts[j] = contacts[j+1];
            }
            numContacts--;
            printf("Contact deleted.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void searchContact() {
    char name[50];
    printf("Enter contact name to search: ");
    scanf(" %[^\n]", name);
    for (int i=0; i<numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void listContacts() {
    printf("Contacts:\n");
    for (int i=0; i<numContacts; i++) {
        printf("%s\n", contacts[i].name);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Search contact\n");
        printf("4. List contacts\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                deleteContact();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                listContacts();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}
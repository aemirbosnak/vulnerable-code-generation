//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char phone[15];
    char address[50];
} Contact;

Contact contacts[MAX_CONTACTS];
int numContacts = 0;

void printMenu();
void addContact();
void deleteContact();
void searchContact();
void initContacts();

int main() {
    initContacts();
    char choice;

    do {
        printMenu();
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                addContact();
                break;
            case 'D':
                deleteContact();
                break;
            case 'S':
                searchContact();
                break;
            case 'E':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'E');

    return 0;
}

void printMenu() {
    printf("\n********** Phone Book **********\n");
    printf("A)dd Contact\n");
    printf("D)elete Contact\n");
    printf("S)earch Contact\n");
    printf("E)xit\n");
}

void addContact() {
    if (numContacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter contact name: ");
    scanf("%s", contacts[numContacts].name);

    printf("Enter phone number: ");
    scanf("%s", contacts[numContacts].phone);

    printf("Enter address: ");
    scanf("%s", contacts[numContacts].address);

    numContacts++;
    printf("Contact added successfully.\n");
}

void deleteContact() {
    char name[NAME_LENGTH];
    int i;

    printf("Enter name of contact to delete: ");
    scanf("%s", name);

    for (i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < numContacts - 1; j++) {
                contacts[j] = contacts[j+1];
            }
            numContacts--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

void searchContact() {
    char name[NAME_LENGTH];
    int i;

    printf("Enter name of contact to search: ");
    scanf("%s", name);

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

void initContacts() {
    memset(contacts, 0, sizeof(contacts));
}
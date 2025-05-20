//FormAI DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 10
#define MAX_CONTACTS 5

struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

void addContact(struct Contact* contacts, int* contactCount) {
    if (*contactCount < MAX_CONTACTS) {
        struct Contact newContact;
        printf("\nEnter name: ");
        scanf("%s", newContact.name);
        printf("Enter phone: ");
        scanf("%s", newContact.phone);
        contacts[*contactCount] = newContact;
        (*contactCount)++;
        printf("\nContact added!\n");
    }
    else {
        printf("\nPhone book is full!\n");
    }
}

void searchContacts(struct Contact* contacts, int contactCount) {
    char searchTerm[MAX_NAME_LENGTH];
    printf("\nEnter name to search: ");
    scanf("%s", searchTerm);
    int foundCount = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strstr(contacts[i].name, searchTerm) != NULL) {
            foundCount++;
            printf("\n%s: %s", contacts[i].name, contacts[i].phone);
        }
    }
    if (foundCount == 0) {
        printf("\nContact not found!\n");
    }
}

void printContacts(struct Contact* contacts, int contactCount) {
    printf("\nPHONE BOOK:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].phone);
    }
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int contactCount = 0;

    printf("Welcome to the PUZZLING PHONE BOOK PROGRAM\n\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1) Add contact\n");
        printf("2) Search contacts\n");
        printf("3) Print all contacts\n");
        printf("4) Exit\n\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addContact(contacts, &contactCount);
                break;
            case 2:
                searchContacts(contacts, contactCount);
                break;
            case 3:
                printContacts(contacts, contactCount);
                break;
            case 4:
                printf("\nThank you for using the PUZZLING PHONE BOOK PROGRAM!\n");
                return 0;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }
}
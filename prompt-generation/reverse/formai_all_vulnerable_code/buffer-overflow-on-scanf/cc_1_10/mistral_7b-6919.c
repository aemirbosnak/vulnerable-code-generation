//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
    int id;
} Contact;

Contact phoneBook[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter contact name: ");
    scanf("%s", phoneBook[numContacts].name);

    printf("Enter phone number: ");
    scanf("%s", phoneBook[numContacts].phone);

    printf("Enter email address: ");
    scanf("%s", phoneBook[numContacts].email);

    printf("Enter contact id: ");
    scanf("%d", &phoneBook[numContacts].id);

    numContacts++;
}

void displayContacts() {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("\nList of Contacts:\n");
    printf("--------------------\n");

    for (int i = 0; i < numContacts; i++) {
        printf("\nID: %d\nName: %s\nPhone: %s\nEmail: %s", phoneBook[i].id, phoneBook[i].name, phoneBook[i].phone, phoneBook[i].email);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                printf("Exiting Phone Book.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
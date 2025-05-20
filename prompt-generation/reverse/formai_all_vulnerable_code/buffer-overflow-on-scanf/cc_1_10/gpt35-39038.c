//FormAI DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[15];
} Contact;

int numContacts = 0;
Contact phoneBook[MAX_CONTACTS];

void addContact() {
    if (numContacts >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    Contact newContact;

    printf("Enter name: ");
    scanf("%s", newContact.name);

    printf("Enter phone number: ");
    scanf("%s", newContact.phone);

    phoneBook[numContacts] = newContact;
    numContacts++;

    printf("Contact added successfully.\n");
}

void searchContact() {
    char name[50];
    printf("Enter name: ");
    scanf("%s", name);

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(name, phoneBook[i].name) == 0) {
            printf("Name: %s\nPhone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void displayContacts() {
    printf("Phone Book:\n");

    for (int i = 0; i < numContacts; i++) {
        printf("%d. %s - %s\n", i+1, phoneBook[i].name, phoneBook[i].phone);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n");
        printf("Menu:\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                displayContacts();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
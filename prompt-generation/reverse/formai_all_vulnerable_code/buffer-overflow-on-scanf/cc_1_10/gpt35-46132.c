//FormAI DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct Contact {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

int numContacts = 0;
Contact contacts[MAX_CONTACTS];

void addContact() {
    printf("Enter name:\n");
    scanf("%s", contacts[numContacts].name);
    printf("Enter phone number:\n");
    scanf("%s", contacts[numContacts].phone);
    printf("Enter email address:\n");
    scanf("%s", contacts[numContacts].email);

    numContacts++;
    printf("Contact added!\n");
}

void displayContacts() {
    if (numContacts == 0) {
        printf("There are no contacts to display.\n");
    } else {
        printf("Name\t\tPhone\t\tEmail\n");
        printf("----\t\t-----\t\t-----\n");
        for (int i = 0; i < numContacts; i++) {
            printf("%s\t\t%s\t\t%s\n", 
                contacts[i].name, 
                contacts[i].phone, 
                contacts[i].email);
        }
    }
}

void searchContacts(char name[]) {
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Name\t\tPhone\t\tEmail\n");
            printf("----\t\t-----\t\t-----\n");
            printf("%s\t\t%s\t\t%s\n", 
                contacts[i].name, 
                contacts[i].phone, 
                contacts[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No contacts were found with that name.\n");
    }
}

int main() {
    int choice = 0;
    while (choice != 4) {
        printf("Please choose an option:\n");
        printf("1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Search contacts\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3: {
                char name[50];
                printf("Enter name to search:\n");
                scanf("%s", name);
                searchContacts(name);
                break;
            }
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");
    }

    return 0;
}
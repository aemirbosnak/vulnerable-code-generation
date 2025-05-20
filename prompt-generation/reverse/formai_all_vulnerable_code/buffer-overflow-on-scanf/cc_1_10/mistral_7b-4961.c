//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 10

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts < MAX_CONTACTS) {
        printf("Enter contact name: ");
        scanf("%s", phoneBook[numContacts].name);

        printf("Enter contact phone number: ");
        scanf("%s", phoneBook[numContacts].phone);

        printf("Enter contact email address: ");
        scanf("%s", phoneBook[numContacts].email);

        numContacts++;
        printf("Contact added successfully!\n");
    } else {
        printf("Phone book is full.\n");
    }
}

void searchByName() {
    char name[50];
    int found = 0;

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone: %s\n", phoneBook[i].phone);
            printf("Email: %s\n", phoneBook[i].email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void searchByPhone() {
    char phone[20];
    int found = 0;

    printf("Enter phone number to search: ");
    scanf("%s", phone);

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].phone, phone) == 0) {
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone: %s\n", phoneBook[i].phone);
            printf("Email: %s\n", phoneBook[i].email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add Contact\n");
        printf("2. Search by Name\n");
        printf("3. Search by Phone\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchByName();
                break;
            case 3:
                searchByPhone();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
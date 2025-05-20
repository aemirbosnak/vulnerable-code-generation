//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 32
#define MAX_PHONE_LENGTH 16
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    char phone[MAX_PHONE_LENGTH + 1];
} Contact;

Contact contacts[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts >= MAX_CONTACTS) {
        printf("Sorry, the phone book is full.\n");
        return;
    }

    char name[MAX_NAME_LENGTH + 1];
    char phone[MAX_PHONE_LENGTH + 1];

    printf("Enter the contact's name: ");
    scanf("%s", name);

    printf("Enter the contact's phone number: ");
    scanf("%s", phone);

    strcpy(contacts[numContacts].name, name);
    strcpy(contacts[numContacts].phone, phone);

    numContacts++;
}

void removeContact() {
    if (numContacts == 0) {
        printf("Sorry, the phone book is empty.\n");
        return;
    }

    char name[MAX_NAME_LENGTH + 1];

    printf("Enter the name of the contact to remove: ");
    scanf("%s", name);

    int index = -1;

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Sorry, the contact could not be found.\n");
        return;
    }

    for (int i = index; i < numContacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    numContacts--;
}

void searchContact() {
    if (numContacts == 0) {
        printf("Sorry, the phone book is empty.\n");
        return;
    }

    char name[MAX_NAME_LENGTH + 1];

    printf("Enter the name of the contact to search for: ");
    scanf("%s", name);

    int index = -1;

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Sorry, the contact could not be found.\n");
        return;
    }

    printf("Contact found:\n");
    printf("Name: %s\n", contacts[index].name);
    printf("Phone: %s\n", contacts[index].phone);
}

void printContacts() {
    if (numContacts == 0) {
        printf("Sorry, the phone book is empty.\n");
        return;
    }

    printf("Contacts:\n");

    for (int i = 0; i < numContacts; i++) {
        printf("%s - %s\n", contacts[i].name, contacts[i].phone);
    }
}

int main() {
    int choice;

    do {
        printf("Choose an option:\n");
        printf("1. Add a contact\n");
        printf("2. Remove a contact\n");
        printf("3. Search for a contact\n");
        printf("4. Print the contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                removeContact();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                printContacts();
                break;
            case 5:
                exit(0);
        }
    } while (choice != 5);

    return 0;
}
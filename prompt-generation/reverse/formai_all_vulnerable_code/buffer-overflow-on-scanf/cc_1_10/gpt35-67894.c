//FormAI DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include <stdio.h>
#define MAX_CONTACTS 100

// structure for storing contact information
struct contact {
    char name[50];
    char phone[20];
};

// function for adding new contact
void addContact(struct contact contacts[], int* numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", contacts[*numContacts].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[*numContacts].phone);

    (*numContacts)++;
    printf("Contact added successfully.\n");
}

// function for searching contact by name
void searchContact(struct contact contacts[], int numContacts) {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// function for displaying all contacts
void displayContacts(struct contact contacts[], int numContacts) {
    printf("Name\t\tPhone\n");

    for (int i = 0; i < numContacts; i++) {
        printf("%-15s%s\n", contacts[i].name, contacts[i].phone);
    }
}

int main() {
    struct contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    do {
        printf("\n1. Add a new contact\n");
        printf("2. Search contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                searchContact(contacts, numContacts);
                break;
            case 3:
                displayContacts(contacts, numContacts);
                break;
            case 4:
                printf("Exiting phone book.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
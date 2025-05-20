//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum number of contacts that can be stored

// Structure to store contact information
struct contact {
    char name[50];
    char phone[20];
};

// Function to add a new contact to the phone book
void addContact(struct contact contacts[], int size) {
    if (size >= MAX_SIZE) {
        printf("Phone book is full. Cannot add any more contacts.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", contacts[size].name);

    printf("Enter phone number: ");
    scanf("%s", contacts[size].phone);

    printf("Contact added successfully!\n");
    size++;
}

// Function to search for a contact in the phone book
int searchContact(struct contact contacts[], int size, char name[]) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found!\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone number: %s\n", contacts[i].phone);
            return i;
        }
    }

    printf("Contact not found.\n");
    return -1;
}

// Function to delete a contact from the phone book
void deleteContact(struct contact contacts[], int size) {
    int i, choice;

    printf("Enter the index of the contact you want to delete: ");
    scanf("%d", &i);

    if (i >= 0 && i < size) {
        printf("Are you sure you want to delete this contact? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            printf("Contact deleted successfully!\n");
            size--;
        } else {
            printf("Contact not deleted.\n");
        }
    } else {
        printf("Invalid index.\n");
    }
}

// Function to display all contacts in the phone book
void displayContacts(struct contact contacts[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone number: %s\n\n", contacts[i].phone);
    }
}

int main() {
    struct contact contacts[MAX_SIZE];
    int size = 0;

    while (1) {
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Delete contact\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (size >= MAX_SIZE) {
                printf("Phone book is full. Cannot add any more contacts.\n");
            } else {
                addContact(contacts, size);
            }
            break;

        case 2:
            printf("Enter name to search: ");
            char name[50];
            scanf("%s", name);
            int index = searchContact(contacts, size, name);

            if (index >= 0) {
                printf("Contact found at index %d\n", index);
            }
            break;

        case 3:
            deleteContact(contacts, size);
            break;

        case 4:
            displayContacts(contacts, size);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
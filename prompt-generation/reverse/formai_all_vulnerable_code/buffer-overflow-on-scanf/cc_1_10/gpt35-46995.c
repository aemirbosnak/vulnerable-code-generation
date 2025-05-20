//FormAI DATASET v1.0 Category: Phone Book ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100 // Maximum number of contacts supported

// Contact structure
typedef struct {
    char name[50];
    char phone[15];
    char email[50];
} Contact;

// Function prototypes
int addContact(Contact[], int);
void displayContacts(Contact[], int);
int searchContacts(Contact[], int, char[]);

int main() {
    Contact contacts[MAX_CONTACTS]; // Array to store contacts
    int count = 0; // Variable to keep track of number of contacts

    printf("Welcome to the Phone Book app!\n");

    while (1) {
        printf("\n1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Search contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count = addContact(contacts, count);
                break;
            case 2:
                displayContacts(contacts, count);
                break;
            case 3: {
                char searchName[50];
                printf("Enter the name to search: ");
                scanf("%s", searchName);

                int index = searchContacts(contacts, count, searchName);
                if (index == -1) {
                    printf("Contact not found.\n");
                } else {
                    printf("%s\t%s\t%s\n", contacts[index].name, contacts[index].phone, contacts[index].email);
                }
                break;
            }
            case 4:
                printf("Exiting Phone Book app...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Function to add a contact to the phone book
int addContact(Contact contacts[], int count) {
    if (count >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return count;
    }

    printf("Enter contact details:\n");

    printf("Name: ");
    scanf("%s", contacts[count].name);

    printf("Phone number: ");
    scanf("%s", contacts[count].phone);

    printf("Email address: ");
    scanf("%s", contacts[count].email);

    count++;
    printf("Contact added successfully!\n");

    return count;
}

// Function to display all contacts in the phone book
void displayContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Name\t\tPhone\t\tEmail\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

// Function to search for a contact by name
int searchContacts(Contact contacts[], int count, char searchName[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            return i;
        }
    }

    return -1;
}
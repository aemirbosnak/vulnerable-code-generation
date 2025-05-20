//FormAI DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 100 // maximum number of contacts

typedef struct {
    char name[50];
    char phone[20];
} Contact;

Contact phoneBook[MAX_CONTACTS]; // array to store contacts
int countContacts = 0; // counter for number of contacts

// Function to add a new contact
void addContact() {
    if (countContacts == MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }
    Contact newContact;
    printf("Enter name: ");
    scanf("%s", newContact.name);
    printf("Enter phone number: ");
    scanf("%s", newContact.phone);
    phoneBook[countContacts] = newContact;
    countContacts++;
    printf("New contact added.\n");
}

// Function to display all contacts
void displayContacts() {
    if (countContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    printf("Name\t\tPhone\n");
    for (int i = 0; i < countContacts; i++) {
        printf("%s\t\t%s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

// Function to search for a contact by name
void searchContact() {
    if (countContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    int index = -1;
    for (int i = 0; i < countContacts; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Contact not found.\n");
    } else {
        printf("Name\t\tPhone\n");
        printf("%s\t\t%s\n", phoneBook[index].name, phoneBook[index].phone);
    }
}

// Function to delete a contact by name
void deleteContact() {
    if (countContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    char deleteName[50];
    printf("Enter name to delete: ");
    scanf("%s", deleteName);
    int index = -1;
    for (int i = 0; i < countContacts; i++) {
        if (strcmp(phoneBook[i].name, deleteName) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Contact not found.\n");
    } else {
        for (int i = index; i < countContacts - 1; i++) {
            phoneBook[i] = phoneBook[i+1];
        }
        countContacts--;
        printf("Contact deleted.\n");
    }
}

int main() {
    int option = 0;
    while (option != 5) {
        printf("\nPhone Book\n");
        printf("-------------------\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit Program\n");
        printf("-------------------\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }
    return 0;
}
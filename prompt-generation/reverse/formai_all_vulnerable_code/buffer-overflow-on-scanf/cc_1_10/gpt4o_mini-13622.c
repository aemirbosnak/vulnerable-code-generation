//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int totalContacts = 0;

void addContact() {
    if (totalContacts >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", phoneBook[totalContacts].name);
    printf("Enter phone number: ");
    scanf("%s", phoneBook[totalContacts].phone);
    totalContacts++;
    printf("Contact added successfully.\n");
}

void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);

    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < totalContacts - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            totalContacts--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to search: ");
    scanf("%s", name);

    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void displayContacts() {
    if (totalContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    printf("Phone Book Contacts:\n");
    for (int i = 0; i < totalContacts; i++) {
        printf("Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                deleteContact();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
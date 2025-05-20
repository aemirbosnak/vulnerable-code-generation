//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: surprised
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
int contactCount = 0;

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    Contact newContact;
    printf("Enter Name: ");
    scanf("%s", newContact.name);
    printf("Enter Phone: ");
    scanf("%s", newContact.phone);

    phoneBook[contactCount] = newContact;
    contactCount++;
    printf("Contact added successfully!\n");
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter Name to search: ");
    scanf("%s", name);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Contact found! Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter Name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Deleting contact: %s\n", phoneBook[i].name);
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            contactCount--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts to display!\n");
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

int main() {
    int choice;
    
    do {
        printf("\n=== Phone Book ===\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
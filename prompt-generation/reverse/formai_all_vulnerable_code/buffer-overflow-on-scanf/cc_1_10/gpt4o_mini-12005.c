//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
};

struct PhoneBook {
    struct Contact contacts[MAX_CONTACTS];
    int contactCount;
};

void addContact(struct PhoneBook *pb) {
    if (pb->contactCount >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", pb->contacts[pb->contactCount].name);
    printf("Enter phone number: ");
    scanf("%s", pb->contacts[pb->contactCount].phone);
    pb->contactCount++;
    printf("Contact added successfully!\n");
}

void displayContacts(struct PhoneBook *pb) {
    if (pb->contactCount == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("\nContacts in the Phone Book:\n");
    for (int i = 0; i < pb->contactCount; i++) {
        printf("Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(struct PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < pb->contactCount; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Contact found: Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No contact found with the name '%s'.\n", name);
    }
}

void deleteContact(struct PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < pb->contactCount; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < pb->contactCount - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->contactCount--;
            printf("Contact '%s' deleted successfully!\n", name);
            break;
        }
    }
    if (!found) {
        printf("No contact found with the name '%s'.\n", name);
    }
}

void displayMenu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("-------------------------\n");
}

int main() {
    struct PhoneBook phoneBook;
    phoneBook.contactCount = 0;

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&phoneBook);
                break;
            case 2:
                displayContacts(&phoneBook);
                break;
            case 3:
                searchContact(&phoneBook);
                break;
            case 4:
                deleteContact(&phoneBook);
                break;
            case 5:
                printf("Exiting the phone book system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
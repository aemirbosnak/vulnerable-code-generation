//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} PhoneBook;

void initializePhoneBook(PhoneBook* pb) {
    pb->contactCount = 0;
}

void addContact(PhoneBook* pb) {
    if (pb->contactCount >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", pb->contacts[pb->contactCount].name);
    printf("Enter phone number: ");
    scanf(" %[^\n]", pb->contacts[pb->contactCount].phone);
    printf("Enter email: ");
    scanf(" %[^\n]", pb->contacts[pb->contactCount].email);

    pb->contactCount++;
    printf("Contact added successfully.\n");
}

void viewContacts(const PhoneBook* pb) {
    if (pb->contactCount == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("\nPhone Book Contacts:\n");
    for (int i = 0; i < pb->contactCount; i++) {
        printf("Contact #%d:\n", i + 1);
        printf("Name: %s\n", pb->contacts[i].name);
        printf("Phone: %s\n", pb->contacts[i].phone);
        printf("Email: %s\n\n", pb->contacts[i].email);
    }
}

void searchContact(const PhoneBook* pb) {
    char searchTerm[NAME_LENGTH];
    int found = 0;

    printf("Enter name to search: ");
    scanf(" %[^\n]", searchTerm);

    for (int i = 0; i < pb->contactCount; i++) {
        if (strstr(pb->contacts[i].name, searchTerm) != NULL) {
            printf("Contact found:\n");
            printf("Name: %s\n", pb->contacts[i].name);
            printf("Phone: %s\n", pb->contacts[i].phone);
            printf("Email: %s\n\n", pb->contacts[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("No contacts found with the name '%s'.\n", searchTerm);
    }
}

void deleteContact(PhoneBook* pb) {
    char nameToDelete[NAME_LENGTH];
    int found = 0;

    printf("Enter name of contact to delete: ");
    scanf(" %[^\n]", nameToDelete);

    for (int i = 0; i < pb->contactCount; i++) {
        if (strcmp(pb->contacts[i].name, nameToDelete) == 0) {
            found = 1;
            for (int j = i; j < pb->contactCount - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->contactCount--;
            printf("Contact '%s' deleted successfully.\n", nameToDelete);
            break;
        }
    }

    if (!found) {
        printf("No contact found with the name '%s'.\n", nameToDelete);
    }
}

void displayMenu() {
    printf("\n=== Phone Book Menu ===\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("========================\n");
}

int main() {
    PhoneBook myPhoneBook;
    initializePhoneBook(&myPhoneBook);

    while (1) {
        displayMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&myPhoneBook);
                break;
            case 2:
                viewContacts(&myPhoneBook);
                break;
            case 3:
                searchContact(&myPhoneBook);
                break;
            case 4:
                deleteContact(&myPhoneBook);
                break;
            case 5:
                printf("Exiting the phone book.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
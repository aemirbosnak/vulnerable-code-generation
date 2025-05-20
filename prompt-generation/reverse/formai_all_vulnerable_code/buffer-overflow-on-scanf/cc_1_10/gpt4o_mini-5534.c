//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: statistical
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

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int totalContacts;
} PhoneBook;

void initializePhoneBook(PhoneBook* phoneBook) {
    phoneBook->totalContacts = 0;
}

void addContact(PhoneBook* phoneBook) {
    if (phoneBook->totalContacts >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", phoneBook->contacts[phoneBook->totalContacts].name);
    printf("Enter phone number: ");
    scanf("%s", phoneBook->contacts[phoneBook->totalContacts].phone);
    phoneBook->totalContacts++;
    printf("Contact added successfully!\n");
}

void displayContacts(PhoneBook* phoneBook) {
    if (phoneBook->totalContacts == 0) {
        printf("No contacts in phone book!\n");
        return;
    }
    printf("\nContacts:\n");
    for (int i = 0; i < phoneBook->totalContacts; i++) {
        printf("Name: %s, Phone: %s\n", phoneBook->contacts[i].name, phoneBook->contacts[i].phone);
    }
}

void searchContact(PhoneBook* phoneBook) {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < phoneBook->totalContacts; i++) {
        if (strcmp(phoneBook->contacts[i].name, name) == 0) {
            printf("Contact found: Name: %s, Phone: %s\n", phoneBook->contacts[i].name, phoneBook->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

void deleteContact(PhoneBook* phoneBook) {
    char name[NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < phoneBook->totalContacts; i++) {
        if (strcmp(phoneBook->contacts[i].name, name) == 0) {
            for (int j = i; j < phoneBook->totalContacts - 1; j++) {
                phoneBook->contacts[j] = phoneBook->contacts[j + 1];
            }
            phoneBook->totalContacts--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void displayStatistics(PhoneBook* phoneBook) {
    printf("\nStatistics:\n");
    printf("Total contacts: %d\n", phoneBook->totalContacts);
}

int main() {
    PhoneBook phoneBook;
    initializePhoneBook(&phoneBook);

    int choice;
    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Display Statistics\n");
        printf("6. Exit\n");
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
                displayStatistics(&phoneBook);
                break;
            case 6:
                printf("Exiting phone book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
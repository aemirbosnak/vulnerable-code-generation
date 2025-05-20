//FormAI DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[20];
};

struct PhoneBook {
    struct Contact contacts[MAX_CONTACTS];
    int count;
};

void initializePhoneBook(struct PhoneBook* phonebook) {
    phonebook->count = 0;
}

void printMenu() {
    printf("\n\nPhone Book Menu\n\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Remove Contact\n");
    printf("4. Quit\n");
}

void addContact(struct PhoneBook* phonebook) {
    if (phonebook->count == MAX_CONTACTS) {
        printf("Error: Phone book is full.\n");
        return;
    }
    struct Contact contact;
    printf("Enter name: ");
    scanf("%s", contact.name);
    printf("Enter phone number: ");
    scanf("%s", contact.phone);
    phonebook->contacts[phonebook->count] = contact;
    phonebook->count++;
    printf("Contact added successfully.\n");
}

void searchContact(struct PhoneBook* phonebook) {
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    for (int i = 0; i < phonebook->count; i++) {
        if (strcmp(phonebook->contacts[i].name, searchName) == 0) {
            printf("\nName: %s\nPhone: %s\n", phonebook->contacts[i].name, phonebook->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void removeContact(struct PhoneBook* phonebook) {
    char removeName[50];
    printf("Enter name to remove: ");
    scanf("%s", removeName);
    for (int i = 0; i < phonebook->count; i++) {
        if (strcmp(phonebook->contacts[i].name, removeName) == 0) {
            for (int j = i; j < phonebook->count - 1; j++) {
                phonebook->contacts[j] = phonebook->contacts[j+1];
            }
            phonebook->count--;
            printf("Contact removed successfully.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    struct PhoneBook phonebook;
    initializePhoneBook(&phonebook);
    int choice = 0;
    while (choice != 4) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact(&phonebook);
                break;
            case 2:
                searchContact(&phonebook);
                break;
            case 3:
                removeContact(&phonebook);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: sophisticated
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
    int size;
} PhoneBook;

void initializePhoneBook(PhoneBook* phoneBook) {
    phoneBook->size = 0;
}

int addContact(PhoneBook* phoneBook, const char* name, const char* phone) {
    if (phoneBook->size >= MAX_CONTACTS) {
        return -1;  // Phone book is full
    }
    strcpy(phoneBook->contacts[phoneBook->size].name, name);
    strcpy(phoneBook->contacts[phoneBook->size].phone, phone);
    phoneBook->size++;
    return 0;  // Success
}

int deleteContact(PhoneBook* phoneBook, const char* name) {
    for (int i = 0; i < phoneBook->size; i++) {
        if (strcmp(phoneBook->contacts[i].name, name) == 0) {
            // Shift remaining contacts down
            for (int j = i; j < phoneBook->size - 1; j++) {
                phoneBook->contacts[j] = phoneBook->contacts[j + 1];
            }
            phoneBook->size--;
            return 0;  // Success
        }
    }
    return -1;  // Contact not found
}

Contact* searchContact(const PhoneBook* phoneBook, const char* name) {
    for (int i = 0; i < phoneBook->size; i++) {
        if (strcmp(phoneBook->contacts[i].name, name) == 0) {
            return &phoneBook->contacts[i];  // Found contact
        }
    }
    return NULL;  // Not found
}

void displayContacts(const PhoneBook* phoneBook) {
    if (phoneBook->size == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    printf("\nContacts:\n");
    for (int i = 0; i < phoneBook->size; i++) {
        printf("Name: %s, Phone: %s\n", phoneBook->contacts[i].name, phoneBook->contacts[i].phone);
    }
}

void showMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Search Contact\n");
    printf("4. Display Contacts\n");
    printf("5. Exit\n");
}

int main() {
    PhoneBook phoneBook;
    initializePhoneBook(&phoneBook);
    
    int choice;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline character

                printf("Enter phone: ");
                fgets(phone, PHONE_LENGTH, stdin);
                phone[strcspn(phone, "\n")] = 0;  // Remove newline character

                if (addContact(&phoneBook, name, phone) == 0) {
                    printf("Contact added successfully.\n");
                } else {
                    printf("Phone book is full. Cannot add contact.\n");
                }
                break;
            case 2:
                printf("Enter name of the contact to delete: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline character

                if (deleteContact(&phoneBook, name) == 0) {
                    printf("Contact deleted successfully.\n");
                } else {
                    printf("Contact not found.\n");
                }
                break;
            case 3:
                printf("Enter name to search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline character

                Contact* contact = searchContact(&phoneBook, name);
                if (contact) {
                    printf("Contact found - Name: %s, Phone: %s\n", contact->name, contact->phone);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            case 4:
                displayContacts(&phoneBook);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
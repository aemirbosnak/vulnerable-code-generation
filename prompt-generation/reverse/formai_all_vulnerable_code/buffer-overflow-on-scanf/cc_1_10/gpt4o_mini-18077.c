//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

typedef struct PhoneBook {
    Contact contacts[MAX_CONTACTS];
    int count;
} PhoneBook;

void initializePhoneBook(PhoneBook* pb) {
    pb->count = 0;
}

void addContact(PhoneBook* pb) {
    if (pb->count >= MAX_CONTACTS) {
        printf("PhoneBook is full. Cannot add more contacts.\n");
        return;
    }
    
    Contact newContact;
    printf("Enter name: ");
    getchar(); // Clear newline character from buffer
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0';  // Remove newline

    printf("Enter phone number: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0'; // Remove newline

    pb->contacts[pb->count] = newContact;
    pb->count++;
    printf("Contact added successfully!\n");
}

void displayContacts(const PhoneBook* pb) {
    if (pb->count == 0) {
        printf("PhoneBook is empty.\n");
        return;
    }

    printf("\nPhone Book Contacts:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(const PhoneBook* pb) {
    if (pb->count == 0) {
        printf("PhoneBook is empty.\n");
        return;
    }

    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    getchar(); // Clear newline character from buffer
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  // Remove newline

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, searchName) == 0) {
            printf("Found Contact - Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact(PhoneBook* pb) {
    if (pb->count == 0) {
        printf("PhoneBook is empty.\n");
        return;
    }

    char deleteName[NAME_LENGTH];
    printf("Enter name to delete: ");
    getchar(); // Clear newline character from buffer
    fgets(deleteName, NAME_LENGTH, stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';  // Remove newline

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, deleteName) == 0) {
            for (int j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->count--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);
    
    int choice;
    do {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&pb);
                break;
            case 2:
                displayContacts(&pb);
                break;
            case 3:
                searchContact(&pb);
                break;
            case 4:
                deleteContact(&pb);
                break;
            case 5:
                printf("Exiting phone book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
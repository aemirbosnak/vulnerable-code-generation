//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
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

void initializePhoneBook(PhoneBook *pb) {
    pb->size = 0;
}

int addContact(PhoneBook *pb, const char *name, const char *phone) {
    if (pb->size >= MAX_CONTACTS) {
        return -1; // Phone book full
    }
    strncpy(pb->contacts[pb->size].name, name, NAME_LENGTH);
    strncpy(pb->contacts[pb->size].phone, phone, PHONE_LENGTH);
    pb->size++;
    return 0; // Success
}

void displayContacts(const PhoneBook *pb) {
    if (pb->size == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    printf("\nPhone Book Contacts:\n");
    for (int i = 0; i < pb->size; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

int searchContact(const PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Found Contact - Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return i;
        }
    }
    printf("Contact not found.\n");
    return -1; // Not found
}

int deleteContact(PhoneBook *pb, const char *name) {
    int index = searchContact(pb, name);
    if (index == -1) {
        return -1; // Not found
    }
    for (int i = index; i < pb->size - 1; i++) {
        pb->contacts[i] = pb->contacts[i + 1];
    }
    pb->size--;
    printf("Deleted contact: %s\n", name);
    return 0; // Success
}

void displayMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

int main() {
    PhoneBook phoneBook;
    initializePhoneBook(&phoneBook);
    
    int choice;
    char name[NAME_LENGTH], phone[PHONE_LENGTH];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter Phone: ");
                fgets(phone, PHONE_LENGTH, stdin);
                phone[strcspn(phone, "\n")] = 0; // Remove newline
                if (addContact(&phoneBook, name, phone) == 0) {
                    printf("Contact added successfully.\n");
                } else {
                    printf("Phone book is full, cannot add contact.\n");
                }
                break;
            case 2:
                displayContacts(&phoneBook);
                break;
            case 3:
                printf("Enter Name to search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                searchContact(&phoneBook, name);
                break;
            case 4:
                printf("Enter Name to delete: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                if (deleteContact(&phoneBook, name) == 0) {
                    printf("Contact deleted successfully.\n");
                } else {
                    printf("Contact not found, deletion failed.\n");
                }
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}
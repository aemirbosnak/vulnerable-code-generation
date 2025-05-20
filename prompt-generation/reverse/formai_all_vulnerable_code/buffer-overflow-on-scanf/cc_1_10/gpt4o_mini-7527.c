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
    int count;
} PhoneBook;

void initializePhoneBook(PhoneBook *phoneBook) {
    phoneBook->count = 0;
}

void addContact(PhoneBook *phoneBook, char *name, char *phone) {
    if (phoneBook->count < MAX_CONTACTS) {
        strcpy(phoneBook->contacts[phoneBook->count].name, name);
        strcpy(phoneBook->contacts[phoneBook->count].phone, phone);
        phoneBook->count++;
        printf("Contact added successfully: %s, %s\n", name, phone);
    } else {
        printf("Phone Book is full! Cannot add more contacts.\n");
    }
}

void displayContacts(PhoneBook *phoneBook) {
    if (phoneBook->count == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\nPhone Book Contacts:\n");
    for (int i = 0; i < phoneBook->count; i++) {
        printf("Contact [%d]: %s, Phone: %s\n", i + 1, phoneBook->contacts[i].name, phoneBook->contacts[i].phone);
    }
}

void searchContact(PhoneBook *phoneBook, char *name) {
    for (int i = 0; i < phoneBook->count; i++) {
        if (strcmp(phoneBook->contacts[i].name, name) == 0) {
            printf("Contact found: %s, Phone: %s\n", name, phoneBook->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found: %s\n", name);
}

void displayStatistics(PhoneBook *phoneBook) {
    printf("\n=== Phone Book Statistics ===\n");
    printf("Total Contacts: %d\n", phoneBook->count);
    if (phoneBook->count > 0) {
        printf("Most Recently Added Contact: %s, Phone: %s\n", 
            phoneBook->contacts[phoneBook->count - 1].name, 
            phoneBook->contacts[phoneBook->count - 1].phone);
    } else {
        printf("No contacts added yet.\n");
    }
}

int main() {
    PhoneBook phoneBook;
    initializePhoneBook(&phoneBook);

    int choice;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];

    while (1) {
        printf("\n*** Phone Book Menu ***\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Display Statistics\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character after choice

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character
                printf("Enter phone: ");
                fgets(phone, PHONE_LENGTH, stdin);
                phone[strcspn(phone, "\n")] = '\0'; // Remove newline character
                addContact(&phoneBook, name, phone);
                break;
            case 2:
                displayContacts(&phoneBook);
                break;
            case 3:
                printf("Enter name to search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character
                searchContact(&phoneBook, name);
                break;
            case 4:
                displayStatistics(&phoneBook);
                break;
            case 5:
                printf("Exiting the Phone Book.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
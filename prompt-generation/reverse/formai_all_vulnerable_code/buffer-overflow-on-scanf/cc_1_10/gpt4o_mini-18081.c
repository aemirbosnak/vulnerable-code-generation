//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: modular
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

void initializePhoneBook(PhoneBook *pb);
void addContact(PhoneBook *pb);
void viewContacts(const PhoneBook *pb);
void searchContact(const PhoneBook *pb);
void deleteContact(PhoneBook *pb);
void displayMenu();
void handleExit();

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);

    int choice;
    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&pb);
                break;
            case 2:
                viewContacts(&pb);
                break;
            case 3:
                searchContact(&pb);
                break;
            case 4:
                deleteContact(&pb);
                break;
            case 5:
                handleExit();
                break;
            default:
                printf("Invalid choice, please try again!\n");
        }
    } while (choice != 5);

    return 0;
}

void initializePhoneBook(PhoneBook *pb) {
    pb->totalContacts = 0;
}

void addContact(PhoneBook *pb) {
    if (pb->totalContacts >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    
    printf("Enter name of the contact: ");
    scanf(" %[^\n]", pb->contacts[pb->totalContacts].name);
    printf("Enter phone number: ");
    scanf(" %[^\n]", pb->contacts[pb->totalContacts].phone);
    pb->totalContacts++;
    printf("Contact added successfully!\n");
}

void viewContacts(const PhoneBook *pb) {
    if (pb->totalContacts == 0) {
        printf("No contacts found!\n");
        return;
    }

    printf("\nPhone Book Contacts:\n");
    for (int i = 0; i < pb->totalContacts; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
    printf("\n");
}

void searchContact(const PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < pb->totalContacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Contact found - Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

void deleteContact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < pb->totalContacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            for (int j = i; j < pb->totalContacts - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->totalContacts--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void displayMenu() {
    printf("==== Phone Book Menu ====\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

void handleExit() {
    printf("Exiting the Phone Book application. Goodbye!\n");
}
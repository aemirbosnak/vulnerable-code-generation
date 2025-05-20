//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: imaginative
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

void initializePhoneBook(PhoneBook* pb) {
    pb->count = 0;
}

void addContact(PhoneBook* pb) {
    if (pb->count >= MAX_CONTACTS) {
        printf("Mystical limit reached! Cannot add more contacts.\n");
        return;
    }

    Contact newContact;
    printf("Enter the name of the enchanting being: ");
    scanf("%s", newContact.name);
    printf("Enter their magical phone number: ");
    scanf("%s", newContact.phone);

    pb->contacts[pb->count++] = newContact;
    printf("Contact added to the mythical phone book.\n");
}

void viewContacts(const PhoneBook* pb) {
    printf("=== Magical Contacts ===\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%d. %s: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(const PhoneBook* pb) {
    char searchName[NAME_LENGTH];
    printf("Enter the name of the enchanting being to conjure: ");
    scanf("%s", searchName);

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, searchName) == 0) {
            printf("Found! %s: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }

    printf("Alas! The enchanting being is not found in the magical realm.\n");
}

void displayMenu() {
    printf("\n=== Welcome to the Magical Phone Book ===\n");
    printf("1. Add a new contact\n");
    printf("2. View all contacts\n");
    printf("3. Search for a contact\n");
    printf("4. Exit the enchanted realm\n");
}

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);

    int choice;
    do {
        displayMenu();
        printf("Choose a mystical action (1-4): ");
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
                printf("You have chosen to leave the enchanted realm. Farewell!\n");
                break;
            default:
                printf("That's not a magical choice! Try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
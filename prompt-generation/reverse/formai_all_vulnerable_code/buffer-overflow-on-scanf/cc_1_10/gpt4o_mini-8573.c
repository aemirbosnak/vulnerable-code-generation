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
    int size;
} PhoneBook;

void initPhoneBook(PhoneBook *pb) {
    pb->size = 0;
    printf("Welcome to the Enchanted Phone Book!\n");
}

void addContact(PhoneBook *pb) {
    if (pb->size >= MAX_CONTACTS) {
        printf("The mystical book is full, cannot add more contacts!\n");
        return;
    }

    Contact newContact;
    printf("Enter the name of the new contact: ");
    scanf(" %[^\n]", newContact.name);
    printf("Enter the phone number: ");
    scanf(" %[^\n]", newContact.phone);

    pb->contacts[pb->size++] = newContact;
    printf("The contact of %s has been inscribed into the phone book!\n", newContact.name);
}

void displayContacts(const PhoneBook *pb) {
    if (pb->size == 0) {
        printf("The phone book is as empty as a desert!\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < pb->size; i++) {
        printf("Contact %d: %s - %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
    printf("--------------------\n");
}

void deleteContact(PhoneBook *pb) {
    if (pb->size == 0) {
        printf("You cannot erase the names if there are none written!\n");
        return;
    }

    char nameToDelete[NAME_LENGTH];
    printf("Enter the name of the contact to erase from existence: ");
    scanf(" %[^\n]", nameToDelete);

    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, nameToDelete) == 0) {
            pb->contacts[i] = pb->contacts[pb->size - 1]; // Move last contact to this position
            pb->size--;
            printf("The contact of %s has been erased from the mystical pages.\n", nameToDelete);
            return;
        }
    }

    printf("Alas! No such contact found in the enchanted book!\n");
}

void searchContact(const PhoneBook *pb) {
    char nameToSearch[NAME_LENGTH];
    printf("Enter the name of the contact to seek: ");
    scanf(" %[^\n]", nameToSearch);

    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, nameToSearch) == 0) {
            printf("Found! The contact of %s is inscribed as: %s\n", nameToSearch, pb->contacts[i].phone);
            return;
        }
    }

    printf("The search yielded no results. The name may be lost in time.\n");
}

void displayMenu() {
    printf("\n--- Enchanted Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Search Contact\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    PhoneBook pb;
    initPhoneBook(&pb);

    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&pb);
                break;
            case 2:
                displayContacts(&pb);
                break;
            case 3:
                deleteContact(&pb);
                break;
            case 4:
                searchContact(&pb);
                break;
            case 5:
                printf("Exiting the enchanted realm of contacts. Farewell!\n");
                exit(0);
            default:
                printf("That is not a valid choice, please try again!\n");
        }
    }

    return 0;
}
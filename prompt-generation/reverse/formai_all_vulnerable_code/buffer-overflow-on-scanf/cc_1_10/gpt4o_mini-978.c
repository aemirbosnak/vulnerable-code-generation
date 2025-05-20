//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: shocked
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

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Oh no! The phone book is full! Can't add more contacts!\n");
        return;
    }

    printf("Entering new contact, brace yourself...\n");
    printf("Name: ");
    scanf(" %[^\n]", phoneBook[contactCount].name);
    printf("Phone: ");
    scanf(" %[^\n]", phoneBook[contactCount].phone);

    contactCount++;
    printf("Contact added successfully! Total contacts: %d\n", contactCount);
    printf("Phew! That was intense!\n");
}

void searchContact() {
    char searchName[NAME_LENGTH];
    printf("Searching for someone? Type their name...\n");
    printf("Name: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            printf("Found: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }

    printf("What?! No such contact found with the name: %s!\n", searchName);
}

void displayContacts() {
    if (contactCount == 0) {
        printf("Whoa! The phone book is empty! No contacts to display!\n");
        return;
    }

    printf("Displaying all contacts... Hold your breath!\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void deleteContact() {
    if (contactCount == 0) {
        printf("Yikes! No contacts to delete!\n");
        return;
    }

    int deleteIndex;
    printf("Which contact would you like to delete? (1 to %d): ", contactCount);
    scanf("%d", &deleteIndex);

    if (deleteIndex < 1 || deleteIndex > contactCount) {
        printf("Argh! Invalid choice! Try again...\n");
        return;
    }

    for (int i = deleteIndex - 1; i < contactCount - 1; i++) {
        phoneBook[i] = phoneBook[i + 1];
    }
    contactCount--;

    printf("Deleted contact! Total contacts left: %d\n", contactCount);
}

void showMenu() {
    while (1) {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                displayContacts();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting... Until we meet again!\n");
                exit(0);
            default:
                printf("Oops! That's not a valid choice! Try again...\n");
        }
    }
}

int main() {
    printf("Welcome to the SHOCKING Phone Book!\n");
    showMenu();
    return 0;
}
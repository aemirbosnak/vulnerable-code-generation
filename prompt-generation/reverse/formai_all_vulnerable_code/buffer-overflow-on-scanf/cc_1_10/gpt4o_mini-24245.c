//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: happy
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
        printf("Oh no! The phone book is full. Can't add more contacts.\n");
        return;
    }
    
    printf("Yay! Let's add a new contact!\n");
    printf("Enter name: ");
    scanf(" %[^\n]", phoneBook[contactCount].name);
    printf("Enter phone number: ");
    scanf(" %[^\n]", phoneBook[contactCount].phone);
    contactCount++;
    printf("Hooray! Contact added successfully!\n\n");
}

void searchContact() {
    char searchName[NAME_LENGTH];
    printf("Who are you looking for? Enter the name: ");
    scanf(" %[^\n]", searchName);
    
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            printf("Found you! %s's phone number is: %s\n\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Oops! No contact found with the name %s.\n\n", searchName);
}

void displayContacts() {
    if (contactCount == 0) {
        printf("The phone book is empty! Let's fill it with happy contacts!\n\n");
        return;
    }

    printf("Here are your happy contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s, Phone Number: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
    printf("\n");
}

void displayMenu() {
    printf("Welcome to the Happy Phone Book!\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Display All Contacts\n");
    printf("4. Exit\n");
    printf("What would you like to do? ");
}

int main() {
    int choice;
    do {
        displayMenu();
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
                printf("Thank you for using the Happy Phone Book! Goodbye!\n");
                break;
            default:
                printf("Oops! That's not a valid choice. Please try again!\n\n");
        }
    } while (choice != 4);

    return 0;
}
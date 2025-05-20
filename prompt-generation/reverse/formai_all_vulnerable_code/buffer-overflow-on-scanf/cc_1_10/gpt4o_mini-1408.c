//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: cheerful
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

void displayMenu() {
    printf("\n=== Welcome to the Cheerful Phone Book! ===\n");
    printf("1. Add a new contact\n");
    printf("2. Display all contacts\n");
    printf("3. Search for a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Exit\n");
    printf("Please choose an option (1-5): ");
}

void addContact(Contact *contacts, int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Oops! Phone book is full! Can't add more contacts.\n");
        return;
    }

    printf("Enter the name of the contact: ");
    scanf(" %[^\n]", contacts[*count].name);
    printf("Enter the phone number of the contact: ");
    scanf(" %[^\n]", contacts[*count].phone);
    (*count)++;
    printf("Yay! Contact added successfully!\n");
}

void displayContacts(Contact *contacts, int count) {
    if (count == 0) {
        printf("Your phone book is empty! Let's add some happy contacts!\n");
        return;
    }

    printf("\n=== Your Contacts ===\n");
    for (int i = 0; i < count; i++) {
        printf("Contact %d: %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void searchContact(Contact *contacts, int count) {
    char searchName[NAME_LENGTH];
    printf("Enter the name of the contact to search: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Found! %s - %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Oops! No contact found with the name %s. Let's try again!\n", searchName);
}

void deleteContact(Contact *contacts, int *count) {
    char deleteName[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]", deleteName);

    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, deleteName) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Hooray! Contact %s has been deleted!\n", deleteName);
            return;
        }
    }
    printf("Whoops! No contact found with the name %s to delete!\n", deleteName);
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                displayContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                deleteContact(contacts, &count);
                break;
            case 5:
                printf("Thank you for using the Cheerful Phone Book! Have a great day!\n");
                exit(0);
            default:
                printf("Oh no! That's not a valid option. Please try again!\n");
        }
    }
    
    return 0;
}
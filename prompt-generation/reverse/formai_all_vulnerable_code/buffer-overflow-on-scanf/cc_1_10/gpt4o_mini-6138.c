//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Oops! Phone book full. Can't add more contacts.\n");
        return;
    }
    Contact newContact;
    printf("Enter name: ");
    scanf(" %[^\n]", newContact.name);
    printf("Enter phone: ");
    scanf(" %[^\n]", newContact.phone);
    phoneBook[contactCount++] = newContact;
    printf("Contact added: %s - %s\n", newContact.name, newContact.phone);
}

void searchContact() {
    char searchName[NAME_LEN];
    printf("Who are you looking for? ");
    scanf(" %[^\n]", searchName);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            printf("Found! %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Sorry, %s is not in the phone book.\n", searchName);
}

void deleteContact() {
    char deleteName[NAME_LEN];
    printf("Which contact do you want to remove? ");
    scanf(" %[^\n]", deleteName);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, deleteName) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            contactCount--;
            printf("Contact %s has been removed. Bye-bye!\n", deleteName);
            return;
        }
    }
    printf("Contact not found! Can't delete what isn't there!\n");
}

void viewContacts() {
    if (contactCount == 0) {
        printf("Your phone book is empty. No friends? No contacts? Oh no!\n");
        return;
    }
    printf("Here's your phone book:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d: %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void displayMenu() {
    printf("\n--- Welcome to the Quirky Phone Book! ---\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Delete Contact\n");
    printf("4. View Contacts\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    
    while (1) {
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
                deleteContact();
                break;
            case 4:
                viewContacts();
                break;
            case 5:
                printf("Thank you for using the Quirky Phone Book! Goodbye!\n");
                exit(0);
            default:
                printf("Yikes! Invalid option. Please choose again.\n");
        }
    }
    
    return 0;
}
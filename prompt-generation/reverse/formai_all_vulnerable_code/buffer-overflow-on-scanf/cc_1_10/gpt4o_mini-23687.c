//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: grateful
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

// Function Declarations
void addContact();
void viewContacts();
void searchContact();
void deleteContact();
void displayMenu();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Please enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Please enter a valid number!\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting the phone book. Thank you for using it!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again!\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n**** Phone Book Menu ****\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("*************************\n");
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", phoneBook[contactCount].name);
    printf("Enter phone number: ");
    scanf("%s", phoneBook[contactCount].phone);
    contactCount++;
    printf("Contact added successfully! Thank you for contributing!\n");
}

void viewContacts() {
    printf("\n**** Contact List ****\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Contact %d: %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
    if (contactCount == 0)
        printf("No contacts to display.\n");
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Found Contact: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found. It's a vast world, keep searching!\n");
}

void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            contactCount--;
            printf("Contact deleted successfully! Each goodbye brings new hope.\n");
            return;
        }
    }
    printf("Contact not found. Hold on to your memories!\n");
}
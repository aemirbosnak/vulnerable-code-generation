//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: optimized
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
int totalContacts = 0;

void displayMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

void addContact() {
    if (totalContacts >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", phoneBook[totalContacts].name);
    printf("Enter Phone Number: ");
    scanf(" %[^\n]", phoneBook[totalContacts].phone);
    
    totalContacts++;
    printf("Contact added successfully!\n");
}

void viewContacts() {
    if (totalContacts == 0) {
        printf("No contacts in the phone book.\n");
        return;
    }

    printf("\nContacts List:\n");
    for (int i = 0; i < totalContacts; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < totalContacts; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            printf("Contact Found - Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < totalContacts; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < totalContacts - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            totalContacts--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

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
                printf("Exiting Phone Book.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
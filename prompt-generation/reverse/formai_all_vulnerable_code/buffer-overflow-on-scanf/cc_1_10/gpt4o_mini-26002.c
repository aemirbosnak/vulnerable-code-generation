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

void addContact() {
    if (contactCount < MAX_CONTACTS) {
        printf("Enter name: ");
        fgets(phoneBook[contactCount].name, NAME_LENGTH, stdin);
        phoneBook[contactCount].name[strcspn(phoneBook[contactCount].name, "\n")] = 0; // Remove newline
        printf("Enter phone number: ");
        fgets(phoneBook[contactCount].phone, PHONE_LENGTH, stdin);
        phoneBook[contactCount].phone[strcspn(phoneBook[contactCount].phone, "\n")] = 0; // Remove newline
        contactCount++;
        printf("Contact added successfully!\n\n");
    } else {
        printf("Phone book is full! Can't add more contacts.\n\n");
    }
}

void viewContacts() {
    if (contactCount == 0) {
        printf("No contacts found in the phone book.\n\n");
        return;
    }
    printf("Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
    printf("\n");
}

void deleteContact() {
    if (contactCount == 0) {
        printf("No contacts to delete. The phone book is empty.\n\n");
        return;
    }
    int index;
    printf("Enter the contact number to delete: ");
    scanf("%d", &index);
    getchar();  // Consume newline

    if (index < 1 || index > contactCount) {
        printf("Invalid contact number!\n\n");
        return;
    }

    for (int i = index - 1; i < contactCount - 1; i++) {
        phoneBook[i] = phoneBook[i + 1];
    }
    contactCount--;
    printf("Contact deleted successfully!\n\n");
}

void searchContact() {
    if (contactCount == 0) {
        printf("No contacts to search.\n\n");
        return;
    }
    char searchName[NAME_LENGTH];
    printf("Enter the name to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline
    
    int found = 0;
    printf("Search results:\n");
    for (int i = 0; i < contactCount; i++) {
        if (strstr(phoneBook[i].name, searchName) != NULL) {
            printf("Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("No contact found with the name '%s'.\n\n", searchName);
    } else {
        printf("\n");
    }
}

void displayMenu() {
    printf("=== Phone Book ===\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Search Contact\n");
    printf("5. Exit\n");
    printf("===================\n");
    printf("Choose an option: ");
}

int main() {
    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                searchContact();
                break;
            case 5:
                printf("Thank you for using the phone book! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n\n");
        }
    }
    return 0;
}
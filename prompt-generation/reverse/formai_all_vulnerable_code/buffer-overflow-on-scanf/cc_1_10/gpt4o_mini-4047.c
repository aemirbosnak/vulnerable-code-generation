//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter name: ");
    fgets(phoneBook[contactCount].name, sizeof(phoneBook[contactCount].name), stdin);
    phoneBook[contactCount].name[strcspn(phoneBook[contactCount].name, "\n")] = 0; // Remove newline

    printf("Enter phone number: ");
    fgets(phoneBook[contactCount].phone, sizeof(phoneBook[contactCount].phone), stdin);
    phoneBook[contactCount].phone[strcspn(phoneBook[contactCount].phone, "\n")] = 0; // Remove newline

    contactCount++;
    printf("Contact added: %s, %s\n", phoneBook[contactCount - 1].name, phoneBook[contactCount - 1].phone);
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts in phone book.\n");
        return;
    }

    printf("\nPhone Book Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, searchName) == 0) {
            printf("Found: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact() {
    char nameToDelete[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(nameToDelete, sizeof(nameToDelete), stdin);
    nameToDelete[strcspn(nameToDelete, "\n")] = 0; // Remove newline

    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, nameToDelete) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1]; // Shift contacts left
            }
            contactCount--;
            printf("Contact deleted.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void displayMenu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("-----------------------\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
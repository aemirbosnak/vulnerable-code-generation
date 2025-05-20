//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: single-threaded
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

void addContact(const char* name, const char* phone) {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    strcpy(phoneBook[contactCount].name, name);
    strcpy(phoneBook[contactCount].phone, phone);
    contactCount++;
    printf("Contact added: %s, %s\n", name, phone);
}

void searchContact(const char* name) {
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            printf("Found contact: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found: %s\n", name);
}

void deleteContact(const char* name) {
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            // Shift contacts down
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            contactCount--;
            printf("Contact deleted: %s\n", name);
            return;
        }
    }
    printf("Contact not found for deletion: %s\n", name);
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("Phone Book Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void showMenu() {
    printf("\n1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Delete Contact\n");
    printf("4. Display Contacts\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character left in the input buffer

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline character
                printf("Enter phone number: ");
                fgets(phone, PHONE_LENGTH, stdin);
                phone[strcspn(phone, "\n")] = 0;  // Remove newline character
                addContact(name, phone);
                break;
            case 2:
                printf("Enter name to search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline character
                searchContact(name);
                break;
            case 3:
                printf("Enter name to delete: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline character
                deleteContact(name);
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                printf("Exiting the phone book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: synchronous
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

// Function Prototypes
void addContact();
void displayContacts();
void searchContact();
void deleteContact();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n==== Phone Book Menu ====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("=========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear buffer to avoid issues with fgets

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
                printf("Exiting the Phone Book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}

void addContact() {
    if (contactCount < MAX_CONTACTS) {
        printf("Enter name: ");
        fgets(phoneBook[contactCount].name, MAX_NAME_LENGTH, stdin);
        phoneBook[contactCount].name[strcspn(phoneBook[contactCount].name, "\n")] = 0;

        printf("Enter phone number: ");
        fgets(phoneBook[contactCount].phone, MAX_PHONE_LENGTH, stdin);
        phoneBook[contactCount].phone[strcspn(phoneBook[contactCount].phone, "\n")] = 0;

        contactCount++;
        printf("Contact added successfully!\n");
    } else {
        printf("Phone book is full! Cannot add more contacts.\n");
    }
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts to display!\n");
    } else {
        printf("\n==== Contacts List ====\n");
        for (int i = 0; i < contactCount; i++) {
            printf("%d. Name: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
        }
        printf("=========================\n");
    }
}

void searchContact() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, searchName) == 0) {
            printf("Contact found! Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
}

void deleteContact() {
    char deleteName[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(deleteName, MAX_NAME_LENGTH, stdin);
    deleteName[strcspn(deleteName, "\n")] = 0;

    int i, found = 0;
    for (i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, deleteName) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int j = i; j < contactCount - 1; j++) {
            phoneBook[j] = phoneBook[j + 1];
        }
        contactCount--;
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
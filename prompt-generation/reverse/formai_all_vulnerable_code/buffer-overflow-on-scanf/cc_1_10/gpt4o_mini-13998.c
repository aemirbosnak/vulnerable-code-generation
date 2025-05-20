//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: complete
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

void addContact(Contact *phoneBook, int *count);
void searchContact(Contact *phoneBook, int count);
void displayContacts(Contact *phoneBook, int count);
void deleteContact(Contact *phoneBook, int *count);

int main() {
    Contact phoneBook[MAX_CONTACTS];
    int count = 0;
    int choice;

    do {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                addContact(phoneBook, &count);
                break;
            case 2:
                searchContact(phoneBook, count);
                break;
            case 3:
                displayContacts(phoneBook, count);
                break;
            case 4:
                deleteContact(phoneBook, &count);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addContact(Contact *phoneBook, int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Phone book is full. Can't add more contacts.\n");
        return;
    }

    printf("Enter name: ");
    fgets(phoneBook[*count].name, MAX_NAME_LENGTH, stdin);
    phoneBook[*count].name[strcspn(phoneBook[*count].name, "\n")] = 0; // Remove newline

    printf("Enter phone number: ");
    fgets(phoneBook[*count].phone, MAX_PHONE_LENGTH, stdin);
    phoneBook[*count].phone[strcspn(phoneBook[*count].phone, "\n")] = 0; // Remove newline

    (*count)++;
    printf("Contact added successfully!\n");
}

void searchContact(Contact *phoneBook, int count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Contact found: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void displayContacts(Contact *phoneBook, int count) {
    if (count == 0) {
        printf("No contacts in the phone book.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void deleteContact(Contact *phoneBook, int *count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of the contact to delete: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            // Shift contacts left to remove the deleted contact
            for (int j = i; j < *count - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found. Unable to delete.\n");
    }
}
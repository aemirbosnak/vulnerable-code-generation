//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: excited
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

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Phone book is full! Can't add more contacts.\n");
        return;
    }
    printf("Enter the name: ");
    fgets(contacts[*count].name, NAME_LENGTH, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = 0; // Remove newline
    printf("Enter the phone number: ");
    fgets(contacts[*count].phone, PHONE_LENGTH, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = 0; // Remove newline
    (*count)++;
    printf("Contact added successfully!\n");
}

void displayContacts(Contact contacts[], int count) {
    printf("\n----- Phone Book -----\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
    printf("----------------------\n");
}

void searchContact(Contact contacts[], int count) {
    char name[NAME_LENGTH];
    printf("Enter the name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(contacts[i].name, name) == 0) { // Case-insensitive comparison
            printf("Found contact: %s: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
}

void deleteContact(Contact contacts[], int *count) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcasecmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n----- Phone Book Menu -----\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character after scanf

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
                printf("Exiting Phone Book, see you next time!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}
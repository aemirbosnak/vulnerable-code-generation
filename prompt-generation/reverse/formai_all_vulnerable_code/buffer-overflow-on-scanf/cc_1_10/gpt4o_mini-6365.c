//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: light-weight
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

void displayContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts found.\n");
        return;
    }
    printf("Contacts:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Contact list is full! Cannot add more contacts.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", contacts[*count].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[*count].phone);
    (*count)++;
    printf("Contact added successfully!\n");
}

void searchContact(Contact contacts[], int count) {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact found: %s - %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void deleteContact(Contact contacts[], int *count) {
    char deleteName[NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", deleteName);
    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, deleteName) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int contactCount = 0;
    int choice;

    while (1) {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &contactCount);
                break;
            case 2:
                displayContacts(contacts, contactCount);
                break;
            case 3:
                searchContact(contacts, contactCount);
                break;
            case 4:
                deleteContact(contacts, &contactCount);
                break;
            case 5:
                printf("Exiting the phone book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}
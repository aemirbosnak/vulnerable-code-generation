//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define FILE_NAME "phonebook.txt"

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void addContact();
void displayContacts();
void searchContact();
void deleteContact();
void clearInputBuffer();
void loadContacts();
void saveContacts();

Contact contacts[MAX_CONTACTS];
int contactCount = 0;

int main() {
    loadContacts();
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
        clearInputBuffer();

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: saveContacts(); exit(0);
            default: printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full, cannot add more contacts.\n");
        return;
    }

    printf("Enter name: ");
    fgets(contacts[contactCount].name, NAME_LENGTH, stdin);
    contacts[contactCount].name[strcspn(contacts[contactCount].name, "\n")] = 0; // Remove newline character

    printf("Enter phone number: ");
    fgets(contacts[contactCount].phone, PHONE_LENGTH, stdin);
    contacts[contactCount].phone[strcspn(contacts[contactCount].phone, "\n")] = 0; // Remove newline character

    contactCount++;
    printf("Contact added successfully.\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Contact %d: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void searchContact() {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline character

    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(contacts[i].name, searchName) == 0) {
            printf("Found contact: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void deleteContact() {
    char deleteName[NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(deleteName, NAME_LENGTH, stdin);
    deleteName[strcspn(deleteName, "\n")] = 0; // Remove newline character

    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(contacts[i].name, deleteName) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contactCount--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void loadContacts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file) {
        while (fscanf(file, "%49[^,],%14s\n", contacts[contactCount].name, contacts[contactCount].phone) == 2) {
            contactCount++;
        }
        fclose(file);
    }
}

void saveContacts() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file) {
        for (int i = 0; i < contactCount; i++) {
            fprintf(file, "%s,%s\n", contacts[i].name, contacts[i].phone);
        }
        fclose(file);
    }
}
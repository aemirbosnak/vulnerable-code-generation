//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define NUMBER_LENGTH 20
#define HACKER_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    char number[NUMBER_LENGTH];
    char hackerType[HACKER_LENGTH]; // Affiliation of the hacker (if any)
} Contact;

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

void addContact();
void displayContacts();
void searchContact();
void deleteContact();
void editContact();
void clearScreen();

int main() {
    int choice;

    do {
        clearScreen();
        printf("++ Cyberpunk Phone Book ++\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Edit Contact\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: editContact(); break;
            case 6: printf("Shutting down...\n"); break;
            default: printf("Invalid choice! Try again.\n"); break;
        }

        printf("Press Enter to continue...");
        while (getchar() != '\n'); // clear the buffer
        getchar();

    } while (choice != 6);

    return 0;
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full! Unable to add more contacts.\n");
        return;
    }

    Contact newContact;
    printf("Enter name: ");
    scanf(" %[^\n]", newContact.name);
    printf("Enter number: ");
    scanf(" %[^\n]", newContact.number);
    printf("Enter hacker type (or none): ");
    scanf(" %[^\n]", newContact.hackerType);

    phoneBook[contactCount++] = newContact;
    printf("Contact added successfully!\n");
}

void displayContacts() {
    clearScreen();
    printf("++ Your Cyberpunk Contacts ++\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", phoneBook[i].name);
        printf("Number: %s\n", phoneBook[i].number);
        printf("Hacker Type: %s\n", phoneBook[i].hackerType);
        printf("------------------------\n");
    }
}

void searchContact() {
    clearScreen();
    char name[NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Contact found!\n");
            printf("Name: %s\n", phoneBook[i].name);
            printf("Number: %s\n", phoneBook[i].number);
            printf("Hacker Type: %s\n", phoneBook[i].hackerType);
            return;
        }
    }
    printf("Contact not found!\n");
}

void deleteContact() {
    clearScreen();
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            contactCount--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void editContact() {
    clearScreen();
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to edit: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Editing contact: %s\n", phoneBook[i].name);
            printf("Enter new number: ");
            scanf(" %[^\n]", phoneBook[i].number);
            printf("Enter new hacker type (or none): ");
            scanf(" %[^\n]", phoneBook[i].hackerType);
            printf("Contact updated successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the terminal screen
}
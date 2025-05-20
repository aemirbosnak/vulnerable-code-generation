//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define FILE_NAME "phonebook.dat"

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

void loadContacts() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file) {
        fread(phoneBook, sizeof(Contact), MAX_CONTACTS, file);
        fclose(file);
        while (phoneBook[contactCount].name[0] != '\0' && contactCount < MAX_CONTACTS) {
            contactCount++;
        }
    }
}

void saveContacts() {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file) {
        fwrite(phoneBook, sizeof(Contact), MAX_CONTACTS, file);
        fclose(file);
    }
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter name: ");
    getchar(); // to consume newline left by previous input
    fgets(phoneBook[contactCount].name, NAME_LENGTH, stdin);
    strtok(phoneBook[contactCount].name, "\n"); // Remove newline

    printf("Enter phone number: ");
    fgets(phoneBook[contactCount].phone, PHONE_LENGTH, stdin);
    strtok(phoneBook[contactCount].phone, "\n"); // Remove newline

    contactCount++;
    saveContacts();
    printf("Contact added successfully!\n");
}

void displayContacts() {
    printf("Contact List:\n");
    printf("%-30s %-15s\n", "Name", "Phone Number");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%-30s %-15s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    getchar(); // to consume the newline
    fgets(name, NAME_LENGTH, stdin);
    strtok(name, "\n"); // Remove newline

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Found contact: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void updateContact() {
    char name[NAME_LENGTH];
    printf("Enter name of the contact to update: ");
    getchar(); // to consume the newline
    fgets(name, NAME_LENGTH, stdin);
    strtok(name, "\n"); // Remove newline

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Updating contact: %s\n", phoneBook[i].name);
            printf("Enter new phone number: ");
            fgets(phoneBook[i].phone, PHONE_LENGTH, stdin);
            strtok(phoneBook[i].phone, "\n"); // Remove newline
            saveContacts();
            printf("Contact updated successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter name of the contact to delete: ");
    getchar(); // to consume the newline
    fgets(name, NAME_LENGTH, stdin);
    strtok(name, "\n"); // Remove newline

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            contactCount--;
            phoneBook[contactCount].name[0] = '\0'; // Mark the last entry as empty
            saveContacts();
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void showMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Update Contact\n");
    printf("5. Delete Contact\n");
    printf("6. Exit\n");
}

int main() {
    loadContacts();
    int choice;

    while (1) {
        showMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

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
                updateContact();
                break;
            case 5:
                deleteContact();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
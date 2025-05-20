//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: standalone
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

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

// Function prototypes
void addContact();
void displayContacts();
void searchContact();
void modifyContact();
void deleteContact();
void saveContacts();
void loadContacts();
void displayMenu();

int main() {
    loadContacts();
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline left in buffer

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: modifyContact(); break;
            case 5: deleteContact(); break;
            case 6: saveContacts(); break;
            case 7: printf("Exiting the program.\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

void displayMenu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Modify Contact\n");
    printf("5. Delete Contact\n");
    printf("6. Save Contacts to File\n");
    printf("7. Exit\n");
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter name: ");
    fgets(phoneBook[contactCount].name, NAME_LENGTH, stdin);
    phoneBook[contactCount].name[strcspn(phoneBook[contactCount].name, "\n")] = 0; // Remove newline

    printf("Enter phone number: ");
    fgets(phoneBook[contactCount].phone, PHONE_LENGTH, stdin);
    phoneBook[contactCount].phone[strcspn(phoneBook[contactCount].phone, "\n")] = 0; // Remove newline

    contactCount++;
    printf("Contact added!\n");
}

void displayContacts() {
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Contact %d: %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            printf("Found Contact: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

void modifyContact() {
    char searchName[NAME_LENGTH];
    printf("Enter name of contact to modify: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            printf("Modifying Contact: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            printf("Enter new name (or press enter to keep unchanged): ");
            char newName[NAME_LENGTH];
            fgets(newName, NAME_LENGTH, stdin);
            if (strcmp(newName, "\n") != 0) {
                newName[strcspn(newName, "\n")] = 0; // Remove newline
                strcpy(phoneBook[i].name, newName);
            }
            printf("Enter new phone number (or press enter to keep unchanged): ");
            char newPhone[PHONE_LENGTH];
            fgets(newPhone, PHONE_LENGTH, stdin);
            if (strcmp(newPhone, "\n") != 0) {
                newPhone[strcspn(newPhone, "\n")] = 0; // Remove newline
                strcpy(phoneBook[i].phone, newPhone);
            }
            printf("Contact modified!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void deleteContact() {
    char searchName[NAME_LENGTH];
    printf("Enter name of contact to delete: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            contactCount--;
            printf("Contact deleted!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void saveContacts() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error saving contacts!\n");
        return;
    }

    for (int i = 0; i < contactCount; i++) {
        fprintf(file, "%s,%s\n", phoneBook[i].name, phoneBook[i].phone);
    }

    fclose(file);
    printf("Contacts saved to %s\n", FILE_NAME);
}

void loadContacts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No saved contacts found, starting fresh!\n");
        return;
    }

    while (fscanf(file, "%49[^,],%14[^\n]\n", phoneBook[contactCount].name, phoneBook[contactCount].phone) == 2) {
        contactCount++;
    }

    fclose(file);
    printf("Contacts loaded from %s\n", FILE_NAME);
}
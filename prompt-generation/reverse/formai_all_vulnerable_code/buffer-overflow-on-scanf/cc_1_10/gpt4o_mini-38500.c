//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact phoneBook[MAX_ENTRIES];
int entryCount = 0;

void addContact();
void displayContacts();
void searchContact();
void deleteContact();
void saveContacts();
void loadContacts();

void menu() {
    int choice;
    do {
        printf("\n=== Phone Book Menu ===\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save Contacts\n");
        printf("6. Load Contacts\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: saveContacts(); break;
            case 6: loadContacts(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);
}

void addContact() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", phoneBook[entryCount].name);
    printf("Enter phone number: ");
    scanf("%s", phoneBook[entryCount].phone);
    entryCount++;
    printf("Contact added!\n");
}

void displayContacts() {
    if (entryCount == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("\n=== Contacts ===\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Found: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < entryCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            entryCount--;
            printf("Contact deleted!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void saveContacts() {
    FILE *file = fopen("phonebook.txt", "w");
    if (!file) {
        printf("Failed to save contacts.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
    fclose(file);
    printf("Contacts saved successfully!\n");
}

void loadContacts() {
    FILE *file = fopen("phonebook.txt", "r");
    if (!file) {
        printf("No saved contacts found.\n");
        return;
    }
    entryCount = 0;
    while (fscanf(file, "%s %s", phoneBook[entryCount].name, phoneBook[entryCount].phone) != EOF) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) break;
    }
    fclose(file);
    printf("Contacts loaded successfully!\n");
}

int main() {
    loadContacts(); // Load contacts on startup
    menu();
    saveContacts(); // Save contacts on exit
    return 0;
}
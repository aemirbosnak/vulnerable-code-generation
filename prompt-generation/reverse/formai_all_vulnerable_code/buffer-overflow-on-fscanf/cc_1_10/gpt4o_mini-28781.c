//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: standalone
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
void viewContacts();
void deleteContact();
void searchContact();
void saveContacts();
void loadContacts();

void printMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Search Contact\n");
    printf("5. Save Contacts\n");
    printf("6. Load Contacts\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    loadContacts();

    int choice;
    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                searchContact();
                break;
            case 5:
                saveContacts();
                break;
            case 6:
                loadContacts();
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

void addContact() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", phoneBook[entryCount].name);
    printf("Enter phone number: ");
    scanf("%s", phoneBook[entryCount].phone);
    entryCount++;
    printf("Contact added successfully!\n");
}

void viewContacts() {
    if (entryCount == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("\nContacts:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void deleteContact() {
    int index;
    viewContacts();
    printf("Enter the number of the contact to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > entryCount) {
        printf("Invalid index. Please try again.\n");
        return;
    }

    // Shift the contacts
    for (int i = index - 1; i < entryCount - 1; i++) {
        phoneBook[i] = phoneBook[i + 1];
    }
    entryCount--;
    printf("Contact deleted successfully!\n");
}

void searchContact() {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    int found = 0;

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            printf("Contact found - Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void saveContacts() {
    FILE *file = fopen("contacts.txt", "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
    fclose(file);
    printf("Contacts saved successfully!\n");
}

void loadContacts() {
    FILE *file = fopen("contacts.txt", "r");
    if (!file) {
        printf("No saved contacts to load.\n");
        return;
    }

    while (fscanf(file, "%s %s", phoneBook[entryCount].name, phoneBook[entryCount].phone) == 2) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) break;
    }
    fclose(file);
    printf("Contacts loaded successfully!\n");
}
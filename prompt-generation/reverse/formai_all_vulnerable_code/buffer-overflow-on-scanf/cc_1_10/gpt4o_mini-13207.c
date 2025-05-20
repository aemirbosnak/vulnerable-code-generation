//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: high level of detail
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

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }
    Contact newContact;
    printf("Enter name: ");
    scanf(" %[^\n]", newContact.name); // To read string with spaces
    printf("Enter phone number: ");
    scanf("%s", newContact.phone);
    phoneBook[contactCount++] = newContact;
    printf("Contact added successfully.\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("\nYour Contacts:\n");
    for (int i = 0; i < contactCount; ++i) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char searchName[NAME_LENGTH];
    printf("Enter the name of the contact to search: ");
    scanf(" %[^\n]", searchName);
    
    int found = 0;
    for (int i = 0; i < contactCount; ++i) {
        if (strcasecmp(phoneBook[i].name, searchName) == 0) {
            printf("Contact found - Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void deleteContact() {
    char deleteName[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]", deleteName);
    
    int found = 0;
    for (int i = 0; i < contactCount; ++i) {
        if (strcasecmp(phoneBook[i].name, deleteName) == 0) {
            for (int j = i; j < contactCount - 1; ++j) {
                phoneBook[j] = phoneBook[j + 1];
            }
            contactCount--;
            found = 1;
            printf("Contact deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Contact not found. Unable to delete.\n");
    }
}

void saveContacts() {
    FILE *file = fopen("phonebook.dat", "wb");
    if (!file) {
        printf("Error opening file for saving.\n");
        return;
    }
    fwrite(phoneBook, sizeof(Contact), contactCount, file);
    fclose(file);
    printf("Contacts saved successfully.\n");
}

void loadContacts() {
    FILE *file = fopen("phonebook.dat", "rb");
    if (!file) {
        printf("No saved contacts found.\n");
        return;
    }
    contactCount = fread(phoneBook, sizeof(Contact), MAX_CONTACTS, file);
    fclose(file);
    printf("Contacts loaded successfully. Total contacts: %d\n", contactCount);
}

void displayMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Save Contacts\n");
    printf("6. Load Contacts\n");
    printf("7. Exit\n");
}

int main() {
    int choice;
    loadContacts(); // Load contacts on startup

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
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
                saveContacts();
                break;
            case 6:
                loadContacts();
                break;
            case 7:
                printf("Exiting phone book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
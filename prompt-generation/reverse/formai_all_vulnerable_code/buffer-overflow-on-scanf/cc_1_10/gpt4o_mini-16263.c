//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: statistical
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

// Function Declarations
void addContact();
void deleteContact();
void searchContact();
void displayContacts();
void showStatistics();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Show Statistics\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addContact(); break;
            case 2: deleteContact(); break;
            case 3: searchContact(); break;
            case 4: displayContacts(); break;
            case 5: showStatistics(); break;
            case 6: exit(0);
            default: printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

// Function to add a contact
void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full, cannot add more contacts.\n");
        return;
    }
    
    Contact newContact;
    printf("Enter name: ");
    clearBuffer();
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0;  // Remove newline char
    printf("Enter phone number: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0;  // Remove newline char
    
    phoneBook[contactCount++] = newContact;
    printf("Contact added successfully.\n");
}

// Function to delete a contact
void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter name of the contact to delete: ");
    clearBuffer();
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;  // Remove newline char
    
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            // Shift contacts left to fill the gap
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            contactCount--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

// Function to search a contact
void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to search: ");
    clearBuffer();
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;  // Remove newline char
    
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Contact found: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

// Function to display all contacts
void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts in the phone book.\n");
        return;
    }
    
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

// Function to show statistics
void showStatistics() {
    printf("Total contacts: %d\n", contactCount);
    if (contactCount > 0) {
        printf("Average length of names: ");
        int totalLength = 0;
        for (int i = 0; i < contactCount; i++) {
            totalLength += strlen(phoneBook[i].name);
        }
        printf("%.2f characters\n", (float)totalLength / contactCount);
    } else {
        printf("No contacts to calculate statistics.\n");
    }
}

// Function to clear buffer
void clearBuffer() {
    while (getchar() != '\n');  // Clear input buffer
}
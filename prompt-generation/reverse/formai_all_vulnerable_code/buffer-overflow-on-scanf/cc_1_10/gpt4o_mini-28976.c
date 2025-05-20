//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: irregular
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
int contactCount = 0;

void addContact() {
    if (contactCount >= MAX_ENTRIES) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }
    printf("Enter contact name: ");
    scanf(" %[^\n]", phoneBook[contactCount].name);
    printf("Enter phone number: ");
    scanf("%s", phoneBook[contactCount].phone);
    contactCount++;
    printf("Contact added successfully!\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("\n--- Phone Book ---\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Contact %d: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);
    
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, searchName) == 0) {
            printf("Found: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
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
    printf("Enter name to delete: ");
    scanf(" %[^\n]", deleteName);
    
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, deleteName) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            contactCount--;
            found = 1;
            printf("Contact deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void menu() {
    int choice;
    while (1) {
        printf("\n=== Phone Book Menu ===\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                deleteContact();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
}

int main() {
    printf("Welcome to the Phone Book application!\n");
    menu();
    return 0;
}
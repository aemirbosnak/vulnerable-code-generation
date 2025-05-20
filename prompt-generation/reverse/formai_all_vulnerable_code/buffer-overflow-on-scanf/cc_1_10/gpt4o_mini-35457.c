//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
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
    fgets(newContact.name, MAX_NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // remove newline
    
    printf("Enter phone number: ");
    fgets(newContact.phone, MAX_PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // remove newline
    
    phoneBook[contactCount++] = newContact;
    printf("Contact added successfully!\n");
}

void deleteContact() {
    char nameToDelete[MAX_NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    fgets(nameToDelete, MAX_NAME_LENGTH, stdin);
    nameToDelete[strcspn(nameToDelete, "\n")] = 0; // remove newline
    
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, nameToDelete) == 0) {
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

void viewContacts() {
    if (contactCount == 0) {
        printf("No contacts available.\n");
        return;
    }
    
    printf("Contacts List:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%s - %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char nameToSearch[MAX_NAME_LENGTH];
    printf("Enter the name of the contact to search: ");
    fgets(nameToSearch, MAX_NAME_LENGTH, stdin);
    nameToSearch[strcspn(nameToSearch, "\n")] = 0; // remove newline
    
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, nameToSearch) == 0) {
            printf("Contact found: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    
    printf("Contact not found!\n");
}

void displayMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. View Contacts\n");
    printf("4. Search Contact\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // consume newline character left by scanf
        
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                deleteContact();
                break;
            case 3:
                viewContacts();
                break;
            case 4:
                searchContact();
                break;
            case 5:
                printf("Exiting Phone Book. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    
    return 0;
}
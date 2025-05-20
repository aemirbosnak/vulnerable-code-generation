//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: creative
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

Contact* phoneBook[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }
    
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    
    printf("Enter name: ");
    scanf(" %[^\n]", newContact->name);
    printf("Enter phone number: ");
    scanf(" %[^\n]", newContact->phone);
    
    phoneBook[contactCount++] = newContact;
    printf("Contact added successfully!\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts found.\n");
        return;
    }
    
    printf("Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, phoneBook[i]->name, phoneBook[i]->phone);
    }
}

void searchContact() {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);
    
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i]->name, searchName) == 0) {
            printf("Contact found! Name: %s, Phone: %s\n", phoneBook[i]->name, phoneBook[i]->phone);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found.\n");
    }
}

void deleteContact() {
    char delName[NAME_LENGTH];
    printf("Enter name of the contact to delete: ");
    scanf(" %[^\n]", delName);
    
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i]->name, delName) == 0) {
            free(phoneBook[i]);
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            contactCount--;
            printf("Contact deleted successfully!\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found to delete.\n");
    }
}

void clearPhoneBook() {
    for (int i = 0; i < contactCount; i++) {
        free(phoneBook[i]);
    }
    contactCount = 0;
    printf("All contacts have been cleared!\n");
}

void showMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Clear Phone Book\n");
    printf("6. Exit\n");
}

int main() {
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
                deleteContact();
                break;
            case 5: 
                clearPhoneBook();
                break;
            case 6: 
                clearPhoneBook();
                printf("Exiting the phone book. Goodbye!\n");
                return 0;
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    }
}
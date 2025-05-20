//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

void addContact();
void displayContacts();
void searchContact();
void deleteContact();
void displayMenu();

int main() {
    int choice;

    while (1) {
        displayMenu();
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
                printf("Exiting the Phone Book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }

    Contact newContact;
    printf("Enter name: ");
    getchar(); // clear newline left from previous input
    fgets(newContact.name, NAME_LEN, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // remove newline

    printf("Enter phone number: ");
    fgets(newContact.phone, PHONE_LEN, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // remove newline

    phoneBook[contactCount++] = newContact;
    printf("Contact added successfully!\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d: %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char searchName[NAME_LEN];
    printf("Enter the name to search: ");
    getchar(); // clear newline
    fgets(searchName, NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, searchName) == 0) {
            printf("Found: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void deleteContact() {
    int index;
    displayContacts();
    
    printf("Enter the number of the contact to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > contactCount) {
        printf("Invalid index. No contact deleted.\n");
        return;
    }
    
    for (int i = index - 1; i < contactCount - 1; i++) {
        phoneBook[i] = phoneBook[i + 1];
    }
    contactCount--;
    printf("Contact deleted successfully!\n");
}
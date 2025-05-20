//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: peaceful
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

void clearScreen(){
    printf("\033[H\033[J");
}

void displayMenu() {
    clearScreen();
    printf("=== Simple Phone Book ===\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Display All Contacts\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("=========================\n");
    printf("Choose an option: ");
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    
    Contact newContact;
    
    printf("Enter Name: ");
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline

    printf("Enter Phone Number: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // Remove newline

    phoneBook[contactCount++] = newContact;
    printf("Contact added successfully!\n");
}

void searchContact() {
    char name[NAME_LENGTH];
    
    printf("Enter Name to Search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            printf("Contact Found: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact Not Found!\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts available.\n");
        return;
    }
    
    printf("=== List of Contacts ===\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void deleteContact() {
    char name[NAME_LENGTH];
    
    printf("Enter Name to Delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            contactCount--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact Not Found!\n");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline after the number input

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                displayContacts();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting the phone book. Have a peaceful day!\n");
                exit(0);
            default:
                printf("Invalid Option! Please try again.\n");
        }

        printf("Press Enter to continue...");
        getchar(); // Wait for user input
    }
    
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} PhoneBook;

void initializePhoneBook(PhoneBook *phoneBook) {
    phoneBook->count = 0;
}

void addContact(PhoneBook *phoneBook) {
    if(phoneBook->count < MAX_CONTACTS) {
        Contact newContact;
        printf("Enter name: ");
        fgets(newContact.name, MAX_NAME_LENGTH, stdin);
        newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline character
        
        printf("Enter phone number: ");
        fgets(newContact.phone, MAX_PHONE_LENGTH, stdin);
        newContact.phone[strcspn(newContact.phone, "\n")] = 0; // Remove newline character
        
        phoneBook->contacts[phoneBook->count++] = newContact;
        printf("Contact added!\n");
    } else {
        printf("Phone book is full!\n");
    }
}

void displayContacts(PhoneBook *phoneBook) {
    if(phoneBook->count == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("\nContacts:\n");
    for(int i = 0; i < phoneBook->count; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook->contacts[i].name, phoneBook->contacts[i].phone);
    }
}

void searchContact(PhoneBook *phoneBook) {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline character

    int found = 0;
    for(int i = 0; i < phoneBook->count; i++) {
        if(strcasecmp(phoneBook->contacts[i].name, searchName) == 0) {
            printf("Found: %s - %s\n", phoneBook->contacts[i].name, phoneBook->contacts[i].phone);
            found = 1;
        }
    }
    if(!found) {
        printf("No contact found with name '%s'.\n", searchName);
    }
}

void deleteContact(PhoneBook *phoneBook) {
    char nameToDelete[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(nameToDelete, MAX_NAME_LENGTH, stdin);
    nameToDelete[strcspn(nameToDelete, "\n")] = 0; // Remove newline character

    for(int i = 0; i < phoneBook->count; i++) {
        if(strcasecmp(phoneBook->contacts[i].name, nameToDelete) == 0) {
            for(int j = i; j < phoneBook->count - 1; j++) {
                phoneBook->contacts[j] = phoneBook->contacts[j + 1];
            }
            phoneBook->count--;
            printf("Contact '%s' deleted!\n", nameToDelete);
            return;
        }
    }
    printf("No contact found with name '%s'.\n", nameToDelete);
}

void displayMenu() {
    printf("\n=== Phone Book Menu ===\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("========================\n");
}

int main() {
    PhoneBook phoneBook;
    initializePhoneBook(&phoneBook);

    int choice;
    do {
        displayMenu();
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch(choice) {
            case 1:
                addContact(&phoneBook);
                break;
            case 2:
                displayContacts(&phoneBook);
                break;
            case 3:
                searchContact(&phoneBook);
                break;
            case 4:
                deleteContact(&phoneBook);
                break;
            case 5:
                printf("Exiting the Phone Book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}
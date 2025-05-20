//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: systematic
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

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} PhoneBook;

void initializePhoneBook(PhoneBook *pb) {
    pb->count = 0;
}

void addContact(PhoneBook *pb) {
    if (pb->count >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }
    
    Contact newContact;
    printf("Enter Name: ");
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline
    printf("Enter Phone: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // Remove newline
    
    pb->contacts[pb->count] = newContact;
    pb->count++;
    printf("Contact added successfully!\n");
}

void displayContacts(PhoneBook *pb) {
    if (pb->count == 0) {
        printf("No contacts in phone book.\n");
        return;
    }
    
    printf("\nPhone Book Contacts:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("Contact %d: Name: %s, Phone: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline
    
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Contact Found: Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

void deleteContact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline
    
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            for (int j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->count--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void menu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    PhoneBook phoneBook;
    initializePhoneBook(&phoneBook);

    int choice;
    do {
        menu();
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
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
                printf("Exiting the phone book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
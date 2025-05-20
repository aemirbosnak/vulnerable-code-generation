//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
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
        printf("Neon Lines Full! Can't add more contacts.\n");
        return;
    }
    
    Contact newContact;
    printf("Enter name (cyber alias): ");
    scanf(" %[^\n]", newContact.name);
    printf("Enter phone number: ");
    scanf(" %[^\n]", newContact.phone);
    printf("Enter email (cybermail): ");
    scanf(" %[^\n]", newContact.email);
    
    pb->contacts[pb->count] = newContact;
    pb->count++;

    printf("Contact added: %s\n", newContact.name);
}

void listContacts(PhoneBook *pb) {
    if (pb->count == 0) {
        printf("No contacts found in the digital void.\n");
        return;
    }
    
    printf("=== Contact List ===\n");
    for (int i = 0; i < pb->count; i++) {
        printf("Contact %d:\n", i + 1);
        printf("  Alias: %s\n", pb->contacts[i].name);
        printf("  Phone: %s\n", pb->contacts[i].phone);
        printf("  Email: %s\n", pb->contacts[i].email);
    }
}

void searchContact(PhoneBook *pb) {
    char query[NAME_LENGTH];
    printf("Enter the alias to search for: ");
    scanf(" %[^\n]", query);
    
    int found = 0;
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, query) == 0) {
            printf("Found contact:\n");
            printf("  Alias: %s\n", pb->contacts[i].name);
            printf("  Phone: %s\n", pb->contacts[i].phone);
            printf("  Email: %s\n", pb->contacts[i].email);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No contact found matching: %s\n", query);
    }
}

void deleteContact(PhoneBook *pb) {
    char query[NAME_LENGTH];
    printf("Enter the alias to delete: ");
    scanf(" %[^\n]", query);
    
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, query) == 0) {
            for (int j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->count--;
            printf("Contact %s deleted from the database.\n", query);
            return;
        }
    }
    
    printf("No contact found matching: %s\n", query);
}

void displayMenu() {
    printf("\n=== Cyberpunk Phone Book ===\n");
    printf("1. Add Contact\n");
    printf("2. List Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("============================\n");
}

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);
    
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an action: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addContact(&pb); break;
            case 2: listContacts(&pb); break;
            case 3: searchContact(&pb); break;
            case 4: deleteContact(&pb); break;
            case 5: 
                printf("Exiting the cyber void...\n"); 
                exit(0);
            default:
                printf("Invalid choice! Hack the interface again.\n");
        }
    }
    
    return 0;
}
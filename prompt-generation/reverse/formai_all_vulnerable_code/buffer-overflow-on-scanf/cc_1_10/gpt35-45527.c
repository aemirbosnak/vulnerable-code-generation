//FormAI DATASET v1.0 Category: Phone Book ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100 // Maximum number of contacts in the phone book
#define MAX_NAME_LENGTH 50 // Maximum length of contact name
#define MAX_PHONE_LENGTH 20 // Maximum length of contact phone number

struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

int numContacts = 0; // Number of contacts in the phone book
struct Contact contacts[MAX_CONTACTS]; // Array of contacts in the phone book

void addContact() {
    if (numContacts == MAX_CONTACTS) {
        printf("The phone book is full.\n");
        return;
    }
    
    printf("Enter the contact name: ");
    scanf("%s", contacts[numContacts].name);
    
    printf("Enter the contact phone number: ");
    scanf("%s", contacts[numContacts].phone);
    
    printf("Contact added.\n");
    numContacts++;
}

void searchContact() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Phone number for %s is %s.\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found.\n");
    }
}

void displayContacts() {
    printf("Contacts in phone book:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].phone);
    }
}

int main() {
    while (1) {
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Display contacts\n");
        printf("4. Exit\n");
        
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
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
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}
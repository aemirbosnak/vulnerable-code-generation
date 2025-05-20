//FormAI DATASET v1.0 Category: Phone Book ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 20
#define PHONE_LENGTH 15

// structure to store contact information
typedef struct contact_info {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} ContactInfo;

// function to add new contact to the phone book
void addContact(ContactInfo *phoneBook, int *count) {
    printf("Enter name: ");
    char name[NAME_LENGTH];
    scanf("%s", name);
    printf("Enter phone number: ");
    char phone[PHONE_LENGTH];
    scanf("%s", phone);
    strcpy(phoneBook[*count].name, name); // copy name to phoneBook
    strcpy(phoneBook[*count].phone, phone); // copy phone number to phoneBook
    (*count)++; // increment count
}

// function to search contact in the phone book
void searchContact(ContactInfo *phoneBook, int count) {
    printf("Enter name to search: ");
    char name[NAME_LENGTH];
    scanf("%s", name);
    int found = 0; // flag to indicate if contact is found or not
    for (int i = 0; i < count; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) { // compare name with phone book entry
            printf("Name: %s\nPhone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1; // set flag to true
            break;
        }
    }
    if (!found) { // if flag is false, contact is not found
        printf("Contact not found!\n");
    }
}

// function to display all contacts in the phone book
void displayContacts(ContactInfo *phoneBook, int count) {
    printf("Contacts in phone book:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\nPhone: %s\n\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

// main function
int main() {
    ContactInfo phoneBook[100]; // array to store contact information
    int choice = 0; // variable to store user's choice
    int count = 0; // variable to store number of contacts in phone book

    do {
        printf("PHONE BOOK\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // add new contact
                addContact(phoneBook, &count);
                break;
            case 2: // search contact
                searchContact(phoneBook, count);
                break;
            case 3: // display all contacts
                displayContacts(phoneBook, count);
                break;
            case 4: // exit
                printf("Exiting phone book...\n");
                break;
            default: // invalid choice
                printf("Invalid choice! Please try again.\n");
                break;
        }
        
    } while (choice != 4);

    return 0;
}
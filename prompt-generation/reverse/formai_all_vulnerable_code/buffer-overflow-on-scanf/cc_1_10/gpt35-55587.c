//FormAI DATASET v1.0 Category: Phone Book ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for contacts
struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

// global variable for storing contacts
struct Contact contacts[100];
int contactCount = 0;

// function for adding contact
void addContact() {
    char name[50], phone[15], email[50];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", phone);
    printf("Enter email address: ");
    scanf("%s", email);
    
    // create Contact object and add to contacts array
    struct Contact contact;
    strcpy(contact.name, name);
    strcpy(contact.phone, phone);
    strcpy(contact.email, email);
    contacts[contactCount] = contact;
    contactCount++;
    
    printf("Contact added successfully.\n");
}

// function for searching contact
void searchContact() {
    char name[50];
    printf("Enter name: ");
    scanf("%s", name);
    
    // loop through contacts and find contact by name
    int i, found = 0;
    for (i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\nEmail: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found.\n");
    }
}

// function for displaying contacts
void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts found.\n");
    } else {
        int i;
        for (i = 0; i < contactCount; i++) {
            printf("Name: %s\nPhone: %s\nEmail: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            printf("--------------------------------------\n");
        }
    }
}

// main function
int main() {
    printf("**********C Phone Book**********\n");
    while (1) {
        printf("Select an option:\n1. Add contact\n2. Search contact\n3. Display contacts\n4. Exit\n");
        int option;
        scanf("%d", &option);
        switch(option) {
            case 1: addContact(); break;
            case 2: searchContact(); break;
            case 3: displayContacts(); break;
            case 4: exit(0);
            default: printf("Invalid option selected.\n");
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Phone Book ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100

// Struct for each contact
typedef struct {
    char name[50];
    char phone[20];
} Contact;

// Function to print all contacts
void printAllContacts(Contact contacts[], int numContacts) {
    printf("PRINTING ALL CONTACTS:\n");
    for (int i=0; i<numContacts; i++) {
        printf("Name: %s, Phone Number: %s\n", contacts[i].name, contacts[i].phone);
    }
    printf("\n");
}

// Function to add a new contact
void addContact(Contact contacts[], int *numContacts) {
    Contact newContact;
    printf("ADDING A NEW CONTACT\n");
    printf("Please enter a name: ");
    scanf("%s", newContact.name);
    printf("Please enter a phone number: ");
    scanf("%s", newContact.phone);
    contacts[*numContacts] = newContact;
    *numContacts += 1;
    printf("CONTACT ADDED\n");
}

// Function to search for a contact by name
void searchByName(Contact contacts[], int numContacts) {
    char searchName[50];
    printf("SEARCHING FOR A CONTACT BY NAME\n");
    printf("Please enter a name to search for: ");
    scanf("%s", searchName);
    for (int i=0; i<numContacts; i++) {
        if (strcmp(searchName, contacts[i].name) == 0) {
            printf("Name: %s, Phone Number: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("CONTACT NOT FOUND\n");
}

int main() {
    Contact contacts[MAX_ENTRIES];
    int numContacts = 0;
    char userInput;

    printf("WELCOME TO THE C PHONE BOOK!\n");

    while (1) {
        printf("Please select an option: (a)dd new contact, (s)earch by name, (p)rint all contact, (q)uit:  ");
        scanf("%s", &userInput);
        printf("\n");
        
        switch (userInput) {
            case 'a':
                addContact(contacts, &numContacts);
                break;
            case 's':
                searchByName(contacts, numContacts);
                break;
            case 'p':
                printAllContacts(contacts, numContacts);
                break;
            case 'q':
                printf("THANK YOU FOR USING THE C PHONE BOOK!\n");
                exit(0);
            default:
                printf("INVALID INPUT, PLEASE TRY AGAIN\n");
                break;
        }        
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_CONTACTS 100 // maximum number of contacts the phone book can hold

// structure representing individual contact
struct Contact {
    char name[30];
    char phone[15];
};

// initialize phone book with no contacts
struct Contact phoneBook[MAX_CONTACTS] = {{"",""}};

// keep track of total number of contacts in the phone book
int totalContacts = 0;

// function to add new contact to phone book
void addNewContact() {
    if(totalContacts == MAX_CONTACTS) { // phone book is full
        printf("Phone book is full!\n");
        return;
    }

    struct Contact newContact;

    printf("Enter name: ");
    scanf("%s", newContact.name);

    printf("Enter phone number: ");
    scanf("%s", newContact.phone);

    phoneBook[totalContacts++] = newContact;

    printf("%s has been added to the phone book.\n", newContact.name);
}

// function to search for contact in phone book
void searchContact() {
    char name[30];
    printf("Enter name to search: ");
    scanf("%s", name);

    int foundIndex = -1;
    for(int i = 0; i < totalContacts; i++) {
        if(strcmp(phoneBook[i].name, name) == 0) {
            foundIndex = i;
            break;
        }
    }

    if(foundIndex == -1) {
        printf("Contact not found!\n");
        return;
    }

    printf("Name: %s\nPhone: %s\n", phoneBook[foundIndex].name, phoneBook[foundIndex].phone);
}

// function to display all the contacts in the phone book
void displayContacts() {
    if(totalContacts == 0) {
        printf("Phone book is empty!\n");
        return;
    }

    printf("Contacts: \n");
    for(int i = 0; i < totalContacts; i++) {
        printf("%d. %s\t%s\n", i+1, phoneBook[i].name, phoneBook[i].phone);
    }
}

int main() {
    int choice;

    while(1) {
        printf("\nPhone Book Menu:\n1. Add a new contact\n2. Search for a contact\n3. Display all contacts\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addNewContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                displayContacts();
                break;
            case 4:
                printf("Exiting phone book...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
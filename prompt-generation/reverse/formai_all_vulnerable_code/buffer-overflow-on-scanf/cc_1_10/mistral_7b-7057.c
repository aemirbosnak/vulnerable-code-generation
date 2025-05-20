//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 100

typedef struct {
    char name[50];
    char phone[20];
} Contact;

Contact phoneBook[MAX_ENTRIES];
int numEntries = 0;

void addContact(Contact contact) {
    if (numEntries < MAX_ENTRIES) {
        phoneBook[numEntries] = contact;
        numEntries++;
    } else {
        printf("Phone book is full.\n");
    }
}

void searchContact(char name[]) {
    for (int i = 0; i < numEntries; i++) {
        if (strcpy(phoneBook[i].name, name) == name) {
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone: %s\n", phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void printPhoneBook() {
    printf("\nPhone Book\n");
    for (int i = 0; i < numEntries; i++) {
        printf("Entry %d:\n", i+1);
        printf("Name: %s\n", phoneBook[i].name);
        printf("Phone: %s\n", phoneBook[i].phone);
        printf("\n");
    }
}

int main() {
    char command[20];
    char name[50];
    Contact newContact;

    while (1) {
        printf("\nPhone Book Menu:\n1. Add Contact\n2. Search Contact\n3. Display Phone Book\n4. Exit\n");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("Enter name: ");
                scanf("%s", newContact.name);
                printf("Enter phone number: ");
                scanf("%s", newContact.phone);
                addContact(newContact);
                break;
            case '2':
                printf("Enter name to search: ");
                scanf("%s", name);
                searchContact(name);
                break;
            case '3':
                printPhoneBook();
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}
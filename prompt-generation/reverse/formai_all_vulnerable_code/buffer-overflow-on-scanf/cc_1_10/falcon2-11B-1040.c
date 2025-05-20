//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_NUMBER_LENGTH];
} Contact;

Contact contacts[10]; // Maximum 10 contacts
int contactCount = 0; // Counts the number of contacts

void addContact(char* name, char* phone) {
    if (contactCount >= 10) {
        printf("Phone Book is full! Cannot add more contacts.\n");
        return;
    }

    strcpy(contacts[contactCount].name, name);
    strcpy(contacts[contactCount].phone, phone);
    contactCount++;
}

void removeContact(char* name) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            strcpy(contacts[i].name, "");
            strcpy(contacts[i].phone, "");
            contactCount--;
            break;
        }
    }
}

void listContacts() {
    printf("Name\t\tPhone Number\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%s\t\t%s\n", contacts[i].name, contacts[i].phone);
    }
}

int main() {
    char name[MAX_NAME_LENGTH], phone[MAX_PHONE_NUMBER_LENGTH];

    while (1) {
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. List Contacts\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                addContact(name, phone);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                removeContact(name);
                break;
            case 3:
                listContacts();
                break;
            case 4:
                printf("Thank you for using the Phone Book.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
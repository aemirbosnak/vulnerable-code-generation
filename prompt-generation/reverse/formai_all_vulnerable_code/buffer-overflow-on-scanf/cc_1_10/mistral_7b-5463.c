//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_SIZE 50
#define PHONE_SIZE 15

typedef struct {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phoneBook[numContacts].name);

    printf("Enter phone number: ");
    scanf("%s", phoneBook[numContacts].phone);

    numContacts++;
}

void searchContact() {
    char name[NAME_SIZE];
    int i;

    printf("Enter name to search: ");
    scanf("%s", name);

    for (i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void printContacts() {
    int i;

    printf("Contacts:\n");

    for (i = 0; i < numContacts; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nPhone Book Menu:\n1. Add Contact\n2. Search Contact\n3. Display Contacts\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                printContacts();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
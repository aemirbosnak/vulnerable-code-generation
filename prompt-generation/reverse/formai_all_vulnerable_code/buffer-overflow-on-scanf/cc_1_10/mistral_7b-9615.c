//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_SIZE 50
#define PHONE_SIZE 20

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

    printf("Enter contact name: ");
    scanf("%s", phoneBook[numContacts].name);

    printf("Enter contact phone number: ");
    scanf("%s", phoneBook[numContacts].phone);

    numContacts++;
}

void searchContact() {
    char searchName[NAME_SIZE];
    int i;

    printf("Enter name to search for: ");
    scanf("%s", searchName);

    for (i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone: %s\n", phoneBook[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void printPhoneBook() {
    int i;

    printf("\nPhone Book:\n");

    for (i = 0; i < numContacts; i++) {
        printf("Name: %s\n", phoneBook[i].name);
        printf("Phone: %s\n", phoneBook[i].phone);
        printf("---------------------\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Print Phone Book\n");
        printf("4. Exit\n");
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
                printPhoneBook();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
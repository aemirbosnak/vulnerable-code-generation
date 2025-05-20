//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact phoneBook[MAX_ENTRIES];
int numContacts = 0;

void addContact() {
    if (numContacts >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    fgets(phoneBook[numContacts].name, NAME_LENGTH, stdin);
    phoneBook[numContacts].name[strlen(phoneBook[numContacts].name) - 1] = '\0';

    printf("Enter phone number: ");
    fgets(phoneBook[numContacts].phone, PHONE_LENGTH, stdin);
    phoneBook[numContacts].phone[strlen(phoneBook[numContacts].phone) - 1] = '\0';

    numContacts++;
}

void searchContact() {
    char name[NAME_LENGTH];
    int i;

    printf("Enter name to search for: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strlen(name) - 1] = '\0';

    for (i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Found contact:\nName: %s\nPhone: %s\n", phoneBook[i].name, phoneBook[i].phone);
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
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n2. Search Contact\n3. Print Contacts\n4. Exit\n");
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
                printContacts();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
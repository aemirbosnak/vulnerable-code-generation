//FormAI DATASET v1.0 Category: Phone Book ; Style: Claude Shannon
/* C Phone Book Example */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

struct Contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

struct Contact PhoneBook[MAX_CONTACTS];
int numContacts = 0;

void AddContact()
{
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    printf("Name: ");
    scanf("%s", name);
    printf("Number: ");
    scanf("%s", number);

    struct Contact newContact;
    strcpy(newContact.name, name);
    strcpy(newContact.number, number);

    PhoneBook[numContacts] = newContact;
    numContacts++;

    printf("Contact added successfully.\n");
}

void FindContact()
{
    char name[MAX_NAME_LENGTH];

    printf("Name: ");
    scanf("%s", name);

    int contactFound = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(PhoneBook[i].name, name) == 0) {
            printf("%s: %s\n", PhoneBook[i].name, PhoneBook[i].number);
            contactFound = 1;
            break;
        }
    }

    if (!contactFound) {
        printf("Contact not found.\n");
    }
}

void ListContacts()
{
    for (int i = 0; i < numContacts; i++) {
        printf("%s: %s\n", PhoneBook[i].name, PhoneBook[i].number);
    }
}

int main()
{
    while (1) {
        printf("\n\n---------------------------\n");
        printf("    C Phone Book Example\n");
        printf("---------------------------\n");
        printf("1. Add contact\n");
        printf("2. Find contact\n");
        printf("3. List contacts\n");
        printf("4. Quit\n");
        printf("\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            AddContact();
            break;
        case 2:
            FindContact();
            break;
        case 3:
            ListContacts();
            break;
        case 4:
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}
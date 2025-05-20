//FormAI DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct Contact {
    char name[20];
    char phone[12];
};

struct Contact phoneBook[MAX_SIZE];
int contactCount = 0;

void addNewContact();
void listAllContacts();
void searchContacts();

int main()
{
    int choice;

    while (1)
    {
        printf("C Phone Book:\n");
        printf("1. Add new contact\n");
        printf("2. List all contacts\n");
        printf("3. Search contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addNewContact();
                break;
            case 2:
                listAllContacts();
                break;
            case 3:
                searchContacts();
                break;
            case 4:
                printf("Thank you for using C Phone Book.\n");
                return 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

void addNewContact()
{
    if (contactCount == MAX_SIZE)
    {
        printf("Sorry, the phone book is full.\n");
        return;
    }

    struct Contact newContact;

    printf("Enter name: ");
    scanf("%s", newContact.name);

    printf("Enter phone number: ");
    scanf("%s", newContact.phone);

    phoneBook[contactCount++] = newContact;

    printf("New contact added successfully!\n");
}

void listAllContacts()
{
    if (contactCount == 0)
    {
        printf("The phone book is empty.\n");
        return;
    }

    printf("List of contacts:\n");

    for (int i = 0; i < contactCount; i++)
    {
        printf("%d. Name: %s, Phone: %s\n", i+1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContacts()
{
    if (contactCount == 0)
    {
        printf("The phone book is empty.\n");
        return;
    }

    char searchName[20];
    int found = 0;

    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < contactCount; i++)
    {
        if (strcmp(phoneBook[i].name, searchName) == 0)
        {
            printf("Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No contact with name %s found.\n", searchName);
    }
}
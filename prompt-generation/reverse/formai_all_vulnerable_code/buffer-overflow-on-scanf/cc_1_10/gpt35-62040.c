//FormAI DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBook
{
    char name[30];
    char telNo[15];
} people[100];

int count = 0;

void addContact()
{
    if (count >= 100)
    {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", people[count].name);

    printf("Enter telephone number: ");
    scanf("%s", people[count].telNo);

    printf("Contact added!\n");

    count++;
}

void searchContact()
{
    char search[30];
    int found = 0;

    printf("Enter name to search: ");
    scanf("%s", search);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(search, people[i].name) == 0)
        {
            printf("Name: %s\n", people[i].name);
            printf("Telephone Number: %s\n", people[i].telNo);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Contact not found!\n");
    }
}

void listContacts()
{
    if (count == 0)
    {
        printf("Phone book is empty!\n");
        return;
    }

    printf("Name\tTelephone Number\n");

    for (int i = 0; i < count; i++)
    {
        printf("%s\t%s\n", people[i].name, people[i].telNo);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. List Contacts\n");
        printf("4. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addContact();
            break;

        case 2:
            searchContact();
            break;

        case 3:
            listContacts();
            break;

        case 4:
            printf("Exiting application...");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
//FormAI DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PhoneBook
{
    char name[50];
    int phoneNumber;
    struct PhoneBook *next;
} PhoneBook;

PhoneBook *head = NULL;

void addContact(char name[], int phoneNumber)
{
    PhoneBook *newContact = (PhoneBook*) malloc(sizeof(PhoneBook));
    strcpy(newContact->name, name);
    newContact->phoneNumber = phoneNumber;
    newContact->next = head;
    head = newContact;
    printf("%s added to the phone book.\n", name);
}

void viewContacts()
{
    PhoneBook *currentContact = head;

    if (currentContact == NULL)
    {
        printf("Your phone book is empty.\n");
    }
    else
    {
        printf("Your phone book:\n");

        while (currentContact != NULL)
        {
            printf("Name: %s | Phone Number: %d\n", currentContact->name, currentContact->phoneNumber);
            currentContact = currentContact->next;
        }
    }
}

void searchContact(char name[])
{
    PhoneBook *currentContact = head;

    while (currentContact != NULL)
    {
        if (strcmp(currentContact->name, name) == 0)
        {
            printf("Name: %s | Phone Number: %d\n", currentContact->name, currentContact->phoneNumber);
            return;
        }

        currentContact = currentContact->next;
    }

    printf("%s not found in phone book.\n", name);
}

void deleteContact(char name[])
{
    PhoneBook *currentContact = head;
    PhoneBook *prevContact = NULL;

    while (currentContact != NULL)
    {
        if (strcmp(currentContact->name, name) == 0)
        {
            if (prevContact == NULL)
            {
                head = currentContact->next;
            }
            else
            {
                prevContact->next = currentContact->next;
            }

            free(currentContact);
            printf("%s deleted from phone book.\n", name);
            return;
        }

        prevContact = currentContact;
        currentContact = currentContact->next;
    }

    printf("%s not found in phone book.\n", name);
}

int main()
{
    char option;
    char name[50];
    int phoneNumber;

    printf("***Phone Book Application***\n");
    printf("Press 'a' to add a contact.\n");
    printf("Press 'v' to view contacts.\n");
    printf("Press 's' to search for a contact.\n");
    printf("Press 'd' to delete a contact.\n");
    printf("Press 'q' to quit.\n");

    while (1)
    {
        printf("\nEnter an option: ");
        scanf(" %c", &option);

        switch (option)
        {
            case 'a':
                printf("Enter name: ");
                scanf(" %s", name);
                printf("Enter phone number: ");
                scanf("%d", &phoneNumber);
                addContact(name, phoneNumber);
                break;

            case 'v':
                viewContacts();
                break;

            case 's':
                printf("Enter a name to search: ");
                scanf(" %s", name);
                searchContact(name);
                break;

            case 'd':
                printf("Enter a name to delete: ");
                scanf(" %s", name);
                deleteContact(name);
                break;

            case 'q':
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid option!\n");
                break;
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBook
{
    char name[50];
    char number[20];
    struct PhoneBook* next;
};

struct PhoneBook* head = NULL;

void addContact(char name[], char number[]);
void printContacts();
void deleteContact(char name[]);
void updateContact(char name[]);
void searchContact(char name[]);

int main()
{
    char input[50];
    char name[50];
    char number[20];

    while (1)
    {   
        printf("\n");
        printf("Welcome to the Phone Book! \n");
        printf("Enter '1' to add a new contact \n");
        printf("Enter '2' to view all contacts \n");
        printf("Enter '3' to delete a contact \n");
        printf("Enter '4' to update a contact \n");
        printf("Enter '5' to search for a contact \n");
        printf("Enter '6' to exit \n");

        fgets(input, 50, stdin);
        input[strlen(input) - 1] = '\0';

        if (strcmp(input, "1") == 0)
        {
            printf("Enter the name: ");
            fgets(name, 50, stdin); 
            name[strlen(name) - 1] = '\0';

            printf("Enter the number: ");
            fgets(number, 20, stdin); 
            number[strlen(number) - 1] = '\0';

            addContact(name, number);
            printf("%s has been added to the Phone Book. \n", name);
        }
        else if (strcmp(input, "2") == 0)
        {
            printContacts();
        }
        else if (strcmp(input, "3") == 0)
        {
            printf("Enter the name of the contact you want to delete: ");
            fgets(name, 50, stdin); 
            name[strlen(name) - 1] = '\0';

            deleteContact(name);
        }
        else if (strcmp(input, "4") == 0)
        {
            printf("Enter the name of the contact you want to update: ");
            fgets(name, 50, stdin); 
            name[strlen(name) - 1] = '\0';

            updateContact(name);
        }
        else if (strcmp(input, "5") == 0)
        {
            printf("Enter the name of the contact you want to search for: ");
            fgets(name, 50, stdin); 
            name[strlen(name) - 1] = '\0';

            searchContact(name);
        }
        else if (strcmp(input, "6") == 0)
        {
            printf("Goodbye! \n");
            exit(0);
        }
        else
        {
            printf("Invalid input. Please enter a number between 1-6. \n");
        }
    }

    return 0;
}

void addContact(char name[], char number[])
{
    struct PhoneBook* newContact = (struct PhoneBook*)malloc(sizeof(struct PhoneBook));

    if (newContact == NULL)
    {
        printf("Error: Memory allocation failed. \n");
        exit(0);
    }

    strcpy(newContact->name, name);
    strcpy(newContact->number, number);
    newContact->next = NULL;

    if (head == NULL)
    {
        head = newContact;
    }
    else
    {
        struct PhoneBook* current = head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newContact;
    }
}

void printContacts()
{
    printf("All contacts: \n");

    if (head == NULL)
    {
        printf("The Phone Book is empty. \n");
    }
    else
    {
        struct PhoneBook* current = head;

        while (current != NULL)
        {
            printf("%s: %s \n", current->name, current->number);
            current = current->next;
        }
    }
}

void deleteContact(char name[])
{
    if (head == NULL)
    {
        printf("The Phone Book is empty. \n");
    }
    else
    {
        struct PhoneBook* current = head;
        struct PhoneBook* previous = NULL;

        while (strcmp(current->name, name) != 0 && current->next != NULL)
        {
            previous = current;
            current = current->next;
        }

        if (strcmp(current->name, name) == 0)
        {
            if (previous == NULL)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            printf("%s has been deleted from the Phone Book. \n", current->name);
            free(current);
        }
        else
        {
            printf("%s is not in the Phone Book. \n", name);
        }
    }
}

void updateContact(char name[])
{
    if (head == NULL)
    {
        printf("The Phone Book is empty. \n");
    }
    else
    {
        struct PhoneBook* current = head;

        while (strcmp(current->name, name) != 0 && current->next != NULL)
        {
            current = current->next;
        }

        if (strcmp(current->name, name) == 0)
        {
            char newNumber[20];
            printf("Enter the new number: ");
            fgets(newNumber, 20, stdin); 
            newNumber[strlen(newNumber) - 1] = '\0';

            strcpy(current->number, newNumber);
            printf("%s's number has been updated to %s. \n", current->name, current->number);
        }
        else
        {
            printf("%s is not in the Phone Book. \n", name);
        }
    }
}

void searchContact(char name[])
{
    if (head == NULL)
    {
        printf("The Phone Book is empty. \n");
    }
    else
    {
        struct PhoneBook* current = head;

        while (strcmp(current->name, name) != 0 && current->next != NULL)
        {
            current = current->next;
        }

        if (strcmp(current->name, name) == 0)
        {
            printf("%s's number is %s. \n", current->name, current->number);
        }
        else
        {
            printf("%s is not in the Phone Book. \n", name);
        }
    }
}
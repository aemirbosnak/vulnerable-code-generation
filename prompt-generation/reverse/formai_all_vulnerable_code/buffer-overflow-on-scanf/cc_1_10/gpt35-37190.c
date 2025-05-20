//FormAI DATASET v1.0 Category: Phone Book ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact
{
    char name[50];
    char phone[15];
    char email[50];
};

// Function prototypes
void addContact();
void searchContact();
void editContact();
void deleteContact();
void displayContactList();
void saveToFile();
void loadFromFile();

struct contact contacts[100];    // Array of contacts
int numContacts = 0;             // Number of contacts stored in the array

int main()
{
    int choice;

    loadFromFile();    // Load data from file, if any

    do
    {
        printf("----------------------------------------------------\n");
        printf("                     PHONE BOOK\n");
        printf("----------------------------------------------------\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Display Contact List\n");
        printf("6. Exit\n");
        printf("----------------------------------------------------\n");
        printf("Enter your choice (1-6): ");
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
                editContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                displayContactList();
                break;
            case 6:
                saveToFile();    // Save data to file
                printf("Thank you for using Phone Book.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void addContact()
{
    if (numContacts == 100)
    {
        printf("Sorry, Phone Book is full. You cannot add any more contacts.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", contacts[numContacts].name);

    printf("Enter phone number: ");
    scanf("%s", contacts[numContacts].phone);

    printf("Enter email: ");
    scanf("%s", contacts[numContacts].email);

    numContacts++;

    printf("Contact added successfully.\n");
}

void searchContact()
{
    char name[50];
    int i, found = 0;

    printf("Enter name to search: ");
    scanf("%s", name);

    for (i = 0; i < numContacts; i++)
    {
        if (strcmp(name, contacts[i].name) == 0)
        {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Sorry, contact not found.\n");
    }
}

void editContact()
{
    char name[50];
    int i, found = 0;

    printf("Enter name to edit: ");
    scanf("%s", name);

    for (i = 0; i < numContacts; i++)
    {
        if (strcmp(name, contacts[i].name) == 0)
        {
            printf("Enter new phone number: ");
            scanf("%s", contacts[i].phone);

            printf("Enter new email: ");
            scanf("%s", contacts[i].email);

            printf("Contact edited successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Sorry, contact not found.\n");
    }
}

void deleteContact()
{
    char name[50];
    int i, j, found = 0;

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (i = 0; i < numContacts; i++)
    {
        if (strcmp(name, contacts[i].name) == 0)
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Sorry, contact not found.\n");
        return;
    }

    for (j = i; j < numContacts - 1; j++)
    {
        strcpy(contacts[j].name, contacts[j+1].name);
        strcpy(contacts[j].phone, contacts[j+1].phone);
        strcpy(contacts[j].email, contacts[j+1].email);
    }

    numContacts--;

    printf("Contact deleted successfully.\n");
}

void displayContactList()
{
    int i;

    if (numContacts == 0)
    {
        printf("Phone Book is empty.\n");
        return;
    }

    printf("Name\t\tPhone\t\tEmail\n");
    printf("----------------------------------------------------\n");
    for (i = 0; i < numContacts; i++)
    {
        printf("%s\t\t%s\t%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

void saveToFile()
{
    FILE *fp;
    int i;

    fp = fopen("phonebook.txt", "w");

    if (fp == NULL)
    {
        printf("Could not open file for writing.\n");
        return;
    }

    fprintf(fp, "%d\n", numContacts);

    for (i = 0; i < numContacts; i++)
    {
        fprintf(fp, "%s %s %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    fclose(fp);

    printf("Data saved to file successfully.\n");
}

void loadFromFile()
{
    FILE *fp;
    int i;

    fp = fopen("phonebook.txt", "r");

    if (fp == NULL)
    {
        printf("Could not open file for reading.\n");
        return;
    }

    fscanf(fp, "%d", &numContacts);

    for (i = 0; i < numContacts; i++)
    {
        fscanf(fp, "%s %s %s", contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    fclose(fp);

    printf("Data loaded from file successfully.\n");
}
//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LEN 30
#define MAX_EMAIL_LEN 50
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
}Contact;

Contact contacts[MAX_CONTACTS];
int numContacts = 0;

void addContact()
{
    if(numContacts == MAX_CONTACTS)
    {
        printf("Maximum contacts limit reached.\n");
        return;
    }

    Contact newContact;
    printf("Enter name of contact: ");
    fgets(newContact.name, MAX_NAME_LEN, stdin);

    // Removing new line character from name
    newContact.name[strcspn(newContact.name, "\n")] = 0;

    printf("Enter email of contact: ");
    fgets(newContact.email, MAX_EMAIL_LEN, stdin);

    // Removing new line character from email
    newContact.email[strcspn(newContact.email, "\n")] = 0;

    contacts[numContacts++] = newContact;

    printf("Contact added successfully.\n");
}

void displayContacts()
{
    if(numContacts == 0)
    {
        printf("No contacts found.\n");
        return;
    }

    printf("Contacts:\n");
    printf("Name\tEmail\n");
    for(int i=0;i<numContacts;i++)
    {
        printf("%s\t%s\n", contacts[i].name, contacts[i].email);
    }
}

void searchContact()
{
    char searchName[MAX_NAME_LEN];
    printf("Enter name to be searched: ");
    fgets(searchName, MAX_NAME_LEN, stdin);

    // Removing new line character from name
    searchName[strcspn(searchName, "\n")] = 0;

    int found = 0;
    printf("Results:\n");
    for(int i=0;i<numContacts;i++)
    {
        if(strcmp(contacts[i].name, searchName) == 0)
        {
            printf("%s\t%s\n", contacts[i].name, contacts[i].email);
            found = 1;
        }
    }

    if(!found)
    {
        printf("No results found for %s.\n", searchName);
    }
}

int main()
{
    int choice = 0;

    while(1)
    {
        printf("-------- Mailing List Manager --------\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        // Clearing input buffer
        fflush(stdin);

        switch(choice)
        {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
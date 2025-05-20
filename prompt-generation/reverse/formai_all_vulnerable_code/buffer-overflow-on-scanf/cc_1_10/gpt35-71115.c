//FormAI DATASET v1.0 Category: Phone Book ; Style: curious
#include<stdio.h>
#include<string.h>

struct Contact
{
    char name[50];
    char phone_number[20];
};

void addContact(struct Contact book[], int *numContacts);
void searchContact(struct Contact book[], int numContacts);
void displayAllContacts(struct Contact book[], int numContacts);

int main()
{
    struct Contact phonebook[100];
    int numContacts = 0, choice;

    while(1)
    {
        printf("\n*** PHONE BOOK MENU ***\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addContact(phonebook, &numContacts);
                break;
            case 2:
                searchContact(phonebook, numContacts);
                break;
            case 3:
                displayAllContacts(phonebook, numContacts);
                break;
            case 4:
                printf("Exiting phonebook application...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void addContact(struct Contact book[], int *numContacts)
{
    if(*numContacts == 100)
    {
        printf("Phonebook is full, cannot add new contacts.\n");
        return;
    }

    struct Contact newContact;
    printf("Enter the name of the contact: ");
    scanf("%s", newContact.name);
    printf("Enter the phone number of the contact: ");
    scanf("%s", newContact.phone_number);
    book[*numContacts] = newContact;
    (*numContacts)++;
    printf("Contact information added successfully.\n");
}

void searchContact(struct Contact book[], int numContacts)
{
    char name[50];
    printf("Enter the name of the contact you want to search: ");
    scanf("%s", name);

    for(int i=0; i<numContacts; i++)
    {
        if(strcmp(book[i].name, name)==0)
        {
            printf("Name: %s\nPhone number: %s\n", book[i].name, book[i].phone_number);
            return;
        }
    }

    printf("Contact not found.\n");
}

void displayAllContacts(struct Contact book[], int numContacts)
{
    if(numContacts==0)
    {
        printf("No contacts found in the phonebook.\n");
        return;
    }

    printf("List of contacts in the phonebook:\n");
    for(int i=0; i<numContacts; i++)
    {
        printf("%d. Name: %s, Phone number: %s\n", i+1, book[i].name, book[i].phone_number);
    }
}
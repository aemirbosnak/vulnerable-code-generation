//FormAI DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_NAME_LEN];
} Contact;

int searchContact(Contact* cList, int size, char* email);
void addContact(Contact* cList, int* size);
void removeContact(Contact* cList, int* size);
void printContacts(Contact* cList, int size);

int main() {
    Contact* contacts = malloc(sizeof(Contact) * 100); //Allocate space for contacts array
    int numOfContacts = 0;
    int choice = 0;

    printf("Welcome to the Paranoid Mailing List Manager\n");

    while (1) {
        printf("Please choose an option:\n");
        printf("1. Add a contact.\n");
        printf("2. Remove a contact.\n");
        printf("3. Print all contacts.\n");
        printf("4. Exit.\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numOfContacts);
                break;
            case 2:
                removeContact(contacts, &numOfContacts);
                break;
            case 3:
                printContacts(contacts, numOfContacts);
                break;
            case 4:
                free(contacts); //Free allocated memory and exit program
                printf("Exiting manager...\n");
                return 0;
            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    }

    return 0;
}

//Function to search contacts array for a specific email
int searchContact(Contact* cList, int size, char* email) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(cList[i].email, email) == 0) {
            return i;
        }
    }

    return -1;
}

//Function to add contact to contacts array
void addContact(Contact* cList, int* size) {
    Contact newContact;
    char confirmChoice;

    printf("Enter name: ");
    scanf("%s", newContact.name);

    printf("Enter email: ");
    scanf("%s", newContact.email);

    if (searchContact(cList, *size, newContact.email) != -1) {
        printf("Contact with that email already exists.\n");
        return;
    }

    printf("Confirm add contact '%s' with email '%s'? (Y/N) ", newContact.name, newContact.email);
    fflush(stdin);
    scanf("%c", &confirmChoice);

    if (confirmChoice == 'Y' || confirmChoice == 'y') {
        cList[*size] = newContact;
        (*size)++;
        printf("Contact added.\n");
    }
    else {
        printf("Contact not added.\n");
    }
}

//Function to remove contact from contacts array
void removeContact(Contact* cList, int* size) {
    char email[MAX_NAME_LEN];
    int contactToRemove;
    char confirmChoice;

    printf("Enter email of contact to remove: ");
    scanf("%s", email);

    contactToRemove = searchContact(cList, *size, email);

    if (contactToRemove == -1) {
        printf("Contact with that email does not exist.\n");
        return;
    }

    printf("Confirm remove contact '%s' with email '%s'? (Y/N) ", cList[contactToRemove].name, email);
    fflush(stdin);
    scanf("%c", &confirmChoice);

    if (confirmChoice == 'Y' || confirmChoice == 'y') {
        memmove(&cList[contactToRemove], &cList[contactToRemove + 1], (*size - contactToRemove - 1) * sizeof(Contact));
        (*size)--;
        printf("Contact removed.\n");
    }
    else {
        printf("Contact not removed.\n");
    }
}

//Function to print all contacts in contacts array
void printContacts(Contact* cList, int size) {
    int i;

    printf("Printing all contacts:\n");

    for (i = 0; i < size; i++) {
        printf("%s - %s\n", cList[i].name, cList[i].email);
    }
}
//FormAI DATASET v1.0 Category: Mailing list manager ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold mailing list information
typedef struct {
    char firstName[20];
    char lastName[20];
    char email[50];
} MailingList;

// function prototypes
void addContact(MailingList* list, int* count);
void deleteContact(MailingList* list, int* count);
void printList(MailingList* list, int count);
void saveList(MailingList* list, int count);

int main()
{
    int count = 0;
    char option;

    // allocate memory for mailing list
    MailingList* list = (MailingList*) malloc(sizeof(MailingList));

    printf("Welcome to the Mailing List Manager!\n");

    do {
        // display menu options
        printf("\nPlease select an option: \n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Print list\n");
        printf("4. Save list\n");
        printf("5. Quit\n");

        // read user's choice
        scanf(" %c", &option);

        switch (option) {
            case '1':
                addContact(list, &count);
                break;
            case '2':
                deleteContact(list, &count);
                break;
            case '3':
                printList(list, count);
                break;
            case '4':
                saveList(list, count);
                break;
            case '5':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option, please try again.\n");
        }
    } while (option != '5');

    // free dynamically allocated memory and exit program
    free(list);
    return 0;
}

// function to add a new contact to the mailing list
void addContact(MailingList* list, int* count)
{
    // reallocate memory for mailing list to fit new contact
    list = (MailingList*) realloc(list, (*count + 1) * sizeof(MailingList));

    // read input for new contact's information
    printf("\nAdding new contact...\n");
    printf("First Name: ");
    scanf(" %s", list[*count].firstName);
    printf("Last Name: ");
    scanf(" %s", list[*count].lastName);
    printf("Email: ");
    scanf(" %s", list[*count].email);

    // increment number of contacts
    (*count)++;

    printf("Contact added!\n");
}

// function to delete a contact from the mailing list
void deleteContact(MailingList* list, int* count)
{
    int i, j;
    char email[50];

    // read input for email address of contact to be deleted
    printf("\nDeleting contact...\n");
    printf("Email: ");
    scanf(" %s", email);

    // search for contact with matching email address
    for (i = 0; i < *count; i++) {
        if (strcmp(list[i].email, email) == 0) {
            // shift contacts after deleted contact up one position
            for (j = i; j < (*count - 1); j++) {
                strcpy(list[j].firstName, list[j + 1].firstName);
                strcpy(list[j].lastName, list[j + 1].lastName);
                strcpy(list[j].email, list[j + 1].email);
            }

            // decrement number of contacts
            (*count)--;

            printf("Contact deleted!\n");
            return;
        }
    }

    // contact not found
    printf("Contact not found.\n");
}

// function to print all contacts in the mailing list
void printList(MailingList* list, int count)
{
    int i;

    printf("\nPrinting mailing list...\n");

    for (i = 0; i < count; i++) {
        printf("%s %s - %s\n", list[i].firstName, list[i].lastName, list[i].email);
    }
}

// function to save the mailing list to a file
void saveList(MailingList* list, int count)
{
    FILE* file;
    int i;

    // open file for writing
    file = fopen("mailing_list.txt", "w");

    // write each contact to file
    for (i = 0; i < count; i++) {
        fprintf(file, "%s %s - %s\n", list[i].firstName, list[i].lastName, list[i].email);
    }

    // close file
    fclose(file);

    printf("\nMailing list saved to file.\n");
}
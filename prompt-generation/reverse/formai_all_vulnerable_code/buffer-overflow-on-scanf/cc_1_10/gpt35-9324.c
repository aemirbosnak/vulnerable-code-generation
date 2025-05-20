//FormAI DATASET v1.0 Category: Mailing list manager ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 50

typedef struct {
    char name[50];
    char email[50];
} Contact;

typedef struct {
    int numContacts;
    Contact contacts[MAX_EMAILS];
} MailingList;

int addContact(MailingList* ml, char* name, char* email);
void displayContacts(MailingList* ml);
int removeContact(MailingList* ml, char* email);

int main()
{
    MailingList ml;
    ml.numContacts = 0;
    int choice;
    char name[50], email[50];

    printf("Welcome to the Mailing List Manager!\n");

    do {
        printf("\n1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Remove contact\n");
        printf("4. Quit\n");
        printf("\nWhat would you like to do? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter name: ");
                scanf("%s", name);
                printf("\nEnter email: ");
                scanf("%s", email);
                addContact(&ml, name, email);
                break;
            case 2:
                displayContacts(&ml);
                break;
            case 3:
                printf("\nEnter email: ");
                scanf("%s", email);
                removeContact(&ml, email);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}

int addContact(MailingList* ml, char* name, char* email)
{
    if (ml->numContacts == MAX_EMAILS) {
        printf("\nMailing list is full.\n");
        return 0;
    }

    for (int i = 0; i < ml->numContacts; i++) {
        if (strcmp(ml->contacts[i].email, email) == 0) {
            printf("\nContact already exists.\n");
            return 0;
        }
    }

    Contact newContact;
    strcpy(newContact.name, name);
    strcpy(newContact.email, email);

    ml->contacts[ml->numContacts++] = newContact;

    printf("\nContact added successfully.\n");
    return 1;
}

void displayContacts(MailingList* ml)
{
    if (ml->numContacts == 0) {
        printf("\nMailing list is empty.\n");
        return;
    }

    printf("\nContacts:\n");

    for (int i = 0; i < ml->numContacts; i++) {
        printf("%s <%s>\n", ml->contacts[i].name, ml->contacts[i].email);
    }
}

int removeContact(MailingList* ml, char* email)
{
    for (int i = 0; i < ml->numContacts; i++) {
        if (strcmp(ml->contacts[i].email, email) == 0) {
            for (int j = i+1; j < ml->numContacts; j++) {
                ml->contacts[j-1] = ml->contacts[j];
            }
            ml->numContacts--;
            printf("\nContact removed successfully.\n");
            return 1;
        }
    }

    printf("\nContact not found.\n");
    return 0;
}
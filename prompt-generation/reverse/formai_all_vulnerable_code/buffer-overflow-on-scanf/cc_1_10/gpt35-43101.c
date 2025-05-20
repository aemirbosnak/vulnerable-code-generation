//FormAI DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// max number of contacts
#define MAX_CONTACTS 1000

// contact struct with name and email
struct Contact {
    char name[100];
    char email[100];
};

// function prototypes
void addContact(struct Contact contacts[], int *numContacts);
void removeContact(struct Contact contacts[], int *numContacts);
void printContacts(struct Contact contacts[], int numContacts);

int main() {

    // initialize empty mailing list with 0 contacts
    struct Contact mailingList[MAX_CONTACTS];
    int numContacts = 0;

    char choice;
    do {
        // show menu and get user choice
        printf("MAILING LIST MANAGER\n");
        printf("A - Add contact\n");
        printf("R - Remove contact\n");
        printf("P - Print contacts\n");
        printf("Q - Quit\n");
        printf("Choice: ");
        scanf(" %c", &choice);

        // perform appropriate action based on user choice
        switch (choice) {
            case 'A':
            case 'a':
                addContact(mailingList, &numContacts);
                break;
            case 'R':
            case 'r':
                removeContact(mailingList, &numContacts);
                break;
            case 'P':
            case 'p':
                printContacts(mailingList, numContacts);
                break;
            case 'Q':
            case 'q':
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

    } while (choice != 'Q' && choice != 'q');

    printf("Goodbye!\n");

    return 0;
}

void addContact(struct Contact contacts[], int *numContacts) {
    // check if max number of contacts has been reached
    if (*numContacts >= MAX_CONTACTS) {
        printf("Mailing list is full!\n");
        return;
    }

    // get name and email from user
    char name[100];
    char email[100];
    printf("Enter name: ");
    scanf(" %[^\n]s", name);
    printf("Enter email: ");
    scanf(" %[^\n]s", email);

    // add contact to list
    strcpy(contacts[*numContacts].name, name);
    strcpy(contacts[*numContacts].email, email);
    (*numContacts)++;
    printf("Contact added.\n");
}

void removeContact(struct Contact contacts[], int *numContacts) {
    // check if mailing list is empty
    if (*numContacts == 0) {
        printf("Mailing list is empty!\n");
        return;
    }

    // get name to remove from user
    char name[100];
    printf("Enter name to remove: ");
    scanf(" %[^\n]s", name);

    // search for matching contact and remove it
    int i;
    for (i = 0; i < *numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            int j;
            for (j = i; j < *numContacts - 1; j++) {
                contacts[j] = contacts[j+1];
            }
            (*numContacts)--;
            printf("Contact removed.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

void printContacts(struct Contact contacts[], int numContacts) {
    // check if mailing list is empty
    if (numContacts == 0) {
        printf("Mailing list is empty!\n");
        return;
    }

    // print all contacts in list
    printf("Mailing list:\n");
    int i;
    for (i = 0; i < numContacts; i++) {
        printf("%s <%s>\n", contacts[i].name, contacts[i].email);
    }
}
//FormAI DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAMELENGTH 50
#define MAXEMAILLENGTH 100
#define MAXCONTACTS 100

// Structure for a contact
typedef struct {
    char name[MAXNAMELENGTH];
    char email[MAXEMAILLENGTH];
} contact;

// Structure for a mailing list
typedef struct {
    int numContacts;
    contact contacts[MAXCONTACTS];
} mailingList;

// Function to prompt user for contact information
void getContactInformation(contact *newContact) {
    printf("Please enter the contact's name: ");
    fgets(newContact->name, MAXNAMELENGTH, stdin);
    newContact->name[strlen(newContact->name)-1] = '\0'; // Remove newline character
    printf("Please enter the contact's email address: ");
    fgets(newContact->email, MAXEMAILLENGTH, stdin);
    newContact->email[strlen(newContact->email)-1] = '\0'; // Remove newline character
}

// Function to add a contact to a mailing list
void addContact(mailingList *list, contact newContact) {
    if (list->numContacts == MAXCONTACTS) {
        printf("Error: Mailing list is full\n");
        return;
    }
    list->contacts[list->numContacts] = newContact;
    list->numContacts++;
}

// Function to remove a contact from a mailing list by name
void removeContact(mailingList *list, char *nameToRemove) {
    int i, j;
    for (i = 0; i < list->numContacts; i++) {
        if (strcmp(list->contacts[i].name, nameToRemove) == 0) {
            for (j = i+1; j < list->numContacts; j++) {
                list->contacts[j-1] = list->contacts[j];
            }
            list->numContacts--;
            return;
        }
    }
    printf("Error: Contact not found\n");
}

// Function to print all contacts in a mailing list
void printContacts(mailingList *list) {
    int i;
    for (i = 0; i < list->numContacts; i++) {
        printf("%s (%s)\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    mailingList list;
    list.numContacts = 0;
    int done = 0;
    while (!done) {
        printf("\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Print contacts\n");
        printf("4. Quit\n");
        printf("\n");

        int choice;
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Remove newline character

        switch (choice) {
            case 1:
                printf("\n");
                printf("Adding a new contact:\n");
                contact newContact;
                getContactInformation(&newContact);
                addContact(&list, newContact);
                printf("Contact added successfully!\n");
                break;
            case 2:
                printf("\n");
                printf("Removing a contact:\n");
                char nameToRemove[MAXNAMELENGTH];
                printf("Please enter the contact's name: ");
                fgets(nameToRemove, MAXNAMELENGTH, stdin);
                nameToRemove[strlen(nameToRemove)-1] = '\0'; // Remove newline character
                removeContact(&list, nameToRemove);
                break;
            case 3:
                printf("\n");
                printf("Printing all contacts:\n");
                printContacts(&list);
                break;
            case 4:
                done = 1;
                break;
            default:
                printf("\n");
                printf("Error: Invalid choice\n");
                break;
        }
    }
    return 0;
}
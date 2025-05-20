//FormAI DATASET v1.0 Category: Mailing list manager ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 1000
#define MAX_NAME_SIZE 50
#define MAX_EMAIL_SIZE 100

/* Define struct to hold contact information */
typedef struct contact {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
} Contact;

Contact mailingList[MAX_LIST_SIZE];
int numContacts = 0;

/* Function to add a new contact to the mailing list */
void addContact() {
    /* Check if mailing list is already full */
    if (numContacts == MAX_LIST_SIZE) {
        printf("Error: Mailing list is already full\n");
        return;
    }

    /* Get name and email from user input */
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);

    /* Create new contact and add to mailing list */
    Contact newContact;
    strcpy(newContact.name, name);
    strcpy(newContact.email, email);
    mailingList[numContacts++] = newContact;

    /* Notify user of successful addition */
    printf("%s <%s> has been added to the mailing list!\n", name, email);
}

/* Function to remove a contact from the mailing list */
void removeContact() {
    /* Check if mailing list is empty */
    if (numContacts == 0) {
        printf("Error: Mailing list is empty\n");
        return;
    }

    /* Get name to remove from user input */
    char name[MAX_NAME_SIZE];
    printf("Enter name to remove: ");
    scanf("%s", name);

    /* Find contact by name in mailing list and remove */
    int i;
    for (i = 0; i < numContacts; i++) {
        if (strcmp(mailingList[i].name, name) == 0) {
            /* Shift remaining contacts down one position in list */
            int j;
            for (j = i; j < numContacts-1; j++) {
                mailingList[j] = mailingList[j+1];
            }
            numContacts--;

            /* Notify user of successful removal */
            printf("%s <%s> has been removed from the mailing list\n", name, mailingList[i].email);
            return;
        }
    }

    /* If contact not found, notify user */
    printf("%s was not found in the mailing list\n", name);
}

/* Function to print all contacts in the mailing list */
void printContacts() {
    /* Check if mailing list is empty */
    if (numContacts == 0) {
        printf("Mailing list is empty\n");
        return;
    }

    /* Loop through all contacts in mailing list and print */
    int i;
    for (i = 0; i < numContacts; i++) {
        printf("%s <%s>\n", mailingList[i].name, mailingList[i].email);
    }
}

int main() {
    /* Display menu and get user input */
    int choice = 0;
    while (choice != 4) {
        printf("Mailing List Manager\n");
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Print Contacts\n");
        printf("4. Quit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);

        /* Call appropriate function based on user choice */
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                removeContact();
                break;
            case 3:
                printContacts();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
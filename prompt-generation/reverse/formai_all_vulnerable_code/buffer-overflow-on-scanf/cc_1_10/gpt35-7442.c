//FormAI DATASET v1.0 Category: Mailing list manager ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct Contact {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

int main() {

    Contact* mailingList = (Contact*) malloc(sizeof(Contact) * MAX_EMAILS);

    if (mailingList == NULL) {
        printf("Error allocating memory for mailing list.\n");
        return 1;
    }

    int numContacts = 0;

    printf("Welcome to the Happy Mailing List Manager!\n\n");

    while (1) {
        printf("Please choose an option:\n"
                "1. Add a contact to the mailing list\n"
                "2. Display all contacts in the mailing list\n"
                "3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (numContacts == MAX_EMAILS) {
                    printf("Sorry, the mailing list is full.\n");
                    break;
                }

                printf("Adding a new contact:\n");

                printf("Name: ");
                char name[MAX_NAME_LEN];
                scanf("%s", name);

                printf("Email: ");
                char email[MAX_EMAIL_LEN];
                scanf("%s", email);

                strcpy(mailingList[numContacts].name, name);
                strcpy(mailingList[numContacts].email, email);

                printf("Contact added!\n");

                numContacts++;

                break;
            }
            case 2: {
                if (numContacts == 0) {
                    printf("There are no contacts in the mailing list yet.\n");
                    break;
                }

                printf("Mailing list:\n");

                for (int i = 0; i < numContacts; i++) {
                    printf("%s: %s\n", mailingList[i].name, mailingList[i].email);
                }

                break;
            }
            case 3: {
                printf("Thank you for using the Happy Mailing List Manager! Have a great day!\n");
                free(mailingList);
                return 0;
            }
            default: {
                printf("Sorry, that is not a valid option. Please choose again.\n");
            }
        }
    }
}
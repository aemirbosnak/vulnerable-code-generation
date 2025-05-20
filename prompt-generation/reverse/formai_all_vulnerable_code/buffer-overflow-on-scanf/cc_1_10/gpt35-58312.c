//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
/* Romeo and Juliet's Mailing List Manager */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function signatures */
void addEmail(char * email, char ** mailingList, int * listSizePtr);
void removeEmail(char * email, char ** mailingList, int * listSizePtr);
void printMailingList(char ** mailingList, int listSize);

/* Main function */
int main()
{
    int listSize = 0;
    char ** mailingList = malloc(listSize * sizeof(char*));

    printf("\n\n********************************************\n");
    printf("* Welcome to Romeo and Juliet's Mailing List *\n");
    printf("********************************************\n\n");

    while (1)
    {
        printf("What would you like to do?\n");
        printf("1. Add an email address\n");
        printf("2. Remove an email address\n");
        printf("3. Print the mailing list\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Please enter the email address you want to add: ");
                char emailToAdd[100];
                scanf("%s", emailToAdd);
                addEmail(emailToAdd, mailingList, &listSize);
                printf("Thank you! The email address has been added.\n");
                break;

            case 2:
                printf("Please enter the email address you want to remove: ");
                char emailToRemove[100];
                scanf("%s", emailToRemove);
                removeEmail(emailToRemove, mailingList, &listSize);
                printf("Thank you! The email address has been removed.\n");
                break;

            case 3:
                printf("\n--- Mailing List ---\n");
                printMailingList(mailingList, listSize);
                break;

            case 4:
                printf("Thank you for using Romeo and Juliet's Mailing List. Goodbye!\n\n");
                free(mailingList);
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

/* Function to add an email address to the mailing list */
void addEmail(char * email, char ** mailingList, int * listSizePtr)
{
    (*listSizePtr)++;
    mailingList = realloc(mailingList, (*listSizePtr) * sizeof(char*));
    mailingList[(*listSizePtr) - 1] = malloc(strlen(email) + 1);
    strcpy(mailingList[(*listSizePtr) - 1], email);
}

/* Function to remove an email address from the mailing list */
void removeEmail(char * email, char ** mailingList, int * listSizePtr)
{
    int indexToRemove = -1;

    for (int i = 0; i < (*listSizePtr); i++)
    {
        if (strcmp(mailingList[i], email) == 0)
        {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove != -1)
    {
        free(mailingList[indexToRemove]);

        for (int i = indexToRemove; i < (*listSizePtr) - 1; i++)
        {
            mailingList[i] = mailingList[i+1];
        }

        (*listSizePtr)--;
        mailingList = realloc(mailingList, (*listSizePtr) * sizeof(char*));
    }
    else
    {
        printf("The email address you entered was not found in the mailing list.\n");
    }
}

/* Function to print the mailing list */
void printMailingList(char ** mailingList, int listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        printf("%d. %s\n", i+1, mailingList[i]);
    }
}
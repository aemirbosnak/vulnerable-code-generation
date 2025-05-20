//FormAI DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 20
#define NUM_OF_PASSWORDS 5

int main()
{
    char passwords[NUM_OF_PASSWORDS][MAX_LENGTH];
    char answer[MAX_LENGTH];
    int choice;
    int i, j, k;
    srand(time(0));

    printf("Welcome to the Password Manager 3000!\n");
    printf("Shall we begin?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice != 1)
    {
        printf("Are you sure you don't want to use our program?\n");
        printf("1. Yes, I'm sure\n");
        printf("2. Okay, let's begin\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    printf("\nGreat! Let's get started.\n");
    printf("We will generate %d unique passwords for you.\n", NUM_OF_PASSWORDS);
    printf("And remember, don't share your passwords with anyone!\n");

    for (i = 0; i < NUM_OF_PASSWORDS; i++)
    {
        for (j = 0; j < MAX_LENGTH-1; j++)
        {
            k = rand() % 3;

            if (k == 0)
            {
                passwords[i][j] = rand() % 26 + 'a';
            }
            else if (k == 1)
            {
                passwords[i][j] = rand() % 26 + 'A';
            }
            else
            {
                passwords[i][j] = rand() % 10 + '0';
            }
        }
        passwords[i][MAX_LENGTH-1] = '\0';
    }

    printf("\nHere are your passwords:\n");

    for (i = 0; i < NUM_OF_PASSWORDS; i++)
    {
        printf("%d. %s\n", i+1, passwords[i]);
    }

    printf("\nWhich password would you like to use?\n");
    printf("Enter the number: ");
    scanf("%d", &choice);

    while (choice < 1 || choice > NUM_OF_PASSWORDS)
    {
        printf("Hmm, that's not a valid choice. Please try again.\n");
        printf("Enter the number: ");
        scanf("%d", &choice);
    }

    printf("\nAre you sure you want to use '%s' as your password?\n", passwords[choice-1]);
    printf("1. Yes\n");
    printf("2. No, generate a new password\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice != 1)
    {
        for (j = 0; j < MAX_LENGTH-1; j++)
        {
            k = rand() % 3;

            if (k == 0)
            {
                passwords[choice-1][j] = rand() % 26 + 'a';
            }
            else if (k == 1)
            {
                passwords[choice-1][j] = rand() % 26 + 'A';
            }
            else
            {
                passwords[choice-1][j] = rand() % 10 + '0';
            }
        }
        passwords[choice-1][MAX_LENGTH-1] = '\0';

        printf("\nHere is your new password: %s\n", passwords[choice-1]);
        printf("Are you happy with this new password?\n");
        printf("1. Yes\n");
        printf("2. No, generate another new password\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    printf("\nCongratulations! You've successfully managed your password.\n");
    printf("As a reward, here's a joke:\n");

    printf("Why did the password manager go to the therapist?\n");
    printf("To get multi-factor authentication!\n");
    printf("Hahaha, I crack myself up sometimes.\n");

    return 0;
}
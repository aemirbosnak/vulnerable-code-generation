//FormAI DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20
#define MASTER_PASSWORD "password123"

int main()
{
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    char masterPassword[MAX_PASSWORD_LENGTH];
    int numPasswords = 0;

    //Request master password
    printf("Please enter the master password:\n");
    fgets(masterPassword, MAX_PASSWORD_LENGTH, stdin);
    //Remove newline character from input
    if (strlen(masterPassword) > 0 && masterPassword[strlen(masterPassword)-1] == '\n')
        masterPassword[strlen(masterPassword)-1] = '\0';

    //Verify master password
    if (strcmp(masterPassword, MASTER_PASSWORD) != 0)
    {
        printf("Incorrect password. Program terminated.\n");
        return 0;
    }

    //Master password verified, enter password management loop
    while (true)
    {
        //Menu
        printf("\nMenu:\n");
        printf("1. Add a password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");
        printf("Enter option: ");

        int option;
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                //Request new password
                printf("\nEnter new password (max %d characters):\n", MAX_PASSWORD_LENGTH);
                scanf("%s", passwords[numPasswords]);
                numPasswords++;
                printf("Password added successfully.\n");
                break;

            case 2:
                //Display passwords
                for (int i = 0; i < numPasswords; i++)
                    printf("%d. %s\n", i+1, passwords[i]);
                break;

            case 3:
                //Exit program
                printf("\nExiting program.\n");
                return 0;

            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
        //Clear input buffer
        while (getchar() != '\n');
    }

    return 0;
}
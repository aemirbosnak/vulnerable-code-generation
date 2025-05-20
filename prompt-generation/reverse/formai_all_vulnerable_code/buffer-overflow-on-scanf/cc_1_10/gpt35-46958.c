//FormAI DATASET v1.0 Category: Password management ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

int main()
{
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    int numPasswords = 0;
    int choice = 0;

    while (1)
    {
        printf("\nPassword manager\n");
        printf("1. Add a password\n");
        printf("2. View all passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                char password[MAX_PASSWORD_LENGTH];

                if (numPasswords >= MAX_PASSWORDS)
                {
                    printf("Maximum number of passwords reached.\n");
                    break;
                }

                printf("Enter password: ");
                scanf("%s", password);

                if (strlen(password) >= MAX_PASSWORD_LENGTH)
                {
                    printf("Password is too long.\n");
                    break;
                }

                strcpy(passwords[numPasswords], password);
                numPasswords++;

                printf("Password added.\n");
                break;
            }

            case 2:
            {
                if (numPasswords == 0)
                {
                    printf("No passwords added yet.\n");
                    break;
                }

                printf("\nPasswords:\n");

                for (int i = 0; i < numPasswords; i++)
                {
                    printf("%d. %s\n", i + 1, passwords[i]);
                }

                break;
            }

            case 3:
            {
                printf("Exiting...\n");
                exit(0);
            }

            default:
            {
                printf("Invalid choice.\n");
                break;
            }
        }
    }

    return 0;
}
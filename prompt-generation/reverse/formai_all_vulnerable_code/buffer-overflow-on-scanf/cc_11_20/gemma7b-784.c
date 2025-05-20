//Gemma-7B DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int choice, flag = 0, i = 0, length = 0;
    char password[100], new_password[100], confirm_password[100];

    system("clear");
    printf("#################################\n");
    printf("C Password Management System\n");
    printf("#################################\n");

    // Main loop
    while (1)
    {
        printf("\nPlease select an option:\n");
        printf("1. Create new password\n");
        printf("2. Change existing password\n");
        printf("3. Delete password\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                system("clear");
                printf("Enter a new password:** ");
                gets(new_password);
                length = strlen(new_password);
                if (length < 8)
                {
                    printf("Password must be at least 8 characters long.\n");
                }
                else
                {
                    flag = 1;
                    printf("Confirm new password:** ");
                    gets(confirm_password);
                    if (strcmp(new_password, confirm_password) == 0)
                    {
                        printf("Password successfully created.\n");
                        strcpy(password, new_password);
                    }
                    else
                    {
                        printf("Passwords do not match.\n");
                    }
                }
                break;

            case 2:
                system("clear");
                printf("Enter your current password: ");
                gets(confirm_password);
                if (strcmp(confirm_password, password) == 0)
                {
                    printf("Enter your new password: ");
                    gets(new_password);
                    length = strlen(new_password);
                    if (length < 8)
                    {
                        printf("Password must be at least 8 characters long.\n");
                    }
                    else
                    {
                        flag = 1;
                        strcpy(password, new_password);
                        printf("Password successfully changed.\n");
                    }
                }
                else
                {
                    printf("Incorrect password.\n");
                }
                break;

            case 3:
                system("clear");
                printf("Enter your password: ");
                gets(confirm_password);
                if (strcmp(confirm_password, password) == 0)
                {
                    printf("Are you sure you want to delete your password? (Y/N): ");
                    char answer;
                    scanf(" %c", &answer);
                    if (answer == 'Y')
                    {
                        printf("Password deleted.\n");
                        strcpy(password, "");
                    }
                    else
                    {
                        printf("Operation cancelled.\n");
                    }
                }
                else
                {
                    printf("Incorrect password.\n");
                }
                break;

            case 4:
                system("clear");
                printf("Thank you for using the C Password Management System.\n");
                exit(0);
                break;

            default:
                printf("Invalid input.\n");
                break;
        }

        if (flag == 0)
        {
            printf("Error occurred.\n");
        }

        flag = 0;
    }

    return 0;
}
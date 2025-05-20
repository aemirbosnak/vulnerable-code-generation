//FormAI DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 20

char passwords[5][MAX_LEN+1] = {"123456", "password", "qwerty", "admin", "letmein"};
bool is_password_changed = false;

void change_password(char* password)
{
    is_password_changed = true;
    strcpy(passwords[0], password);
}

int main()
{
    char current_password[MAX_LEN+1] = "123456";
    bool is_locked_out = false;
    int attempts_left = 3;

    printf("Welcome to Password Manager 3000!\n\n");

    while (!is_locked_out)
    {
        char input[MAX_LEN+1];
        printf("Please enter your password: ");
        scanf("%s", input);

        if (strcmp(input, current_password) == 0)
        {
            printf("Password correct! What would you like to do?\n");
            printf("1. Change password\n");
            printf("2. Exit\n");

            int choice;
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                {
                    char new_password[MAX_LEN+1];
                    printf("Enter your new password: ");
                    scanf("%s", new_password);

                    if (strcmp(new_password, current_password) == 0)
                    {
                        printf("Cannot set the same password as the current one!\n");
                    }
                    else if (strlen(new_password) > MAX_LEN)
                    {
                        printf("Password too long! Please enter a password of length <= %d\n", MAX_LEN);
                    }
                    else
                    {
                        change_password(new_password);
                        printf("Password changed successfully!\n");
                    }

                    break;
                }
                case 2:
                {
                    printf("Goodbye!\n");
                    return 0;
                }
                default:
                {
                    printf("Invalid choice!\n");
                    break;
                }
            }

            attempts_left = 3;
            strcpy(current_password, passwords[0]);
        }
        else
        {
            printf("Password incorrect!\n");
            attempts_left--;

            if (attempts_left == 0)
            {
                printf("Too many attempts! Account locked out!\n");
                is_locked_out = true;

                if (is_password_changed)
                {
                    printf("Please contact support to unlock your account!\n");
                }
                else
                {
                    printf("Please login using the default password to unlock your account!\n");
                }
            }
            else
            {
                printf("%d attempts left!\n", attempts_left);
            }
        }
    }

    return 0;
}
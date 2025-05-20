//FormAI DATASET v1.0 Category: Password management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 5
#define PASSWORD_LENGTH 10

void scramble_password(char *password);
void unscramble_password(char *password);

int main(void)
{
    char passwords[MAX_PASSWORDS][PASSWORD_LENGTH+1];
    char master_password[PASSWORD_LENGTH+1] = "s3cur3p@ssw0rd";
    int num_passwords = 0;
    int choice, i;
    char temp_password[PASSWORD_LENGTH+1];
    char scrambled_password[PASSWORD_LENGTH+1];

    printf("Welcome to the Password Manager\n");

    while (1)
    {
        printf("1. Add Password\n");
        printf("2. Edit Password\n");
        printf("3. Show All Passwords\n");
        printf("4. Remove Password\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (num_passwords < MAX_PASSWORDS)
                {
                    printf("Enter Password: ");
                    scanf("%s", temp_password);
                    scramble_password(temp_password);
                    strcpy(passwords[num_passwords], temp_password);
                    num_passwords++;
                    printf("Password Added\n");
                }
                else
                {
                    printf("Maximum Number of Passwords Reached\n");
                }
                break;
            case 2:
                printf("Enter Password Number (1-%d): ", num_passwords);
                scanf("%d", &i);
                i--;
                if (i < num_passwords && i >= 0)
                {
                    printf("Enter New Password: ");
                    scanf("%s", temp_password);
                    scramble_password(temp_password);
                    strcpy(passwords[i], temp_password);
                    printf("Password Updated\n");
                }
                else
                {
                    printf("Invalid Password Number\n");
                }
                break;
            case 3:
                printf("Password List:\n");
                for (i = 0; i < num_passwords; i++)
                {
                    unscramble_password(passwords[i]);
                    printf("%d: %s\n", i+1, passwords[i]);
                    scramble_password(passwords[i]);
                }
                break;
            case 4:
                printf("Enter Password Number (1-%d): ", num_passwords);
                scanf("%d", &i);
                i--;
                if (i < num_passwords && i >= 0)
                {
                    printf("Are you sure you want to remove password %d? (y/n)\n", i+1);
                    char response[2];
                    scanf("%s", response);
                    if (response[0] == 'y')
                    {
                        for (;i < num_passwords-1; i++)
                        {
                            strcpy(passwords[i], passwords[i+1]);
                        }
                        num_passwords--;
                        printf("Password Removed\n");
                    }
                    else
                    {
                        printf("Password Not Removed\n");
                    }
                }
                else
                {
                    printf("Invalid Password Number\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}

void scramble_password(char *password)
{
    int len = strlen(password);
    int i;
    for (i = 0; i < len; i++)
    {
        password[i] = password[i] ^ 0xFF;
    }
}

void unscramble_password(char *password)
{
    int len = strlen(password);
    int i;
    for (i = 0; i < len; i++)
    {
        password[i] = password[i] ^ 0xFF;
    }
}
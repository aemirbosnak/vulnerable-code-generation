//FormAI DATASET v1.0 Category: Password management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_MAX_LENGTH 20
#define PASSWORDS_MAX_COUNT 10

/* Global variables */
char passwords[PASSWORDS_MAX_COUNT][PASSWORD_MAX_LENGTH];
int total_passwords;

/* Function declarations */
void add_password();
void list_passwords();
void find_password();
void delete_password();
int get_input();

/* Main function */
int main()
{
    int option;

    printf("Welcome to the Password Manager!\n\n");

    while (1)
    {
        printf("Please select an option:\n");
        printf("1. Add a password\n");
        printf("2. List passwords\n");
        printf("3. Find a password\n");
        printf("4. Delete a password\n");
        printf("5. Exit\n\n");

        option = get_input();

        switch (option)
        {
            case 1:
                add_password();
                break;

            case 2:
                list_passwords();
                break;

            case 3:
                find_password();
                break;

            case 4:
                delete_password();
                break;

            case 5:
                printf("Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}

/* Function to get user input */
int get_input()
{
    int input;
    scanf("%d", &input);
    fflush(stdin);
    return input;
}

/* Function to add a password */
void add_password()
{
    char password[PASSWORD_MAX_LENGTH];

    printf("Please enter the password to add: ");
    scanf("%s", password);
    fflush(stdin);

    if (total_passwords == PASSWORDS_MAX_COUNT)
    {
        printf("Sorry, you cannot add any more passwords.\n");
        return;
    }

    strcpy(passwords[total_passwords], password);
    total_passwords++;

    printf("Password added successfully!\n");
}

/* Function to list all passwords */
void list_passwords()
{
    int i;

    if (total_passwords == 0)
    {
        printf("There are no passwords saved.\n");
        return;
    }

    for (i = 0; i < total_passwords; i++)
    {
        printf("%d. %s\n", i+1, passwords[i]);
    }
}

/* Function to find a password */
void find_password()
{
    char password[PASSWORD_MAX_LENGTH];

    printf("Please enter the password to find: ");
    scanf("%s", password);
    fflush(stdin);

    int i;
    for (i = 0; i < total_passwords; i++)
    {
        if (strcmp(passwords[i], password) == 0)
        {
            printf("Password found at index %d.\n", i+1);
            return;
        }
    }

    printf("Sorry, the password was not found.\n");
}

/* Function to delete a password */
void delete_password()
{
    char password[PASSWORD_MAX_LENGTH];

    printf("Please enter the password to delete: ");
    scanf("%s", password);
    fflush(stdin);

    int i;
    for (i = 0; i < total_passwords; i++)
    {
        if (strcmp(passwords[i], password) == 0)
        {
            int j;
            for (j = i; j < total_passwords-1; j++)
            {
                strcpy(passwords[j], passwords[j+1]);
            }

            total_passwords--;

            printf("Password deleted successfully!\n");

            return;
        }
    }

    printf("Sorry, the password was not found.\n");
}
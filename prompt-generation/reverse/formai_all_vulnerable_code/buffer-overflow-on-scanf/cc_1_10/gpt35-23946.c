//FormAI DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERNAME_LEN 20
#define MAX_PASSWORD_LEN 20

/* Function to validate the username */
int validate_username(char *username)
{
    int i, len=strlen(username);
    if (len > MAX_USERNAME_LEN)
        return 0;
    for (i=0; i<len; ++i)
        if (!isalnum(username[i]))
            return 0;
    return 1;
}

/* Function to validate the password */
int validate_password(char *password)
{
    int i, len=strlen(password), has_upper=0, has_lower=0, has_digit=0;
    if (len > MAX_PASSWORD_LEN)
        return 0;
    for (i=0; i<len; ++i)
    {
        if (isupper(password[i]))
            has_upper = 1;
        else if (islower(password[i]))
            has_lower = 1;
        else if (isdigit(password[i]))
            has_digit = 1;
        else
            return 0; /* Non-alphanumeric character */
    }
    return has_upper && has_lower && has_digit;
}

int main()
{
    char username[MAX_USERNAME_LEN+1], password[MAX_PASSWORD_LEN+1];
    int i, n;

    printf("Enter number of accounts: ");
    scanf("%d", &n);

    /* Allocate memory for the accounts */
    char **usernames = (char **) malloc(sizeof(char *) * n);
    char **passwords = (char **) malloc(sizeof(char *) * n);

    /* Read in the accounts */
    for (i=0; i<n; ++i)
    {
        printf("Account %d\n", i+1);
        printf("Enter username: ");
        scanf("%s", username);
        while (!validate_username(username))
        {
            printf("Invalid username! Must be alphanumeric and no more than %d characters long.\n", MAX_USERNAME_LEN);
            printf("Enter username: ");
            scanf("%s", username);
        }

        printf("Enter password: ");
        scanf("%s", password);
        while (!validate_password(password))
        {
            printf("Invalid password! Must be between 8 and 20 characters long and contain at least one uppercase letter, one lowercase letter, and one digit.\n");
            printf("Enter password: ");
            scanf("%s", password);
        }

        /* Store the account */
        usernames[i] = strdup(username);
        passwords[i] = strdup(password);
    }

    /* Display the accounts */
    printf("\n\nYour accounts:\n");
    for (i=0; i<n; ++i)
        printf("%-20s %s\n", usernames[i], passwords[i]);

    /* Free memory */
    for (i=0; i<n; ++i)
    {
        free(usernames[i]);
        free(passwords[i]);
    }
    free(usernames);
    free(passwords);
    
    return 0;
}
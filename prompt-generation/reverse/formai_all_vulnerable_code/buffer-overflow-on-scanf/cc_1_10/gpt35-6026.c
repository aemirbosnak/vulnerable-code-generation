//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function prototypes */
int checkLength(char *password);
int checkUppercase(char *password);
int checkLowercase(char *password);
int checkDigits(char *password);
int checkSpecial(char *password);

int main()
{
    char password[100];

    printf("Enter the password: ");
    scanf("%s", password);

    int length = checkLength(password);
    int uppercase = checkUppercase(password);
    int lowercase = checkLowercase(password);
    int digits = checkDigits(password);
    int special = checkSpecial(password);

    int strength = length + uppercase + lowercase + digits + special;

    if (strength < 5)
    {
        printf("Your password is very weak.\n");
    }
    else if (strength < 8)
    {
        printf("Your password is weak.\n");
    }
    else if (strength < 10)
    {
        printf("Your password is medium.\n");
    }
    else
    {
        printf("Your password is strong.\n");
    }

    return 0;
}

/* Check the length of the password */
int checkLength(char *password)
{
    int length = strlen(password);

    if (length < 8)
    {
        printf("Password length should be at least 8 characters.\n");
        return 0;
    }

    return 1;
}

/* Check if there is at least one uppercase letter */
int checkUppercase(char *password)
{
    int i;
    int length = strlen(password);

    for (i = 0; i < length; i++)
    {
        if (isupper(password[i]))
        {
            return 1;
        }
    }

    printf("Password should contain at least one uppercase letter.\n");
    return 0;
}

/* Check if there is at least one lowercase letter */
int checkLowercase(char *password)
{
    int i;
    int length = strlen(password);

    for (i = 0; i < length; i++)
    {
        if (islower(password[i]))
        {
            return 1;
        }
    }

    printf("Password should contain at least one lowercase letter.\n");
    return 0;
}

/* Check if there is at least one digit */
int checkDigits(char *password)
{
    int i;
    int length = strlen(password);

    for (i = 0; i < length; i++)
    {
        if (isdigit(password[i]))
        {
            return 1;
        }
    }

    printf("Password should contain at least one digit.\n");
    return 0;
}

/* Check if there is at least one special character */
int checkSpecial(char *password)
{
    int i;
    int length = strlen(password);

    for (i = 0; i < length; i++)
    {
        if (!isalnum(password[i]))
        {
            return 1;
        }
    }

    printf("Password should contain at least one special character.\n");
    return 0;
}
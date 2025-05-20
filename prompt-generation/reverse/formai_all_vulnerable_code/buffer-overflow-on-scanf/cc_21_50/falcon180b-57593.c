//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char password[100];
    int length, uppercase, lowercase, number, special;
    char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *lower = "abcdefghijklmnopqrstuvwxyz";
    char *numbers = "0123456789";
    char *specials = "!@#$%^&*()_+-=~`[]{}|;:,.<>?";
    char *all = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=~`[]{}|;:,.<>?";

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);
    uppercase = 0;
    lowercase = 0;
    number = 0;
    special = 0;

    for (int i = 0; i < length; i++)
    {
        if (isupper(password[i]))
        {
            uppercase = 1;
        }
        else if (islower(password[i]))
        {
            lowercase = 1;
        }
        else if (isdigit(password[i]))
        {
            number = 1;
        }
        else if (strchr(specials, password[i])!= NULL)
        {
            special = 1;
        }
    }

    if (length < 8)
    {
        printf("Weak password. Password must be at least 8 characters long.\n");
    }
    else if (uppercase == 0 && lowercase == 0 && number == 0 && special == 0)
    {
        printf("Weak password. Password must contain at least one uppercase letter, one lowercase letter, one number, and one special character.\n");
    }
    else if (length >= 8 && (uppercase == 1 || lowercase == 1 || number == 1 || special == 1))
    {
        printf("Moderate password strength.\n");
    }
    else if (length >= 12 && (uppercase == 1 && lowercase == 1 && number == 1 && special == 1))
    {
        printf("Strong password strength.\n");
    }
    else
    {
        printf("Very strong password strength.\n");
    }

    return 0;
}
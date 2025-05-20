//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];
    int length, i, specialChars = 0, digits = 0, upperCase = 0, lowerCase = 0;

    printf("Enter a password to check its strength: ");
    scanf("%s", password);

    length = strlen(password);

    // Check for special characters
    for (i = 0; i < length; i++)
    {
        if (!isalnum(password[i]))
        {
            specialChars = 1;
            break;
        }
    }

    // Check for digits
    for (i = 0; i < length; i++)
    {
        if (isdigit(password[i]))
        {
            digits++;
        }
    }

    // Check for uppercase letters
    for (i = 0; i < length; i++)
    {
        if (isupper(password[i]))
        {
            upperCase++;
        }
    }

    // Check for lowercase letters
    for (i = 0; i < length; i++)
    {
        if (islower(password[i]))
        {
            lowerCase++;
        }
    }

    if (length < 8)
    {
        printf("Weak password. Password should be at least 8 characters long.\n");
    }
    else if (length >= 8 && length < 14 && specialChars && digits && upperCase && lowerCase)
    {
        printf("Good password.\n");
    }
    else if (length >= 14 && specialChars && digits && upperCase && lowerCase)
    {
        printf("Strong password.\n");
    }
    else
    {
        printf("Weak password. Password should contain at least one special character, one digit, one uppercase letter and one lowercase letter.\n");
    }

    return 0;
}
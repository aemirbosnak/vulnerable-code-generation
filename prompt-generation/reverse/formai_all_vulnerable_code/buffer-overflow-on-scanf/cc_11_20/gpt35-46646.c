//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[30];
    int length, has_uppercase, has_lowercase, has_digit, has_special, score;

    printf("Please enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    has_uppercase = has_lowercase = has_digit = has_special = 0;

    for (int i = 0; i < length; i++)
    {
        if (isupper(password[i]))
        {
            has_uppercase = 1;
        }
        else if (islower(password[i]))
        {
            has_lowercase = 1;
        }
        else if (isdigit(password[i]))
        {
            has_digit = 1;
        }
        else
        {
            has_special = 1;
        }
    }

    score = has_uppercase + has_lowercase + has_digit + has_special;

    if (length >= 6 && length <= 8 && score == 2)
    {
        printf("Password strength: Weak");
    }
    else if (length > 8 && score == 3)
    {
        printf("Password strength: Moderate");
    }
    else if (length > 8 && score == 4)
    {
        printf("Password strength: Strong");
    }
    else
    {
        printf("Password strength: Very weak");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 15
#define TRUE 1
#define FALSE 0

int main()
{
    char password[LENGTH];
    int password_length, upper_case = FALSE, lower_case = FALSE,
        digit = FALSE, special_char = FALSE;

    printf("\nEnter a password (max 15 characters): ");
    scanf("%s", password);

    // Password length validation
    password_length = strlen(password);
    if (password_length < 6)
    {
        printf("\nPassword must be at least 6 characters long.\n");
        return 0;
    }

    // Password strength check
    for (int i = 0; i < password_length; i++)
    {
        if (isupper(password[i]))
        {
            upper_case = TRUE;
        }
        else if (islower(password[i]))
        {
            lower_case = TRUE;
        }
        else if (isdigit(password[i]))
        {
            digit = TRUE;
        }
        else
        {
            special_char = TRUE;
        }
    }

    // Password strength assessment and output
    if (upper_case && lower_case && digit && special_char)
    {
        printf("\nStrong Password!\n");
    }
    else if ((upper_case || lower_case) && digit && special_char)
    {
        printf("\nModerately Strong Password!\n");
    }
    else
    {
        printf("\nWeak Password!\n");
    }

    return 0;
}
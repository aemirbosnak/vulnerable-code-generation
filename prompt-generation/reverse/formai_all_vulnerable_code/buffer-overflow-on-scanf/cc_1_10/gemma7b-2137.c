//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_password_strength(char *password)
{
    int password_length = strlen(password);
    int has_upper_case = 0;
    int has_lower_case = 0;
    int has_number = 0;
    int has_symbol = 0;

    for (int i = 0; i < password_length; i++)
    {
        if (isupper(password[i]))
        {
            has_upper_case = 1;
        }
        else if (islower(password[i]))
        {
            has_lower_case = 1;
        }
        else if (isdigit(password[i]))
        {
            has_number = 1;
        }
        else if (ispunct(password[i]))
        {
            has_symbol = 1;
        }
    }

    if (has_upper_case && has_lower_case && has_number && has_symbol)
    {
        printf("Password strength: Strong\n");
    }
    else
    {
        printf("Password strength: Weak\n");
    }
}

int main()
{
    char password[256];

    printf("Enter your password: ");
    scanf("%s", password);

    check_password_strength(password);

    return 0;
}
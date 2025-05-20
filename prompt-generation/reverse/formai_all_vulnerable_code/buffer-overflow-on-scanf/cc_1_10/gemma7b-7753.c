//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void check_password_strength(char *password)
{
    int strength = 0;
    char lower_case = 0, upper_case = 0, number = 0, symbol = 0;

    // Check for lower case letter
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            lower_case = 1;
        }
    }

    // Check for upper case letter
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            upper_case = 1;
        }
    }

    // Check for number
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            number = 1;
        }
    }

    // Check for symbol
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= '!' && password[i] <= '~')
        {
            symbol = 1;
        }
    }

    // Calculate strength
    strength = lower_case + upper_case + number + symbol;

    // Print strength
    printf("Password Strength: %d/%d\n", strength, 4);
}

int main()
{
    char password[20];

    printf("Enter password: ");
    scanf("%s", password);

    check_password_strength(password);

    return 0;
}
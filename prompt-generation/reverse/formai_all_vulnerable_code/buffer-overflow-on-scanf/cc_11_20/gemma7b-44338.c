//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strength_check(char *pass)
{
    int length = strlen(pass);
    int score = 0;
    char upper_case = 0, lower_case = 0, number = 0, symbol = 0;

    // Check for uppercase letter
    for (int i = 0; i < length; i++)
    {
        if (pass[i] >= 'A' && pass[i] <= 'Z')
        {
            upper_case = 1;
        }
    }

    // Check for lowercase letter
    for (int i = 0; i < length; i++)
    {
        if (pass[i] >= 'a' && pass[i] <= 'z')
        {
            lower_case = 1;
        }
    }

    // Check for number
    for (int i = 0; i < length; i++)
    {
        if (pass[i] >= '0' && pass[i] <= '9')
        {
            number = 1;
        }
    }

    // Check for symbol
    for (int i = 0; i < length; i++)
    {
        if (pass[i] >= '!' && pass[i] <= '~')
        {
            symbol = 1;
        }
    }

    // Calculate score
    if (upper_case && lower_case && number && symbol)
    {
        score = 100;
    }
    else if (upper_case || lower_case || number || symbol)
    {
        score = 75;
    }
    else
    {
        score = 50;
    }

    // Print score
    printf("Password Strength: %d%%", score);
}

int main()
{
    char pass[20];

    printf("Enter your password: ");
    scanf("%s", pass);

    strength_check(pass);

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AnalyzePassword(char *password)
{
    int length = strlen(password);
    char upperCase = 0, lowerCase = 0, number = 0, symbol = 0;

    // Check for uppercase letter
    for (int i = 0; i < length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            upperCase = 1;
        }
    }

    // Check for lowercase letter
    for (int i = 0; i < length; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            lowerCase = 1;
        }
    }

    // Check for number
    for (int i = 0; i < length; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            number = 1;
        }
    }

    // Check for symbol
    for (int i = 0; i < length; i++)
    {
        if (password[i] >= '!' && password[i] <= '~')
        {
            symbol = 1;
        }
    }

    // Print results
    printf("Password Analysis:\n");
    printf("--------------------\n");
    printf("Length: %d\n", length);
    printf("Uppercase Letter: %c\n", upperCase);
    printf("Lowercase Letter: %c\n", lowerCase);
    printf("Number: %c\n", number);
    printf("Symbol: %c\n", symbol);

    if (upperCase && lowerCase && number && symbol)
    {
        printf("Strength: Strong\n");
    }
    else
    {
        printf("Strength: Weak\n");
    }
}

int main()
{
    char password[256];

    printf("Enter your password: ");
    scanf("%s", password);

    AnalyzePassword(password);

    return 0;
}
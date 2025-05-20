//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: statistical
#include <stdio.h>
#include <string.h>

int main()
{
    char password[50];
    int length, i;
    int uppercase = 0, lowercase = 0, digits = 0, symbols = 0;
    int score = 0;

    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);

    for(i = 0; i < length; i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
            uppercase++;

        else if(password[i] >= 'a' && password[i] <= 'z')
            lowercase++;

        else if(password[i] >= '0' && password[i] <= '9')
            digits++;

        else
            symbols++;
    }

    if(length < 8)
    {
        printf("Password length is weak\n");
        return 0;
    }

    // Checking for uppercase character
    if(uppercase == 0)
    {
        printf("No uppercase characters found in password.\n");
        score -= 20;
    }

    //Checking for lowercase character
    if(lowercase == 0)
    {
        printf("No lowercase characters found in password.\n");
        score -= 20;
    }

    //Checking for digits
    if(digits == 0)
    {
        printf("No digits found in password.\n");
        score -= 20;
    }

    //Checking for symbols
    if(symbols == 0)
    {
        printf("No symbols found in password.\n");
        score -= 20;
    }

    //Assigning the score based on the length of password
    if(length >= 8 && length < 12)
    {
        score += 10;
    }
    else if(length >= 12 && length <= 20)
    {
        score += 20;
    }
    else
    {
        score += 30;
    }

    // Displaying the password strength
    if(score >= 70)
    {
        printf("Password is very strong\n");
    }
    else if(score >= 50 && score < 70)
    {
        printf("Password is strong\n");
    }
    else if(score >= 30 && score < 50)
    {
        printf("Password is weak\n");
    }
    else if(score >= 0 && score < 30)
    {
        printf("Password is very weak\n");
    }

    return 0;
}
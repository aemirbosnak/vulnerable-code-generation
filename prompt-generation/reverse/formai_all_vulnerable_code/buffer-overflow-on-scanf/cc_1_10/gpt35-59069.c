//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int score_password(char *password);

int main()
{
    char password[50];

    printf("Enter your password: ");
    scanf("%s", password);

    int password_strength = score_password(password);

    if(password_strength >= 8)
    {
        printf("Strong Password\n");
    }
    else if(password_strength >= 5 && password_strength <= 7)
    {
        printf("Moderate Password\n");
    }
    else
    {
        printf("Weak Password\n");
    }

    return 0;
}

int score_password(char *password)
{
    int length = strlen(password);

    int upper = 0, lower = 0, digit = 0, special = 0;
    int i;

    for(i = 0; i < length; i++)
    {
        if(isupper(password[i]))
        {
            upper = 1;
        }
        else if(islower(password[i]))
        {
            lower = 1;
        }
        else if(isdigit(password[i]))
        {
            digit = 1;
        }
        else
        {
            special = 1;
        }
    }

    int password_strength = upper + lower + digit + special;

    if(length < 6)
    {
        password_strength--;
    }

    if(password_strength < 0)
    {
        password_strength = 0;
    }

    return password_strength;
}
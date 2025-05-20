//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *check_strength(char *pass)
{
    int min_length = 8;
    int has_number = 0;
    int has_letter = 0;
    int has_symbol = 0;
    char *message = NULL;

    if (strlen(pass) < min_length)
    {
        message = "Password too short!";
    }
    else if (!has_number)
    {
        message = "Password needs a number!";
    }
    else if (!has_letter)
    {
        message = "Password needs a letter!";
    }
    else if (!has_symbol)
    {
        message = "Password needs a symbol!";
    }

    return message;
}

int main()
{
    char password[256];
    char *message = NULL;

    printf("Enter your password: ");
    scanf("%s", password);

    message = check_strength(password);

    if (message)
    {
        printf("%s\n", message);
    }
    else
    {
        printf("Password is strong!\n");
    }

    return 0;
}
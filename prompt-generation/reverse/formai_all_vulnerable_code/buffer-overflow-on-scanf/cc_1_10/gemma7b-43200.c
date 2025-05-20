//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PASSWD_LENGTH 255

int main()
{
    char password[MAX_PASSWD_LENGTH];
    int password_length;
    int strength;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    strength = check_password_strength(password, password_length);

    switch (strength)
    {
        case 0:
            printf("Your password is weak. Please choose a stronger password.\n");
            break;
        case 1:
            printf("Your password is fair. It may be acceptable, but could be improved.\n");
            break;
        case 2:
            printf("Your password is good. It is strong enough for most purposes.\n");
            break;
        case 3:
            printf("Your password is excellent. It is very strong and difficult to crack.\n");
            break;
    }

    return 0;
}

int check_password_strength(char *password, int password_length)
{
    int strength = 0;
    int has_upper = 0;
    int has_lower = 0;
    int has_number = 0;
    int has_symbol = 0;

    for (int i = 0; i < password_length; i++)
    {
        char current_char = password[i];

        if (isupper(current_char))
        {
            has_upper = 1;
        }
        else if (islower(current_char))
        {
            has_lower = 1;
        }
        else if (isdigit(current_char))
        {
            has_number = 1;
        }
        else if (ispunct(current_char))
        {
            has_symbol = 1;
        }
    }

    if (has_upper && has_lower && has_number && has_symbol)
    {
        strength = 3;
    }
    else if (has_upper || has_lower || has_number || has_symbol)
    {
        strength = 2;
    }
    else
    {
        strength = 0;
    }

    return strength;
}
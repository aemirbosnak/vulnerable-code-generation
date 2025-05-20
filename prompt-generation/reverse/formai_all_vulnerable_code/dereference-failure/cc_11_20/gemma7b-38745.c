//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{

    time_t t = time(NULL);
    srand(t);

    // Generate a random password
    char password[16] = "";
    for (int i = 0; i < 16; i++)
    {
        password[i] = (rand() % 2) ? 'a' + rand() % 26 : '0' + rand() % 10;
    }

    // Print the password
    printf("Your password is: %s\n", password);

    // Check if the password is strong
    int strength = check_password_strength(password);
    switch (strength)
    {
        case 0:
            printf("Your password is weak.\n");
            break;
        case 1:
            printf("Your password is medium.\n");
            break;
        case 2:
            printf("Your password is strong.\n");
            break;
        case 3:
            printf("Your password is very strong.\n");
            break;
    }

    return 0;
}

int check_password_strength(char *password)
{

    int length = strlen(password);
    int has_numbers = 0, has_letters = 0, has_symbols = 0;

    for (int i = 0; i < length; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            has_letters = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            has_numbers = 1;
        }
        else if (password[i] >= '!' && password[i] <= '~')
        {
            has_symbols = 1;
        }
    }

    if (length >= 12 && has_numbers && has_letters && has_symbols)
    {
        return 3;
    }
    else if (length >= 8 && has_numbers && has_letters)
    {
        return 2;
    }
    else if (length >= 6 && has_numbers || has_letters)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
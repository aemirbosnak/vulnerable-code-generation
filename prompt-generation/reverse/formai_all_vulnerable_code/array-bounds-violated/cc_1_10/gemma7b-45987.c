//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 256

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;

    printf("Enter your password: ");
    getline(stdin, password, MAX_PASSWORD_LENGTH);

    password_length = strlen(password);

    if (password_length < 8)
    {
        printf("Your password is too short.\n");
    }
    else if (password_length > 24)
    {
        printf("Your password is too long.\n");
    }
    else if (!isupper(password[0]) && !islower(password[0]) && !isdigit(password[0]))
    {
        printf("Your password must start with a letter or number.\n");
    }
    else if (!isalnum(password[password_length - 1]))
    {
        printf("Your password must end with a letter or number.\n");
    }
    else if (hasRepeatCharacters(password))
    {
        printf("Your password has repeated characters.\n");
    }
    else
    {
        printf("Your password is strong.\n");
    }

    return 0;
}

int hasRepeatCharacters(char *password)
{
    int i, j, character_count[256] = {0};

    for (i = 0; password[i] != '\0'; i++)
    {
        character_count[password[i]]++;
    }

    for (j = 0; character_count[j] > 1; j++)
    {
        return 1;
    }

    return 0;
}
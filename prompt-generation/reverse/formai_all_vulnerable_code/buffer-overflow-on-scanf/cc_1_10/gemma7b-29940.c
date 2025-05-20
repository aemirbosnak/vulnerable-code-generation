//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PASSWORD_MAX_LENGTH 256

int main()
{
    char password[PASSWORD_MAX_LENGTH];
    int password_length;

    system("/bin/clear");

    printf("Enter a password: ");
    scanf("%s", password);
    password_length = strlen(password);

    if (password_length < 8)
    {
        printf("Password too short. Minimum 8 characters required.\n");
        exit(1);
    }

    if (!isupper(password[0]))
    {
        printf("Password must start with an uppercase letter.\n");
        exit(1);
    }

    if (!islower(password[password_length - 1]))
    {
        printf("Password must end with a lowercase letter.\n");
        exit(1);
    }

    if (check_password_complexity(password) == 0)
    {
        printf("Password not complex enough. Please use a combination of uppercase and lowercase letters, numbers, and symbols.\n");
        exit(1);
    }

    printf("Password acceptable.\n");

    return 0;
}

int check_password_complexity(char *password)
{
    int i;
    int complexity = 1;

    for (i = 0; password[i] != '\0'; i++)
    {
        if (!isalnum(password[i]) && password[i] != '$' && password[i] != '#')
        {
            complexity = 0;
        }
    }

    return complexity;
}
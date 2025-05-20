//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define PASSWORD_MINIMUM_LENGTH 8

int main()
{
    char password[PASSWORD_MINIMUM_LENGTH];
    int password_length = 0;
    int strength = 0;

    printf("Enter password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Calculate password strength
    if (password_length >= PASSWORD_MINIMUM_LENGTH)
    {
        strength = strength + 1;
    }
    if (strstr(password, "!") || strstr(password, "@") || strstr(password, "$") || strstr(password, "%"))
    {
        strength = strength + 1;
    }
    if (strstr(password, "a") || strstr(password, "e") || strstr(password, "i") || strstr(password, "o") || strstr(password, "u"))
    {
        strength = strength + 1;
    }
    if (strength == 3)
    {
        printf("Password strength: Very strong\n");
    }
    else if (strength == 2)
    {
        printf("Password strength: Moderate\n");
    }
    else if (strength == 1)
    {
        printf("Password strength: Weak\n");
    }
    else
    {
        printf("Invalid password\n");
    }

    return 0;
}
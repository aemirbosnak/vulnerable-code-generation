//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: introspective
#include <stdio.h>
#include <string.h>

// Function to check password strength
int isPasswordStrong(char *password)
{
    int len = strlen(password);
    int uppercase = 0;
    int lowercase = 0;
    int digit = 0;
    int special = 0;
    int minLength = 8;
    int maxLength = 16;

    // Check length
    if (len < minLength || len > maxLength)
        return 0;

    // Check for at least one uppercase letter
    if (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", password[0]) == NULL)
        return 0;
    uppercase++;

    // Check for at least one lowercase letter
    if (strchr("abcdefghijklmnopqrstuvwxyz", password[0]) == NULL)
        return 0;
    lowercase++;

    // Check for at least one digit
    if (strchr("0123456789", password[0]) == NULL)
        return 0;
    digit++;

    // Check for at least one special character
    if (strchr("!@#$%^&*()-+", password[0]) == NULL)
        return 0;
    special++;

    return 1;
}

int main()
{
    char password[20];
    printf("Enter your password: ");
    scanf("%s", password);
    if (isPasswordStrong(password))
        printf("Password is strong.\n");
    else
        printf("Password is weak.\n");
    return 0;
}
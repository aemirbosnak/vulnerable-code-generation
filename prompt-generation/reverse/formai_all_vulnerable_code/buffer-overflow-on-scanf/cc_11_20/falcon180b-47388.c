//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: funny
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH 8
#define MIN_LENGTH_PASSWORD 8
#define MAX_LENGTH_PASSWORD 16
#define MIN_NUMERIC_CHARS 1
#define MIN_SPECIAL_CHARS 1
#define MIN_UPPERCASE_CHARS 1
#define MIN_LOWERCASE_CHARS 1

int main()
{
    char password[PASSWORD_LENGTH + 1] = {0};
    int length = 0;
    int numeric_chars = 0;
    int special_chars = 0;
    int uppercase_chars = 0;
    int lowercase_chars = 0;

    // Get password input from user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) < MIN_LENGTH_PASSWORD || strlen(password) > MAX_LENGTH_PASSWORD)
    {
        printf("Password length must be between %d and %d characters.\n", MIN_LENGTH_PASSWORD, MAX_LENGTH_PASSWORD);
        return 1;
    }

    // Check numeric characters
    for (int i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            numeric_chars++;
        }
    }
    if (numeric_chars < MIN_NUMERIC_CHARS)
    {
        printf("Password must contain at least %d numeric characters.\n", MIN_NUMERIC_CHARS);
        return 1;
    }

    // Check special characters
    for (int i = 0; i < strlen(password); i++)
    {
        if (!isalnum(password[i]))
        {
            special_chars++;
        }
    }
    if (special_chars < MIN_SPECIAL_CHARS)
    {
        printf("Password must contain at least %d special characters.\n", MIN_SPECIAL_CHARS);
        return 1;
    }

    // Check uppercase characters
    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            uppercase_chars++;
        }
    }
    if (uppercase_chars < MIN_UPPERCASE_CHARS)
    {
        printf("Password must contain at least %d uppercase characters.\n", MIN_UPPERCASE_CHARS);
        return 1;
    }

    // Check lowercase characters
    for (int i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            lowercase_chars++;
        }
    }
    if (lowercase_chars < MIN_LOWERCASE_CHARS)
    {
        printf("Password must contain at least %d lowercase characters.\n", MIN_LOWERCASE_CHARS);
        return 1;
    }

    // Password is strong enough
    printf("Your password is strong enough.\n");
    return 0;
}
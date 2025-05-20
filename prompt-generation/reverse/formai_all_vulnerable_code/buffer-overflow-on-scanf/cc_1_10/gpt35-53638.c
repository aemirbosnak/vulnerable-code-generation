//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: complex
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//function declarations
int passwordLengthCheck(char *);
int passwordStrengthCheck(char *);
int upperCaseCheck(char *);
int lowerCaseCheck(char *);
int digitCheck(char *);

int main()
{
    char password[50];
    int length_check, strength_check, upper_check, lower_check, digit_check;

    printf("Enter a password: ");
    scanf("%s", password);

    //validating the password strength
    length_check = passwordLengthCheck(password);
    strength_check = passwordStrengthCheck(password);
    upper_check = upperCaseCheck(password);
    lower_check = lowerCaseCheck(password);
    digit_check = digitCheck(password);

    //password is secure
    if (length_check && strength_check && upper_check && lower_check && digit_check)
    {
        printf("The password is secure and strong!");
    }
    else
    {
        printf("The password is not secure and strong!");
    }

    return 0;
}

//function to check password length
int passwordLengthCheck(char *password)
{
    if (strlen(password) >= 8)
    {
        return 1;
    }
    else
    {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }
}

//function to check password strength
int passwordStrengthCheck(char *password)
{
    int count = 0;
    for (int i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            count++;
            break;
        }
    }

    for (int i = 0; i < strlen(password); i++)
    {
        if (isalpha(password[i]))
        {
            count++;
            break;
        }
    }

    if (count == 2)
    {
        return 1;
    }
    else
    {
        printf("Password must contain at least one digit and one letter.\n");
        return 0;
    }
}

//function to check if password contains at least one UPPERCASE
int upperCaseCheck(char *password)
{
    int count = 0;
    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            count++;
            break;
        }
    }

    if (count == 1)
    {
        return 1;
    }
    else
    {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }
}

//function to check if password contains at least one lowercase
int lowerCaseCheck(char *password)
{
    int count = 0;
    for (int i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            count++;
            break;
        }
    }

    if (count == 1)
    {
        return 1;
    }
    else
    {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }
}

//function to check if password contains at least one digit
int digitCheck(char *password)
{
    int count = 0;
    for (int i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            count++;
            break;
        }
    }

    if (count == 1)
    {
        return 1;
    }
    else
    {
        printf("Password must contain at least one digit.\n");
        return 0;
    }
}
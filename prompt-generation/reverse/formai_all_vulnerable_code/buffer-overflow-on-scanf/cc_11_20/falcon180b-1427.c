//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32

/* Function to check if the given character is an alphabet */
int isAlpha(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        return 1;
    else
        return 0;
}

/* Function to check if the given character is a digit */
int isDigit(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

/* Function to check if the given character is a special character */
int isSpecial(char ch)
{
    if (ch == '!' || ch == '@' || ch == '#' || ch == '$' || ch == '%'
        || ch == '^' || ch == '&' || ch == '*' || ch == '(' || ch == ')'
        || ch == '-' || ch == '_' || ch == '+' || ch == '=' || ch == '{'
        || ch == '}' || ch == '[' || ch == ']' || ch == '|' || ch == '~'
        || ch == ';' || ch == ':' || ch == '"' || ch == '\'' || ch == '<'
        || ch == '>' || ch == ',' || ch == '.' || ch == '?' || ch == '/')
        return 1;
    else
        return 0;
}

/* Function to check the strength of the password */
void checkPasswordStrength(char *password)
{
    int length = strlen(password);
    int hasAlpha = 0, hasDigit = 0, hasSpecial = 0;

    if (length < MIN_LENGTH || length > MAX_LENGTH)
        printf("Password length should be between %d and %d characters.\n", MIN_LENGTH, MAX_LENGTH);
    else if (!isAlpha(password[0]))
        printf("Password should start with an alphabet.\n");
    else if (!isAlpha(password[length - 1]))
        printf("Password should end with an alphabet.\n");
    else if (!isDigit(password[length - 1]))
        printf("Password should end with a digit.\n");
    else if (!isSpecial(password[length - 1]))
        printf("Password should end with a special character.\n");
    else if (length == 1)
        printf("Password is very weak.\n");
    else if (length == 2)
        printf("Password is weak.\n");
    else if (length == 3)
        printf("Password is moderate.\n");
    else if (length == 4)
        printf("Password is strong.\n");
    else if (length >= 5)
        printf("Password is very strong.\n");

    if (hasAlpha && hasDigit && hasSpecial)
        printf("Password contains all types of characters.\n");
    else if (hasAlpha && hasDigit)
        printf("Password contains alphabets and digits.\n");
    else if (hasAlpha && hasSpecial)
        printf("Password contains alphabets and special characters.\n");
    else if (hasDigit && hasSpecial)
        printf("Password contains digits and special characters.\n");
    else
        printf("Password contains only one type of characters.\n");
}

int main()
{
    char password[MAX_LENGTH];

    printf("Enter the password to check its strength: ");
    scanf("%s", password);

    checkPasswordStrength(password);

    return 0;
}
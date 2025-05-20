//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int isPasswordStrong(char* password);

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter thy password: ");
    scanf("%s", password);

    if (isPasswordStrong(password))
    {
        printf("Thy password is strong as a castle wall!\n");
    }
    else
    {
        printf("Thy password is weak as a peasant's hut!\n");
    }

    return 0;
}

int isPasswordStrong(char* password)
{
    int length = strlen(password);
    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasNumber = 0;
    int hasSpecialChar = 0;

    for (int i = 0; i < length; i++)
    {
        if (isupper(password[i]))
        {
            hasUppercase = 1;
        }
        else if (islower(password[i]))
        {
            hasLowercase = 1;
        }
        else if (isdigit(password[i]))
        {
            hasNumber = 1;
        }
        else if (!isalnum(password[i]))
        {
            hasSpecialChar = 1;
        }
    }

    if (length >= 8 && hasUppercase && hasLowercase && hasNumber && hasSpecialChar)
    {
        return 1;
    }

    return 0;
}
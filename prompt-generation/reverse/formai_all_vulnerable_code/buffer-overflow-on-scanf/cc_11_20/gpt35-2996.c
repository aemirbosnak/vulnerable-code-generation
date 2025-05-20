//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);
    int length = strlen(password);

    int uppercase = 0, lowercase = 0, digits = 0, special_char = 0;

    for (int i = 0; i < length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            uppercase++;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            lowercase++;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            digits++;
        }
        else
        {
            special_char++;
        }
    }

    if (length < 8)
    {
        printf("Your password is weak! The password length is less than 8 characters\n");
        printf("Please choose a new password with at least 8 characters.\n");
    }
    else if (uppercase == 0 || lowercase == 0)
    {
        printf("Your password is weak! The password must contain at least one uppercase letter and one lowercase letter.\n");
        printf("Please choose a new password with at least one uppercase letter and one lowercase letter.\n");
    }
    else if (digits == 0)
    {
        printf("Your password is weak! The password must contain at least one digit.\n");
        printf("Please choose a new password with at least one digit.\n");
    }
    else if (special_char == 0)
    {
        printf("Your password is weak! The password must contain at least one special character.\n");
        printf("Please choose a new password with at least one special character.\n");
    }
    else
    {
        printf("Your password is strong! Congratulations!\n");
    }

    return 0;
}
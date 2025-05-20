//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check password strength
void check_password_strength(char password[])
{
    int n = strlen(password);
    int has_lower_case = 0, has_upper_case = 0, has_digit = 0, has_special_char = 0;

    for (int i = 0; i < n; i++)
    {
        char ch = password[i];
        if (islower(ch))
        {
            has_lower_case = 1;
        }
        else if (isupper(ch))
        {
            has_upper_case = 1;
        }
        else if (isdigit(ch))
        {
            has_digit = 1;
        }
        else
        {
            has_special_char = 1;
        }
    }

    if (n < 8 || n > 20)
    {
        printf("Password length should be between 8 and 20 characters\n");
    }
    else if (!(has_lower_case && has_upper_case))
    {
        printf("Password should contain at least one lowercase and one uppercase letter.\n");
    }
    else if (!has_digit)
    {
        printf("Password should contain at least one digit.\n");
    }
    else if (!has_special_char)
    {
        printf("Password should contain at least one special character.\n");
    }
    else
    {
        printf("Password is strong!\n");
    }
}

int main()
{
    char password[50];
    printf("Enter your password: ");
    scanf("%[^\n]", password);

    check_password_strength(password);

    return 0;
}
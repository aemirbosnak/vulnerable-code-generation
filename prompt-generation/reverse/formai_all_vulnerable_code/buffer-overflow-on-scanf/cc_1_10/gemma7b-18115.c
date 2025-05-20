//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASS_LEN 1024

int main()
{
    char pass[MAX_PASS_LEN];
    int pass_len = 0;

    // Get the password from the user
    printf("Enter a password: ");
    scanf("%s", pass);

    // Calculate the password length
    pass_len = strlen(pass);

    // Check if the password meets the strength requirements
    if (pass_len < 8)
    {
        printf("Error: Password is too short.\n");
    }
    else if (pass_len > 24)
    {
        printf("Error: Password is too long.\n");
    }
    else if (!isupper(pass[0]) && !isdigit(pass[0]))
    {
        printf("Error: Password must start with an uppercase letter or a number.\n");
    }
    else if (!containsSpecialChars(pass))
    {
        printf("Error: Password must contain a special character.\n");
    }
    else
    {
        printf("Password is strong.\n");
    }

    return 0;
}

int containsSpecialChars(char *pass)
{
    char special_chars[] = "!@#$%^&*()_+-={}[]|\\:";

    for (int i = 0; i < strlen(pass); i++)
    {
        for (int j = 0; j < strlen(special_chars); j++)
        {
            if (pass[i] == special_chars[j])
            {
                return 1;
            }
        }
    }

    return 0;
}
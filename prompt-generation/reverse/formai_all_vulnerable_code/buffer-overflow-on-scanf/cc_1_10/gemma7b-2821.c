//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASS_LEN 256

void check_password_strength(char *pass)
{
    int pass_len = strlen(pass);
    int has_num = 0, has_upper = 0, has_lower = 0, has_symbol = 0;

    if (pass_len < 8)
    {
        printf("Password too short! Minimum 8 characters required.\n");
        return;
    }

    for (int i = 0; i < pass_len; i++)
    {
        if (pass[i] >= '0' && pass[i] <= '9')
            has_num = 1;
        else if (pass[i] >= 'A' && pass[i] <= 'Z')
            has_upper = 1;
        else if (pass[i] >= 'a' && pass[i] <= 'z')
            has_lower = 1;
        else if (pass[i] >= '!' && pass[i] <= '@')
            has_symbol = 1;
    }

    if (has_num && has_upper && has_lower && has_symbol)
    {
        printf("Strong password!\n");
    }
    else
    {
        printf("Password not strong enough. Please use a combination of upper and lowercase letters, numbers, and symbols.\n");
    }
}

int main()
{
    char pass[MAX_PASS_LEN];

    printf("Enter your password: ");
    scanf("%s", pass);

    check_password_strength(pass);

    return 0;
}
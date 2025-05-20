//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWD_LEN 255

typedef struct PostApocalypticPassword {
    char password[MAX_PASSWD_LEN];
    int strength;
} PostApocalypticPassword;

int assess_password_strength(char *password)
{
    int strength = 0;
    int has_upper = 0;
    int has_lower = 0;
    int has_num = 0;
    int has_symbol = 0;

    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            has_upper = 1;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            has_lower = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            has_num = 1;
        }
        else if (password[i] >= '!' && password[i] <= '~')
        {
            has_symbol = 1;
        }
    }

    if (has_upper && has_lower && has_num && has_symbol)
    {
        strength = 5;
    }
    else if (has_upper || has_lower || has_num || has_symbol)
    {
        strength = 3;
    }
    else
    {
        strength = 1;
    }

    return strength;
}

int main()
{
    PostApocalypticPassword password_info;

    printf("Welcome to the Last Hope Password Generator.\n");
    printf("Please enter your desired password: ");

    scanf("%s", password_info.password);

    password_info.strength = assess_password_strength(password_info.password);

    switch (password_info.strength)
    {
        case 5:
            printf("Your password is extremely strong. You are safe.\n");
            break;
        case 3:
            printf("Your password is strong. You should be safe, but consider changing it if you have any concerns.\n");
            break;
        case 1:
            printf("Your password is weak. Please choose a stronger password.\n");
            break;
    }

    return 0;
}
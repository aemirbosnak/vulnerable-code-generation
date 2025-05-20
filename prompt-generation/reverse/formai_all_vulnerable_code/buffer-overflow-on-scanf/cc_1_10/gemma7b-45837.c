//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int password_strength(char *pass)
{
    int strength = 0;
    int i = 0;
    char ch;

    for (; pass[i] != '\0'; i++)
    {
        ch = pass[i];

        if (ch >= 'a' && ch <= 'z')
            strength++;
        else if (ch >= 'A' && ch <= 'Z')
            strength++;
        else if (ch >= '0' && ch <= '9')
            strength++;
        else if (ch == '$' || ch == '%')
            strength++;
    }

    return strength;
}

int main()
{
    char pass[20];

    printf("Enter a password: ");
    scanf("%s", pass);

    int strength = password_strength(pass);

    switch (strength)
    {
        case 0:
            printf("Password is very weak\n");
            break;
        case 1:
            printf("Password is weak\n");
            break;
        case 2:
            printf("Password is moderate\n");
            break;
        case 3:
            printf("Password is strong\n");
            break;
        case 4:
            printf("Password is very strong\n");
            break;
    }

    return 0;
}
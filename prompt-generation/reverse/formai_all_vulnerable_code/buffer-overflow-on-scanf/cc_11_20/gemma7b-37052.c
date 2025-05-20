//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[20];
    int i, strength = 0, upper = 0, lower = 0, number = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            lower++;
        else if (password[i] >= 'A' && password[i] <= 'Z')
            upper++;
        else if (password[i] >= '0' && password[i] <= '9')
            number++;
    }

    if (lower > 0)
        strength++;
    if (upper > 0)
        strength++;
    if (number > 0)
        strength++;

    switch (strength)
    {
        case 0:
            printf("Password is too weak!\n");
            break;
        case 1:
            printf("Password is weak.\n");
            break;
        case 2:
            printf("Password is moderate.\n");
            break;
        case 3:
            printf("Password is strong.\n");
            break;
        case 4:
            printf("Password is very strong.\n");
            break;
    }

    return 0;
}
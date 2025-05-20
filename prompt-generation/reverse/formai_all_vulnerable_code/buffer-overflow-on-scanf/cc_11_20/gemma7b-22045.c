//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char password[256];
    int i, strength = 0, min_length = 8, max_length = 16;
    system("/bin/clear");

    printf("Enter your password: ");
    scanf("%s", password);

    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            strength++;
        else if (password[i] >= 'A' && password[i] <= 'Z')
            strength++;
        else if (password[i] >= '0' && password[i] <= '9')
            strength++;
        else
            strength--;
    }

    if (strlen(password) < min_length || strlen(password) > max_length)
    {
        strength = -1;
    }

    switch (strength)
    {
        case -1:
            printf("Error: Password is too short or too long.\n");
            break;
        case 0:
            printf("Error: Weak password.\n");
            break;
        case 1:
            printf("Password is acceptable.\n");
            break;
        case 2:
            printf("Strong password.\n");
            break;
        case 3:
            printf("Excellent password.\n");
            break;
    }

    return 0;
}
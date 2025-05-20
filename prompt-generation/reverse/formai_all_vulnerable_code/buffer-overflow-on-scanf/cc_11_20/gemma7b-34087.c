//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void password_strength(char *pass)
{
    int strength = 0;
    int i = 0;

    for (i = 0; pass[i] != '\0'; i++)
    {
        if (pass[i] >= 'a' && pass[i] <= 'z')
            strength++;
        else if (pass[i] >= 'A' && pass[i] <= 'Z')
            strength++;
        else if (pass[i] >= '0' && pass[i] <= '9')
            strength++;
        else if (pass[i] == '$' || pass[i] == '&' || pass[i] == '*' || pass[i] == '+' || pass[i] == '-' || pass[i] == '=' || pass[i] == '|' || pass[i] == '~')
            strength++;
    }

    switch (strength)
    {
        case 0:
            printf("Your password is weak as a baby's rattle.\n");
            break;
        case 1:
            printf("Your password is as strong as a garden hose.\n");
            break;
        case 2:
            printf("Your password is as powerful as a nuclear warhead.\n");
            break;
        case 3:
            printf("Your password is as safe as Fort Knox.\n");
            break;
        case 4:
            printf("Your password is unbreakable, like the Enigma Code.\n");
            break;
    }
}

int main()
{
    char pass[20];

    printf("Enter your password: ");
    scanf("%s", pass);

    password_strength(pass);

    return 0;
}
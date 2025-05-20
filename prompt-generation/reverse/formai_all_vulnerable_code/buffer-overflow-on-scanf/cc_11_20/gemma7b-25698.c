//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[256];
    int strength = 0;
    printf("I am a wizard, my dear, and I need your most potent password...\n");
    printf("Please cast your strongest spell, one that will make my heart sing...\n");
    scanf("%s", password);

    // Analyze password strength
    for (int i = 0; password[i] != '\0'; i++)
    {
        // Uppercase letters
        if (password[i] >= 'A' && password[i] <= 'Z')
            strength++;

        // Lowercase letters
        else if (password[i] >= 'a' && password[i] <= 'z')
            strength++;

        // Numbers
        else if (password[i] >= '0' && password[i] <= '9')
            strength++;

        // Symbols
        else if (password[i] >= '!' && password[i] <= '~')
            strength++;
    }

    // Display password strength
    switch (strength)
    {
        case 0:
            printf("Your password is as weak as a troll's undergarments...try again, my dear.\n");
            break;
        case 1:
            printf("Your password is as strong as a dragon's tail...but could be better.\n");
            break;
        case 2:
            printf("Your password is as potent as a wizard's spell...bravo, my dear!\n");
            break;
        case 3:
            printf("Your password is as secure as a fortress...you are a master of secrets.\n");
            break;
    }

    return 0;
}
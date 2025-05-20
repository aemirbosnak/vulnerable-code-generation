//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PASSWORD_MINIMUM_LENGTH 8

int main()
{
    char password[PASSWORD_MINIMUM_LENGTH];
    int strength = 0;
    int i;

    printf("Hey there, traveler! Let's see if you can crack this password checker...\n");

    // Get the password from the user
    printf("Enter a password: ");
    scanf("%s", password);

    // Check the password strength
    for (i = 0; i < PASSWORD_MINIMUM_LENGTH; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            strength++;
        }
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            strength++;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            strength++;
        }
    }

    // Display the password strength
    switch (strength)
    {
        case 0:
            printf("Your password is as weak as a kitten in a cardboard box.\n");
            break;
        case 1:
            printf("Your password is as strong as a squirrel on a fence.\n");
            break;
        case 2:
            printf("Your password is as powerful as a lion tamer.\n");
            break;
        case 3:
            printf("Your password is as secure as a vault in Fort Knox.\n");
            break;
    }

    return 0;
}
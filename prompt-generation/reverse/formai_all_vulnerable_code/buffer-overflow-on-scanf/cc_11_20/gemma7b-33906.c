//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[20];
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    // Analyze password strength
    for (int i = 0; password[i] != '\0'; i++)
    {
        // Check for uppercase letter
        if (password[i] >= 'A' && password[i] <= 'Z')
            strength++;

        // Check for lowercase letter
        if (password[i] >= 'a' && password[i] <= 'z')
            strength++;

        // Check for number
        if (password[i] >= '0' && password[i] <= '9')
            strength++;

        // Check for special character
        if (password[i] >= '!' && password[i] <= '~')
            strength++;
    }

    // Print password strength
    switch (strength)
    {
        case 0:
            printf("Your password is as weak as a teacup on a cold night. Please try again.\n");
            break;
        case 1:
            printf("Your password is as strong as a single candle. It could be improved.\n");
            break;
        case 2:
            printf("Your password is as powerful as a torch in the hands of a skilled detective. Good job!\n");
            break;
        case 3:
            printf("Your password is as secure as a locked trunk in a castle. You have a master mind.\n");
            break;
    }

    return 0;
}
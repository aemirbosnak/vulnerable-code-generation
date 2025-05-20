//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main()
{
    char password[256];
    int strength = 0;

    printf("Hey, welcome to the Password Strength Checker!\n");
    printf("Please enter your desired password: ");

    scanf("%s", password);

    // Check password length
    if (strlen(password) < 8)
    {
        strength -= 20;
        printf("Oops! Your password is too short.\n");
    }

    // Check for uppercase letter
    if (!strchr(password, 'A'))
    {
        strength -= 15;
        printf("Uh oh! Your password needs an uppercase letter.\n");
    }

    // Check for number
    if (!strchr(password, '0') || !strchr(password, '9'))
    {
        strength -= 10;
        printf("Missing numbers? Your password needs some digits.\n");
    }

    // Check for special characters
    if (!strchr(password, '$') && !strchr(password, '&') &&
        !strchr(password, '*'))
    {
        strength -= 5;
        printf("Plain text? Add some spice with special characters.\n");
    }

    // Calculate strength percentage
    strength = (strength * 100) / 100;

    // Show strength results
    printf("Your password strength is: %d%%", strength);

    return 0;
}
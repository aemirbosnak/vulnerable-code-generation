//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

int main()
{
    char password[256] = "";
    int i = 0;
    int password_strength = 0;
    struct stat sb;

    system("/bin/clear");

    // Check if the user is root
    if (geteuid() != 0)
    {
        printf("Error: You must be root to use this program.\n");
        exit(1);
    }

    // Get the user's password
    printf("Enter your password: ");
    scanf("%s", password);

    // Check if the password is strong
    for (i = 0; i < strlen(password); i++)
    {
        // Check if the password character is a number
        if (password[i] >= '0' && password[i] <= '9')
        {
            password_strength++;
        }

        // Check if the password character is a letter
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            password_strength++;
        }

        // Check if the password character is a symbol
        else if (password[i] >= '!' && password[i] <= '~')
        {
            password_strength++;
        }
    }

    // Check if the password is strong enough
    if (password_strength < 8)
    {
        printf("Your password is not strong enough.\n");
        exit(1);
    }

    // Print a confirmation message
    printf("Your password is strong.\n");

    return 0;
}
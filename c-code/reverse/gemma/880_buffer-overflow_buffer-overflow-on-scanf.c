#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char password[100];
    scanf("%s", password);

    if (strlen(password) >= 8)
    {
        int hasUppercase = 0, hasLowercase = 0, hasDigits = 0, hasSpecialCharacters = 0;
        for (int i = 0; password[i] != '\0'; i++)
        {
            if (password[i] >= 'A' && password[i] <= 'Z')
            {
                hasUppercase = 1;
            }
            else if (password[i] >= 'a' && password[i] <= 'z')
            {
                hasLowercase = 1;
            }
            else if (password[i] >= '0' && password[i] <= '9')
            {
                hasDigits = 1;
            }
            else if (password[i] >= '`' && password[i] <= '~')
            {
                hasSpecialCharacters = 1;
            }
        }

        if (hasUppercase && hasLowercase && hasDigits && hasSpecialCharacters)
        {
            printf("Strength: Very strong\n");
        }
        else
        {
            printf("Strength: Weak\n");
        }
    }
    else
    {
        printf("Strength: Weak\n");
    }

    return 0;
}

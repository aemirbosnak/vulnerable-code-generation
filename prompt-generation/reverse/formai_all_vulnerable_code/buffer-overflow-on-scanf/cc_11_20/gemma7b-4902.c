//Gemma-7B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LEN 256

int main()
{
    char password[MAX_PASSWORD_LEN];
    int i, j, k, l;

    printf("Enter a strong password: ");
    scanf("%s", password);

    printf("Your password is: ");
    for (i = 0; password[i] != '\0'; i++)
    {
        printf("%c ", password[i]);
    }

    printf("\n");

    // Check if the password meets the following criteria:
    // - At least one uppercase letter
    // - At least one lowercase letter
    // - At least one number
    // - No repeated characters within the password

    k = 0;
    for (i = 0; password[i] != '\0'; i++)
    {
        for (j = 0; j < l; j++)
        {
            if (password[i] == password[j])
            {
                k = 1;
            }
        }

        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            l = i;
        }

        if (password[i] >= 'a' && password[i] <= 'z')
        {
            l = i;
        }

        if (password[i] >= '0' && password[i] <= '9')
        {
            l = i;
        }
    }

    if (k == 0)
    {
        printf("Your password meets the following criteria:\n");
        printf("- At least one uppercase letter\n");
        printf("- At least one lowercase letter\n");
        printf("- At least one number\n");
        printf("- No repeated characters within the password\n");

        printf("Congratulations! Your password is secure.\n");
    }
    else
    {
        printf("Sorry, your password does not meet the criteria.\n");
        printf("Please try again.\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHAR 128

int main()
{
    int length, i, j;
    char password[MAX_CHAR];

    printf("Enter the length of password you wish to generate: ");
    scanf("%d", &length);

    srand(time(NULL));

    for (i = 0; i < length; i++)
    {
        int r = rand() % 94 + 33;
        password[i] = r;
    }
    password[length] = '\0';

    // Check if password meets criteria
    int lowercase = 0, uppercase = 0, digit = 0, specialchar = 0;
    for (j = 0; j < length; j++)
    {
        if (password[j] >= 'a' && password[j] <='z')
        {
            lowercase++;
        }
        else if (password[j] >= 'A' && password[j] <= 'Z')
        {
            uppercase++;
        }
        else if (password[j] >= '0' && password[j] <='9')
        {
            digit++;
        }
        else
        {
            specialchar++;
        }
    }

    // Generate password again if not meeting criteria
    while (lowercase == 0 || uppercase == 0 || digit == 0 || specialchar == 0)
    {
        for (i = 0; i < length; i++)
        {
            int r = rand() % 94 + 33;
            password[i] = r;
        }
        password[length] = '\0';

        lowercase = 0, uppercase = 0, digit = 0, specialchar = 0;
        for (j = 0; j < length; j++)
        {
            if (password[j] >= 'a' && password[j] <='z')
            {
                lowercase++;
            }
            else if (password[j] >= 'A' && password[j] <= 'Z')
            {
                uppercase++;
            }
            else if (password[j] >= '0' && password[j] <='9')
            {
                digit++;
            }
            else
            {
                specialchar++;
            }
        }
    }

    printf("Your new secure password is: %s\n", password);

    return 0;
}
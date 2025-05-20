//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main()
{
    char password[100];
    int length, i, j, count = 0;
    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);

    if (length < 8)
    {
        printf("Password should be at least 8 characters long.\n");
        return 0;
    }

    for (i = 0; i < length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            count++;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            count++;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            count++;
        }
        else
        {
            count++;
        }
    }

    if (count < 3)
    {
        printf("Password is weak. It should contain at least one uppercase letter, one lowercase letter, and one digit.\n");
    }
    else if (count >= 3 && count < 5)
    {
        printf("Password is average.\n");
    }
    else
    {
        printf("Password is strong.\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[50];
    int length, i;
    int upper = 0, lower = 0, digits = 0, special = 0;

    printf("Enter password to check its strength:\n");
    scanf("%s", password);

    length = strlen(password);

    if(length < 8)
    {
        printf("Weak password. Must have at least 8 characters\n");
        return 0;
    }

    for(i = 0; i < length; i++)
    {
        if(isupper(password[i]))
        {
            upper++;
        }
        else if(islower(password[i]))
        {
            lower++;
        }
        else if(isdigit(password[i]))
        {
            digits++;
        } else
        {
            special++;
        }
    }

    if(upper >= 1 && lower >= 1 && digits >= 1 && special >= 1)
    {
        printf("Strong password. Well done!\n");
    }
    else
    {
        printf("Weak password. Must have at least one uppercase, one lowercase, one digit and one special character\n");
    }

    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include<stdio.h>
#include<string.h>

int main()
{
    char pwd[20];

    printf("Enter your password: ");
    scanf("%s", pwd);

    if(strlen(pwd) < 8)
    {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    char specialChars[10] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};
    int specialCount = 0;

    for(int i = 0; i < strlen(pwd); i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(pwd[i] == specialChars[j])
            {
                specialCount++;
                break;
            }
        }
    }

    if(specialCount < 1)
    {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    int uppercaseCount = 0;
    int lowercaseCount = 0;

    for(int i = 0; i < strlen(pwd); i++)
    {
        if(pwd[i] >= 'A' && pwd[i] <= 'Z')
        {
            uppercaseCount++;
        }
        else if(pwd[i] >= 'a' && pwd[i] <= 'z')
        {
            lowercaseCount++;
        }
    }

    if(uppercaseCount < 1 || lowercaseCount < 1)
    {
        printf("Password must contain at least one uppercase and one lowercase letter.\n");
        return 0;
    }

    printf("Your password is strong!\n");
    return 0;
}
//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: statistical
#include <stdio.h>
#include <string.h>

int main()
{
    char password[50];
    int length, uppercaseCount=0, lowercaseCount=0, digitCount=0;

    printf("Enter the password to check its strength:\n");
    scanf("%s", password);

    length = strlen(password);

    for(int i=0; i<length; i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
        {
            uppercaseCount++;
        }
        else if(password[i] >= 'a' && password[i] <= 'z')
        {
            lowercaseCount++;
        }
        else if(password[i] >= '0' && password[i] <= '9')
        {
            digitCount++;
        }
    }

    printf("Password Strength:\n");

    if(length < 6)
    {
        printf("Weak\n");
        printf("Minimum password length should be 6 characters.\n");
    }
    else if(length >= 6 && length <= 10)
    {
        if(uppercaseCount >= 1 && lowercaseCount >= 1 && digitCount >= 1)
        {
            printf("Strong\n");
        }
        else
        {
            printf("Moderate\n");
            printf("Password should contain at least one uppercase letter, one lowercase letter, and one digit.\n");
        }
    }
    else
    {
        if(uppercaseCount >= 2 && lowercaseCount >= 2 && digitCount >= 2)
        {
            printf("Very Strong\n");
        }
        else
        {
            printf("Strong\n");
            printf("Password should contain at least two uppercase letters, two lowercase letters, and two digits.\n");
        }
    }

    return 0;
}
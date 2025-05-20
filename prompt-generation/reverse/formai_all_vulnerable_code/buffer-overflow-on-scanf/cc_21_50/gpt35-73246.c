//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[50];

    printf("Enter password: ");
    scanf("%s", password);

    int length = strlen(password);
    int uppercase = 0;
    int lowercase = 0;
    int numbers = 0;
    int symbols = 0;

    // Count the number of uppercase, lowercase, numbers, and symbols in the password
    for(int i = 0; i < length; i++)
    {
        if(isupper(password[i]))
        {
            uppercase++;
        }
        else if(islower(password[i]))
        {
            lowercase++;
        }
        else if(isdigit(password[i]))
        {
            numbers++;
        }
        else
        {
            symbols++;
        }
    }

    int strength = 0;

    // Check the strength of the password based on the number of uppercase, lowercase, numbers, and symbols
    if(uppercase >= 1 && lowercase >= 1 && numbers >= 1 && symbols >= 1 && length >= 8)
    {
        strength = 4;
    }
    else if((uppercase >= 1 && lowercase >= 1 && numbers >= 1 && length >= 8) || (uppercase >= 1 && lowercase >= 1 && symbols >= 1 && length >= 8) || (lowercase >= 1 && numbers >= 1 && symbols >= 1 && length >= 8))
    {
        strength = 3;
    }
    else if((uppercase >= 1 && lowercase >= 1 && length >= 8) || (uppercase >= 1 && numbers >= 1 && length >= 8) || (uppercase >= 1 && symbols >= 1 && length >= 8) || (lowercase >= 1 && numbers >= 1 && length >= 8) || (lowercase >= 1 && symbols >= 1 && length >= 8) || (numbers >= 1 && symbols >= 1 && length >= 8))
    {
        strength = 2;
    }
    else if(length >= 8)
    {
        strength = 1;
    }

    // Output the strength of the password
    switch(strength)
    {
        case 4:
            printf("Strong password\n");
            break;
        case 3:
            printf("Moderately strong password\n");
            break;
        case 2:
            printf("Weak password\n");
            break;
        case 1:
            printf("Very weak password\n");
            break;
        default:
            printf("Invalid password\n");
            break;
    }

    return 0;
}
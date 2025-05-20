//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: retro
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char password[100];
    int length, i, upper=0, lower=0, digit=0, special=0;

    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);

    //Checking for uppercase letters
    for(i=0; i<length; i++)
    {
        if(isupper(password[i]))
        {
            upper++;
        }
    }

    //Checking for lowercase letters
    for(i=0; i<length; i++)
    {
        if(islower(password[i]))
        {
            lower++;
        }
    }

    //Checking for digits
    for(i=0; i<length; i++)
    {
        if(isdigit(password[i]))
        {
            digit++;
        }
    }

    //Checking for special characters
    for(i=0; i<length; i++)
    {
        if(!isalnum(password[i]))
        {
            special++;
        }
    }

    //Calculating password strength
    int strength = 0;
    if(length >= 8)
    {
        strength += 1;
    }
    if(upper >= 1)
    {
        strength += 1;
    }
    if(lower >= 1)
    {
        strength += 1;
    }
    if(digit >= 1)
    {
        strength += 1;
    }
    if(special >= 1)
    {
        strength += 1;
    }

    //Displaying password strength
    if(strength <= 1)
    {
        printf("Weak\n");
    }
    else if(strength <= 3)
    {
        printf("Medium\n");
    }
    else
    {
        printf("Strong\n");
    }

    return 0;
}
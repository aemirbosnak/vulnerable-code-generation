//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: brave
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main()
{
    char password[100];
    int length, upper, lower, digit, special, repeated;

    printf("Enter the password: ");
    scanf("%s", password);

    length = strlen(password);
    upper = 0;
    lower = 0;
    digit = 0;
    special = 0;
    repeated = 0;

    for(int i=0; i<length; i++)
    {
        if(isupper(password[i]))
        {
            upper = 1;
        }
        else if(islower(password[i]))
        {
            lower = 1;
        }
        else if(isdigit(password[i]))
        {
            digit = 1;
        }
        else if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*')
        {
            special = 1;
        }
        else if(i > 0 && password[i] == password[i-1])
        {
            repeated = 1;
            break;
        }
    }

    if(length >= 8 && upper && lower && digit && special &&!repeated)
    {
        printf("Strong Password");
    }
    else
    {
        printf("Weak Password");
    }

    return 0;
}
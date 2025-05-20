//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: brave
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
    char password[50];
    int length, i, upper=0, lower=0, digit=0, special=0;
    printf("Enter the password: ");
    scanf("%s", password);
    length = strlen(password);
    for(i=0; i<length; i++)
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
            digit++;
        }
        else
        {
            special++;
        }
    }
    if(length < 8)
    {
        printf("Password is too short\n");
    }
    else if(upper == 0 && lower == 0 && digit == 0 && special == 0)
    {
        printf("Password is too weak\n");
    }
    else if(upper == 0 || lower == 0 || digit == 0 || special == 0)
    {
        printf("Password is weak\n");
    }
    else if(length >= 8 && upper && lower && digit && special)
    {
        printf("Password is strong\n");
    }
    else
    {
        printf("Password is moderate\n");
    }
    return 0;
}
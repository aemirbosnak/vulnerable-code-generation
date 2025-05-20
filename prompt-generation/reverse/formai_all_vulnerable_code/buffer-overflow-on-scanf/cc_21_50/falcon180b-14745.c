//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: real-life
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_LENGTH 100

int main()
{
    char password[MAX_LENGTH];
    int length, i;
    int uppercase = 0, lowercase = 0, digit = 0, special = 0;
    int total_score = 0;
    
    printf("Enter password: ");
    scanf("%s", password);
    
    length = strlen(password);
    
    for(i=0; i<length; i++)
    {
        if(isupper(password[i]))
        {
            uppercase = 1;
        }
        else if(islower(password[i]))
        {
            lowercase = 1;
        }
        else if(isdigit(password[i]))
        {
            digit = 1;
        }
        else
        {
            special = 1;
        }
    }
    
    if(length >= 8)
    {
        total_score += 1;
    }
    if(length >= 12)
    {
        total_score += 2;
    }
    if(length >= 16)
    {
        total_score += 3;
    }
    
    if(uppercase && lowercase)
    {
        total_score += 1;
    }
    if(uppercase && digit)
    {
        total_score += 1;
    }
    if(lowercase && digit)
    {
        total_score += 1;
    }
    if(uppercase && special)
    {
        total_score += 1;
    }
    if(lowercase && special)
    {
        total_score += 1;
    }
    if(digit && special)
    {
        total_score += 1;
    }
    
    printf("Password Strength: ");
    if(total_score < 3)
    {
        printf("Weak\n");
    }
    else if(total_score < 6)
    {
        printf("Moderate\n");
    }
    else
    {
        printf("Strong\n");
    }
    
    return 0;
}
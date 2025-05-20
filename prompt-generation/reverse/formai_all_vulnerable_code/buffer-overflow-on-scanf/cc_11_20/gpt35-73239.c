//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int length = 0, lower = 0, upper = 0, digit = 0, special = 0, score = 0;
    char password[50];
    
    printf("Enter password to check: ");
    scanf("%s", password);
    length = strlen(password);
    
    for(int i=0; i<length; i++)
    {
        char c = password[i];
        if(c >= 'a' && c <= 'z')
        {
            lower++;
        }
        else if(c >= 'A' && c <= 'Z')
        {
            upper++;
        }
        else if(c >= '0' && c <= '9')
        {
            digit++;
        }
        else
        {
            special++;
        }
    }
    
    // Calculating password strength score
    if(length >= 6 && length <= 8) 
    {
        score += 10;
    } 
    else if(length > 8) 
    {
        score += 25;
    }
    
    if(upper > 0 && lower > 0) 
    {
        score += 20;
    }
    
    if(digit > 0 && special > 0) 
    {
        score += 25;
    } 
    else if(digit > 0 || special > 0) 
    {
        score += 10;
    }
    
    // Password strength rating
    if(score == 0 || score <= 40)
    {
        printf("\nPassword strength: Weak");
    }
    else if(score <= 70)
    {
        printf("\nPassword strength: Medium");
    }
    else
    {
        printf("\nPassword strength: Strong");
    }
    
    return 0;
}
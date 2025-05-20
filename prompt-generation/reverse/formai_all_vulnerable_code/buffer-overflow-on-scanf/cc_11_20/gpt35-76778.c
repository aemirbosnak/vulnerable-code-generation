//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];
    int len, i, upper, lower, digit, other, strength=0;
    
    printf("Please enter your password: ");
    scanf("%s", password);
    
    len = strlen(password);
    
    if(len < 8)
    {
        printf("Your password is too short!\n");
        return 1;
    }
    
    for(i=0; i<len; i++)
    {
        if(isupper(password[i]))
        {
            strength += 3;
            upper++;
        }
        else if(islower(password[i]))
        {
            strength += 3;
            lower++;
        }
        else if(isdigit(password[i]))
        {
            strength += 3;
            digit++;
        }
        else
        {
            other++;
        }
    }
    
    strength += len;
    
    printf("Your password is %d characters long.\n", len);
    
    printf("Your password contains %d uppercase letter(s), %d lowercase letter(s), and %d digit(s).\n", upper, lower, digit);
    
    if(other > 0)
    {
        printf("Your password also contains %d symbol(s) or special character(s).\n", other);
    }
    
    if(strength < 20)
    {
        printf("Your password is very weak. Please try again.\n");
    }
    else if(strength >= 20 && strength < 40)
    {
        printf("Your password is weak. Please try again.\n");
    }
    else if(strength >= 40 && strength < 60)
    {
        printf("Your password is moderate. It can be improved.\n");
    }
    else if(strength >= 60 && strength < 80)
    {
        printf("Your password is strong. Good job!\n");
    }
    else if(strength >= 80)
    {
        printf("Your password is very strong. Congratulations!\n");
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];
    printf("Please enter your password: ");
    scanf("%s", password);
    int len = strlen(password);
    
    int upperCase = 0, lowerCase = 0, digits = 0, symbols = 0;
    for(int i=0; i<len; i++)
    {
        if(isupper(password[i]))
        {
            upperCase++;
        }
        if(islower(password[i]))
        {
            lowerCase++;
        }
        if(isdigit(password[i]))
        {
            digits++;
        }
        if(!isalnum(password[i]))
        {
            symbols++;
        }
    }
    
    int strength = 0;
    if(len >= 8)
    {
        strength += 20;
    }
    if(upperCase > 0 && lowerCase > 0)
    {
        strength += 20;
    }
    if(digits > 0)
    {
        strength += 20;
    }
    if(symbols > 0)
    {
        strength += 20;
    }
    if(len >= 12)
    {
        strength += 20;
    }
    
    if(strength == 0)
    {
        printf("Your password is too weak, it needs to have at least 8 characters and at least one uppercase letter, one lowercase letter, one digit and one symbol\n");
    }
    else if(strength < 60)
    {
        printf("Your password is weak, it has a strength of %d percent. You should consider changing it\n", strength);
    }
    else if(strength < 80)
    {
        printf("Your password is a bit weak, it has a strength of %d percent. It's recommended to add more complexity\n", strength);
    }
    else if(strength < 100)
    {
        printf("Your password is strong, it has a strength of %d percent. Keep it up!\n", strength);
    }
    else
    {
        printf("Your password is excellent, it has a strength of %d percent. You must be very paranoid!\n", strength);
    }
    return 0;
}
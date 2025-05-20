//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* function to check password strength */
int password_strength(char *password)
{
    int len = strlen(password);
    int count = 0;
    int flags = 0;
    int strength = 0;
    
    /* count digits, uppercase and lowercase letters */
    for(int i = 0; i < len; i++)
    {
        if(isdigit(password[i]))
            count++;
        if(isupper(password[i]))
            flags |= 1;
        if(islower(password[i]))
            flags |= 2;
    }
    
    /* calculate password strength based on conditions */
    if(len >= 8 && count >= 2 && flags == 3)
        strength = 4;
    else if(len >= 8 && flags == 2)
        strength = 3;
    else if(len < 8 || (flags == 1 && count < 2))
        strength = 1;
    else
        strength = 2;
    
    return strength;
}

int main()
{
    char password[25];
    printf("Enter your password: ");
    scanf("%s", password);
    
    int strength = password_strength(password);
    
    /* print password strength */
    switch(strength)
    {
        case 1:
            printf("Password is weak\n");
            break;
        case 2:
            printf("Password is moderate\n");
            break;
        case 3:
            printf("Password is strong\n");
            break;
        case 4:
            printf("Password is very strong\n");
            break;
        default:
            printf("Invalid Password\n");
    }
    
    return 0;
}
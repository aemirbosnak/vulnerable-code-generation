//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: systematic
#include <stdio.h>
#include <string.h>

int main()
{
    char password[100];
    int length, uppercase, lowercase, digit, special_char;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    // Check for uppercase letters
    uppercase = 0;
    for(int i=0; i<length; i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
        {
            uppercase = 1;
            break;
        }
    }

    // Check for lowercase letters
    lowercase = 0;
    for(int i=0; i<length; i++)
    {
        if(password[i] >= 'a' && password[i] <= 'z')
        {
            lowercase = 1;
            break;
        }
    }

    // Check for digits
    digit = 0;
    for(int i=0; i<length; i++)
    {
        if(password[i] >= '0' && password[i] <= '9')
        {
            digit = 1;
            break;
        }
    }

    // Check for special characters
    special_char = 0;
    for(int i=0; i<length; i++)
    {
        if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*' || password[i] == '?')
        {
            special_char = 1;
            break;
        }
    }

    // Calculate password strength
    int strength = 0;
    if(length >= 8)
    {
        strength += 1;
    }
    if(uppercase)
    {
        strength += 1;
    }
    if(lowercase)
    {
        strength += 1;
    }
    if(digit)
    {
        strength += 1;
    }
    if(special_char)
    {
        strength += 1;
    }

    // Print password strength
    printf("\nPassword strength: ");
    if(strength == 0)
    {
        printf("Very Weak\n");
    }
    else if(strength == 1)
    {
        printf("Weak\n");
    }
    else if(strength == 2)
    {
        printf("Moderate\n");
    }
    else if(strength == 3)
    {
        printf("Strong\n");
    }
    else
    {
        printf("Very Strong\n");
    }

    return 0;
}
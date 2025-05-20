//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /* Initializing required variables */
    char password[100];
    int length, flag = 0, upper = 0, lower = 0, digit = 0, special = 0;
   
    printf("Enter a password: ");
    scanf("%s", password);
   
    length = strlen(password);
   
    /* Checking length of the password */
    if (length < 8)
    {
        printf("Password length should be at least 8 characters.\n");
        exit(1);
    }
   
    /* Checking if password contains upper case, lower case and digits */
    for (int i = 0; i < length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            upper = 1;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            lower = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            digit = 1;
        }
        else
        {
            special = 1;
        }
    }
   
    /* Setting flag to 1 if password contains all types of characters */
    if (upper == 1 && lower == 1 && digit == 1 && special == 1)
    {
        flag = 1;
    }
   
    /* Printing the strength of password based on the flag value */
    if (flag == 1)
    {
        printf("Strong Password.\n");
    }
    else
    {
        printf("Weak Password.\n");
    }
   
    return 0;
}
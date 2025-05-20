//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

int main()
{
    char password[100];
    int length, i, count_uppercase=0, count_lowercase=0, count_digits=0, count_special_chars=0;
    bool is_valid_password=true;

    printf("Enter password: ");
    scanf("%s", password);

    length=strlen(password);

    for(i=0; i<length; i++)
    {
        if(isalpha(password[i]))
        {
            if(isupper(password[i]))
            {
                count_uppercase++;
            }
            else
            {
                count_lowercase++;
            }
        }
        else if(isdigit(password[i]))
        {
            count_digits++;
        }
        else
        {
            count_special_chars++;
        }
    }

    if(length<8)
    {
        printf("Password must be at least 8 characters long.\n");
        is_valid_password=false;
    }

    if(count_uppercase==0 || count_lowercase==0 || count_digits==0 || count_special_chars==0)
    {
        printf("Password must contain at least one uppercase letter, one lowercase letter, one digit and one special character.\n");
        is_valid_password=false;
    }

    if(is_valid_password)
    {
        printf("Password is strong.\n");
    }
    else
    {
        printf("Password is weak.\n");
    }

    return 0;
}
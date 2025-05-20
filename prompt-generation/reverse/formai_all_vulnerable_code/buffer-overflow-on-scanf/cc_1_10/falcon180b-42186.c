//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: calm
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char password[100];
    int len, i, count_uppercase = 0, count_lowercase = 0, count_digit = 0, count_special = 0;

    printf("Enter Password: ");
    scanf("%s", password);
    len = strlen(password);

    for(i=0; i<len; i++)
    {
        if(isupper(password[i]))
        {
            count_uppercase++;
        }
        else if(islower(password[i]))
        {
            count_lowercase++;
        }
        else if(isdigit(password[i]))
        {
            count_digit++;
        }
        else
        {
            count_special++;
        }
    }

    if(len >= 8)
    {
        if(count_uppercase && count_lowercase && count_digit && count_special)
        {
            printf("Strong Password\n");
        }
        else
        {
            printf("Weak Password\n");
        }
    }
    else
    {
        printf("Password must be at least 8 characters long\n");
    }

    return 0;
}
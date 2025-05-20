//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

#define MAX_LEN 100
#define MIN_LEN 8
#define MIN_NUM 1
#define MIN_LOWER 1
#define MIN_UPPER 1
#define MIN_SPECIAL 1

int main()
{
    char password[MAX_LEN] = {'\0'};
    int len = 0;
    int num = 0;
    int lower = 0;
    int upper = 0;
    int special = 0;
    int strength = 0;
    char *message = "Please enter your password: ";

    printf("%s", message);
    scanf("%s", password);

    len = strlen(password);

    if(len < MIN_LEN)
    {
        printf("Password must be at least %d characters long.\n", MIN_LEN);
        exit(0);
    }

    for(int i = 0; i < len; i++)
    {
        if(isdigit(password[i]))
        {
            num++;
        }
        else if(isalpha(password[i]))
        {
            if(islower(password[i]))
            {
                lower++;
            }
            else if(isupper(password[i]))
            {
                upper++;
            }
        }
        else
        {
            special++;
        }
    }

    if(num < MIN_NUM)
    {
        printf("Password must contain at least %d number(s).\n", MIN_NUM);
        exit(0);
    }

    if(lower < MIN_LOWER)
    {
        printf("Password must contain at least %d lowercase letter(s).\n", MIN_LOWER);
        exit(0);
    }

    if(upper < MIN_UPPER)
    {
        printf("Password must contain at least %d uppercase letter(s).\n", MIN_UPPER);
        exit(0);
    }

    if(special < MIN_SPECIAL)
    {
        printf("Password must contain at least %d special character(s).\n", MIN_SPECIAL);
        exit(0);
    }

    if(num && lower && upper && special)
    {
        strength = 4;
        printf("Password strength: Very Strong\n");
    }
    else if((num || lower || upper) && special)
    {
        strength = 3;
        printf("Password strength: Strong\n");
    }
    else if(num && (lower || upper))
    {
        strength = 2;
        printf("Password strength: Moderate\n");
    }
    else if(num || (lower && upper))
    {
        strength = 1;
        printf("Password strength: Weak\n");
    }
    else
    {
        strength = 0;
        printf("Password strength: Very Weak\n");
    }

    return 0;
}
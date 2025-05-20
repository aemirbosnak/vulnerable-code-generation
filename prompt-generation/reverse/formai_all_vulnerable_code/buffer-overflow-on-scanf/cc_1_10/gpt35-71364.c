//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_length(char* password)
{
    int length = strlen(password);
    return length >= 8 && length <= 16;
}

int check_uppercase(char* password)
{
    int i, count = 0;
    for(i=0; i<strlen(password); i++)
    {
        if(isupper(password[i]))
            count++;
    }
    return count >= 1;
}

int check_lowercase(char* password)
{
    int i, count = 0;
    for(i=0; i<strlen(password); i++)
    {
        if(islower(password[i]))
            count++;
    }
    return count >= 1;
}

int check_digit(char* password)
{
    int i, count = 0;
    for(i=0; i<strlen(password); i++)
    {
        if(isdigit(password[i]))
            count++;
    }
    return count >= 1;
}

int check_special(char* password)
{
    int i, count = 0;
    for(i=0; i<strlen(password); i++)
    {
        if(!isalnum(password[i]))
            count++;
    }
    return count >= 1;
}

int main()
{
    char password[50];
    int is_valid = 1;

    printf("Enter your password: \n");
    scanf("%s", password);

    if(!check_length(password))
    {
        printf("Your password should be between 8 and 16 characters\n");
        is_valid = 0;
    }

    if(!check_uppercase(password))
    {
        printf("Your password should contain at least 1 uppercase letter\n");
        is_valid = 0;
    }

    if(!check_lowercase(password))
    {
        printf("Your password should contain at least 1 lowercase letter\n");
        is_valid = 0;
    }

    if(!check_digit(password))
    {
        printf("Your password should contain at least 1 digit\n");
        is_valid = 0;
    }

    if(!check_special(password))
    {
        printf("Your password should contain at least 1 special character\n");
        is_valid = 0;
    }

    if(is_valid)
    {
        printf("Your password is strong and contains all the necessary requirements\n");
    }

    return 0;
}
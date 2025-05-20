//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: modular
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int check_length(char *);
int check_uppercase(char *);
int check_lowercase(char *);
int check_digit(char *);
int check_special_char(char *);

int main()
{
    char password[100];
    int pass_length, pass_strength=0;
    printf("Enter your password: ");
    scanf("%s", password);
    pass_length = check_length(password);
    pass_strength += pass_length;
    pass_strength += check_uppercase(password);
    pass_strength += check_lowercase(password);
    pass_strength += check_digit(password);
    pass_strength += check_special_char(password);
    
    if(pass_strength >= 6)
    {
        printf("\nPassword is STRONG!\n");
    }
    else if(pass_strength >= 4)
    {
        printf("\nPassword is AVERAGE.\nPlease add more complexity for better security.\n");
    }
    else
    {
        printf("\nWeak password. Please set a password of at least 6 characters with complexity.\n");
    }
    return 0;
}

int check_length(char *password)
{
    int length = strlen(password);
    if(length >= 6)
    {
        return 1;
    }
    else
    {
        printf("\nPassword should be of at least 6 characters.\n");
        exit(0);
    }
}

int check_uppercase(char *password)
{
    int count = 0;
    for(int i=0; i<strlen(password); i++)
    {
        if(isupper(*(password+i)))
        {
            count++;
        }
    }
    if(count >= 1)
    {
        return 1;
    }
    else
    {
        printf("\nPassword should contain at least 1 uppercase letter.\n");
        exit(0);
    }
}

int check_lowercase(char *password)
{
    int count = 0;
    for(int i=0; i<strlen(password); i++)
    {
        if(islower(*(password+i)))
        {
            count++;
        }
    }
    if(count >= 1)
    {
        return 1;
    }
    else
    {
        printf("\nPassword should contain at least 1 lowercase letter.\n");
        exit(0);
    }
}

int check_digit(char *password)
{
    int count = 0;
    for(int i=0; i<strlen(password); i++)
    {
        if(isdigit(*(password+i)))
        {
            count++;
        }
    }
    if(count >= 1)
    {
        return 1;
    }
    else
    {
        printf("\nPassword should contain at least 1 digit.\n");
        exit(0);
    }
}

int check_special_char(char *password)
{
    char special_chars[] = "!@#$%^&*()";
    int count = 0;
    for(int i=0; i<strlen(password); i++)
    {
        for(int j=0; j<strlen(special_chars); j++)
        {
            if(*(password+i) == special_chars[j])
            {
                count++;
            }
        }
    }
    if(count >= 1)
    {
        return 1;
    }
    else
    {
        printf("\nPassword should contain at least 1 special character (!@#$%^&*()).\n");
        exit(0);
    }
}
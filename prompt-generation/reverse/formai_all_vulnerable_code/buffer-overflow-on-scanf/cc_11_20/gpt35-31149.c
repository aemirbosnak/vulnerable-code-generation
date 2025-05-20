//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: creative
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//function to check if input contains only digits
int is_digits(char *input) 
{
    for(int i=0;i<strlen(input);i++)
    {
        if(!isdigit(input[i]))
            return 0;
    }
    return 1;
}

int main()
{
    int length = 0, uppercase = 0, lowercase = 0, digit = 0, special = 0;
    char password[100];

    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);

    for(int i=0;i<length;i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
            uppercase++;
        else if(password[i] >= 'a' && password[i] <='z')
            lowercase++;
        else if(isdigit(&password[i]))
            digit++;
        else
            special++;
    }

    printf("\nPassword Strength:\n");

    if(length<8 || (uppercase<1 || lowercase<1 || digit<1 || special<1))
        printf("\nWeak Password!");
    else if(length>=8 && length<12 && (uppercase>=1 && lowercase>=1 && (digit>=1 || special>=1)))
        printf("\nMedium Password!");
    else if(length>=12 && (uppercase>=2 && lowercase>=2 && (digit>=2 || special>=2)))
        printf("\nStrong Password!");
    else
        printf("\nVery Strong Password!");

    return 0;
}
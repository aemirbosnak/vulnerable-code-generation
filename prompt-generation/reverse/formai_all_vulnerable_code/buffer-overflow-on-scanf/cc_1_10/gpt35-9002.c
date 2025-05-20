//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    //Initializing variables
    char password[50];
    int length, digit_count=0, upper_count=0, lower_count=0, special_count=0, total_score=0;
    int i, j;

    //Prompting user for password
    printf("Please enter your password: ");
    scanf("%s", password);

    //Calculating the length of password
    length = strlen(password);

    //Checking for digits, upper and lower case letters, and special characters
    for(i=0; i<length; i++)
    {
        if (isdigit(password[i]))
        {
            digit_count++;
        }
        else if (isupper(password[i]))
        {
            upper_count++;
        }
        else if (islower(password[i]))
        {
            lower_count++;
        }
        else
        {
            special_count++;
        }
    }

     //Password Score Calculation
     total_score = +2 * digit_count + 3 * upper_count + 3 * lower_count + 5 * special_count;

     //Printing the strength of password
     if (total_score >= 50)
     {
         printf("\n\n***** Your password is Strong! *****\n");
     }
     else if (total_score >=25 && total_score < 50)
     {
         printf("\n\n***** Your password is Moderate! *****\n");
     }
     else
    {
        printf("\n\n***** Your password is Weak! *****\n");
    }

    return 0;
}
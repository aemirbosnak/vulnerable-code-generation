//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: shocked
#include<stdio.h>
#include<string.h>

int main()
{
    char password[30];
    int length, i, digit=0, ucase=0, lcase=0, specialchar=0;

    printf("Enter the password to validate its strength:\n");
    scanf("%s", password);

    length = strlen(password);

    if(length<8)
        printf("WARNING: Password should be atleast 8 characters long!\n");
    else
    {
        for(i=0; i<length; i++)
        {
            if((password[i]>=48) && (password[i]<=57))
                digit++;

            if((password[i]>=65) && (password[i]<=90))
                ucase++;

            if((password[i]>=97) && (password[i]<=122))
                lcase++;

            if((password[i]>=33) && (password[i]<=47))
                specialchar++;
        }

        if(digit && ucase && lcase && specialchar)
            printf("CONGRATULATIONS! Password is STRONG!\n");

        else
        {
            printf("WARNING: Password is not strong enough!\n");
            if(!digit)
                printf("Password should contain atleast one Digit\n");

            if(!ucase)
                printf("Password should contain atleast one Uppercase letter\n");

            if(!lcase)
                printf("Password should contain atleast one Lowercase letter\n");

            if(!specialchar)
                printf("Password should contain atleast one Special Character\n");
        }
    }

    return 0;
}
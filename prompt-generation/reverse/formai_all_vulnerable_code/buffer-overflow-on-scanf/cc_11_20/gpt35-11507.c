//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    int min_length = 8; //minimum password length
    int upper = 0; //uppercase letter count
    int lower = 0; //lowercase letter count
    int digits = 0; //digit count
    int special = 0; //special character count
    char password[50]; //maximum password length
    printf("Enter your password:\n");
    scanf("%s", password); //read password from user
    int length = strlen(password); //calculate password length
    if(length<min_length)//check if password is shorter than minimum allowed lenghth
    {
        printf("Password length should be more than or equal to %d characters.\n", min_length);
        exit(0); //exit the program in case of password length violation
    }
    for(int i=0; i<length; i++) //iterate through each character in the password
    {
        if(isupper(password[i])) //check if character is uppercase
            upper++;
        if(islower(password[i])) //check if character is lowercase
            lower++;
        if(isdigit(password[i])) //check if character is a digit
            digits++;
        if(!isalnum(password[i])) //check if character is a special character
            special++;
    }
    if(upper==0) //check if there is atleast 1 uppercase character
    {
        printf("Password should contain atleast 1 uppercase character.\n");
    }
    if(lower==0) //check if there is atleast 1 lowercase character
    {
        printf("Password should contain atleast 1 lowercase character.\n");
    }
    if(digits==0) //check if there is atleast 1 digit
    {
        printf("Password should contain atleast 1 digit.\n");
    }
    if(special==0) //check if there is atleast 1 special character
    {
        printf("Password should contain atleast 1 special character.\n");
    }
    if(upper>0 && lower>0 && digits>0 && special>0) //if all conditions are met, password strength is strong
    {
        printf("Congratulations! Password strength is strong.\n");
        printf("Keep your password safe!\n");
    }
    return 0;
}
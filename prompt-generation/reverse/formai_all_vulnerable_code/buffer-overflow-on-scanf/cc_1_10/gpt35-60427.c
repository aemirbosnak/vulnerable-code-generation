//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: future-proof
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

//Function to check the strength of password
bool checkPasswordStrength(char* password)
{
    int len = strlen(password);
    
    //Checking for length of password
    if (len < 8)
        return false;       //Weak Password
    
    bool upperFlag = false;
    bool lowerFlag = false;
    bool digitFlag = false;
    bool specialFlag = false;
    
    //Checking for upper case,lower case, digits & special characters
    for(int i=0;i<len;i++)
    {
        if(password[i]>='A' && password[i]<='Z')
            upperFlag = true;
        else if(password[i]>='a' && password[i]<='z')
            lowerFlag = true;
        else if(password[i]>='0' && password[i]<='9')
            digitFlag = true;
        else
            specialFlag = true;
    }
    
    //Checking for all conditions
    if(upperFlag && lowerFlag && digitFlag && specialFlag)
        return true;        //Strong Password
    
    return false;           //Moderate Password
}

int main()
{
    char password[50];
    printf("Enter your password: ");
    scanf("%s",password);
    
    if(checkPasswordStrength(password))
        printf("Congratulations! Your password is strong.");
    else
        printf("Your password is weak. Please create a strong password.");
    
    return 0;
}
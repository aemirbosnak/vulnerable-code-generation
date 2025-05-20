//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: retro
#include<stdio.h>
#include<string.h>

int main()
{
    char password[50];
    printf("Please enter your password: ");
    scanf("%s", password);

    int length=strlen(password);
    int score=0;
    int uppercase_letters=0;
    int lowercase_letters=0;
    int numbers=0;

    // Checking the length of the password and adding to the score
    if(length<6) score+=0;
    else if(length<8) score+=10;
    else if(length<10) score+=20;
    else score+=30;

    // Checking for uppercase letters and adding to the score
    for(int i=0; i<length; i++)
    {
        if(password[i]>='A' && password[i]<='Z')
        {
            score+=5;
            uppercase_letters++;
        }
    }

    // Checking for lowercase letters and adding to the score
    for(int i=0; i<length; i++)
    {
        if(password[i]>='a' && password[i]<='z')
        {
            score+=5;
            lowercase_letters++;
        }
    }

    // Checking for numbers and adding to the score
    for(int i=0; i<length; i++)
    {
        if(password[i]>='0' && password[i]<='9')
        {
            score+=5;
            numbers++;
        }
    }

    // Printing the results
    printf("\n\nPassword strength: %d/100", score);
    printf("\nUppercase letters: %d", uppercase_letters);
    printf("\nLowercase letters: %d", lowercase_letters);
    printf("\nNumbers: %d", numbers);

    return 0;
}
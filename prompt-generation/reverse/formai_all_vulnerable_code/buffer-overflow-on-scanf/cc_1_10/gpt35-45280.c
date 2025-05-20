//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//Function to generate random characters
char getRandomChar() 
{
    char possibleChars[] = "!@#$%^&*()_+-={}[]|\\:;\"\'<>,.?/~`abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int randomIndex = rand() % (sizeof(possibleChars) - 1);
    return possibleChars[randomIndex];
}

//Function to generate a secure password with a specified length
void generatePassword(int length) 
{
    //Initialize the password string and seed the random number generator
    char password[length + 1];
    srand((unsigned int) time(0));

    for(int i = 0; i < length; i++) 
    {
        //Get random character and add it to the password
        password[i] = getRandomChar();
    }

    //Add null terminator to end of password string
    password[length] = '\0';

    //Check if password meets requirements
    int hasUpperCase = 0;
    int hasLowerCase = 0;
    int hasDigit = 0;
    int hasSpecialChar = 0;
    
    for(int i = 0; i < length; i++) 
    {
        if(isupper(password[i])) 
        {
            hasUpperCase = 1;
        } 
        else if(islower(password[i])) 
        {
            hasLowerCase = 1;
        } 
        else if(isdigit(password[i])) 
        {
            hasDigit = 1;
        } 
        else 
        {
            hasSpecialChar = 1;
        }
    }
    
    //If password does not meet requirements, regenerate it
    if(!hasUpperCase || !hasLowerCase || !hasDigit || !hasSpecialChar) 
    {
        generatePassword(length);
    }

    //Print the password
    printf("Your secure password is: %s\n", password);
}

//Main function
int main() 
{
    int passwordLength;

    //Get password length from user
    printf("Enter the desired password length: ");
    scanf("%d", &passwordLength);

    //Generate password and print it to user
    generatePassword(passwordLength);

    return 0;
}
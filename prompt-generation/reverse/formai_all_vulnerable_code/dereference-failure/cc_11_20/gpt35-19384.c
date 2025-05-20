//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

//Function to generate random password
char* generatePassword(int length)
{
    char* password = malloc((length+1)*sizeof(char)); //Dynamically allocated memory for password 
   
    //Define the characters that can be used in password
    char symbols[] = "~!@#$%^&*()_+`-={}|[]\\:\"<>?,./";
    char numbers[] = "0123456789";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   
    int numSymbols = sizeof(symbols) - 1; //Total number of symbols available
    int numNumbers = sizeof(numbers) - 1; //Total number of numbers available
    int numLowercase = sizeof(lowercase) - 1; //Total number of lowercase letters available
    int numUppercase = sizeof(uppercase) - 1; //Total number of uppercase letters available

    //Seed random number generator
    srand(time(NULL));

    //Choose at least one symbol, number, lowercase and uppercase letter for password
    password[0] = symbols[rand() % numSymbols];
    password[1] = numbers[rand() % numNumbers];
    password[2] = lowercase[rand() % numLowercase];
    password[3] = uppercase[rand() % numUppercase];

    //Fill rest of the password with random characters from all available types
    for(int i = 4; i < length; i++)
    {
        int type = rand() % 4; //Choose a random type of character

        switch(type)
        {
            case 0: //Add a symbol
                password[i] = symbols[rand() % numSymbols];
                break;
           
            case 1: //Add a number
                password[i] = numbers[rand() % numNumbers];
                break;
           
            case 2: //Add a lowercase letter
                password[i] = lowercase[rand() % numLowercase];
                break;
           
            case 3: //Add an uppercase letter
                password[i] = uppercase[rand() % numUppercase];
                break;
        }
    }

    password[length] = '\0'; //Terminate the string with null character
    return password;
}

int main()
{
    int length;

    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter a length for your password (8-64 characters): ");
    scanf("%d", &length);

    //Check if entered length is valid
    if(length < 8 || length > 64)
    {
        printf("Invalid length entered. Please enter a length between 8 and 64 characters.\n");
        return 1;
    }
   
    //Generate password
    char* password = generatePassword(length);
   
    //Check if password contains at least one symbol, number, lowercase and uppercase letter
    int hasSymbol = 0, hasNumber = 0, hasLower = 0, hasUpper = 0;

    for(int i = 0; i < length; i++)
    {
        if(ispunct(password[i])) hasSymbol = 1;
        if(isdigit(password[i])) hasNumber = 1;
        if(islower(password[i])) hasLower = 1;
        if(isupper(password[i])) hasUpper = 1;
    }
   
    //If any type of character is missing, generate new password
    while(!hasSymbol || !hasNumber || !hasLower || !hasUpper)
    {
        free(password); //Free memory allocated for previous password
        password = generatePassword(length); //Generate new password
       
        //Check if new password contains all required types of characters
        hasSymbol = 0, hasNumber = 0, hasLower = 0, hasUpper = 0;

        for(int i = 0; i < length; i++)
        {
            if(ispunct(password[i])) hasSymbol = 1;
            if(isdigit(password[i])) hasNumber = 1;
            if(islower(password[i])) hasLower = 1;
            if(isupper(password[i])) hasUpper = 1;
        }
    }
   
    printf("Your secure password has been generated: %s\n", password);
    free(password); //Free memory allocated for password
   
    return 0;
}
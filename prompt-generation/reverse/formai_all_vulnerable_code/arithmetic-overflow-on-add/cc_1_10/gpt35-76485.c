//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const char* symbols = "!@#$%^&*()_+-=[]{}|;:,./<>?`~";
    const char* digits = "0123456789";
    const char* lowercase = "abcdefghijklmnopqrstuvwxyz";
    const char* uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int length;
    
    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the desired length of your password: ");
    scanf("%d", &length);
    
    if(length < 8)
    {
        printf("Password length must be at least 8 characters. Please try again.\n");
        return 0;
    }
    
    char* password = malloc((length + 1) * sizeof(char)); //Allocate memory for password
    
    srand(time(NULL)); //Seed random number generator with time
    
    for(int i = 0; i < length; i++)
    {
        int category = rand() % 4; //Choose a category for the character (symbol, digit, lowercase, uppercase)
        
        switch(category)
        {
            case 0: //Symbol
                password[i] = symbols[rand() % 21]; //21 symbols in the symbol string
                break;
            case 1: //Digit
                password[i] = digits[rand() % 10]; //10 digits in the digit string
                break;
            case 2: //Lowercase letter
                password[i] = lowercase[rand() % 26]; //26 lowercase letters in the lowercase string
                break;
            case 3: //Uppercase letter
                password[i] = uppercase[rand() % 26]; //26 uppercase letters in the uppercase string
                break;
        }
    }
    
    password[length] = '\0'; //Null-terminate the password
    
    printf("Your secure password is: %s\n", password);
    
    free(password); //Free memory used by password
    
    return 0;
}
//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random secure password
void generate_password(int length)
{
    srand(time(0)); // seeding the random number generator with current time
    
    // defining character sets to be used in the password
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char symbols[] = "!@#$%^&*()_+-=";
    char numbers[] = "0123456789";
    
    int lowercase_count = 0;
    int uppercase_count = 0;
    int symbol_count = 0;
    int number_count = 0;
    int i;
    
    // checking the length of the password
    if(length < 8)
    {
        printf("\nSorry, your password must be at least 8 characters long. I am generating a 8 character password for you anyway. :)\n\n");
        length = 8;
    }
    
    // defining the password array and filling it with random characters
    char password[length+1];
    for(i = 0; i < length; i++)
    {
        int set = rand() % 4; // selecting the character set randomly
        
        switch(set)
        {
            case 0:
                password[i] = lowercase[rand() % 26];
                lowercase_count++;
                break;
                
            case 1:
                password[i] = uppercase[rand() % 26];
                uppercase_count++;
                break;
                
            case 2:
                password[i] = symbols[rand() % 12];
                symbol_count++;
                break;
                
            case 3:
                password[i] = numbers[rand() % 10];
                number_count++;
                break;
        }
    }
    
    // checking if the password has at least one character from each set
    if(lowercase_count == 0)
    {
        password[length-1] = lowercase[rand() % 26];
        lowercase_count++;
    }
    
    if(uppercase_count == 0)
    {
        password[length-2] = uppercase[rand() % 26];
        uppercase_count++;
    }
    
    if(symbol_count == 0)
    {
        password[length-3] = symbols[rand() % 12];
        symbol_count++;
    }
    
    if(number_count == 0)
    {
        password[length-4] = numbers[rand() % 10];
        number_count++;
    }
    
    password[length] = '\0';
    
    // printing the generated password
    printf("\nCongratulations! Your new password is: %s\n\n", password);
    printf("This password contains %d lowercase letters, %d uppercase letters, %d symbols and %d numbers.\n\n", lowercase_count, uppercase_count, symbol_count, number_count);
}

int main()
{
    int length;
    
    printf("Welcome to the Secure Password Generator!\n");
    printf("How long do you want your password to be? (minimum 8): ");
    scanf("%d", &length);
    
    generate_password(length);
    
    return 0;
}
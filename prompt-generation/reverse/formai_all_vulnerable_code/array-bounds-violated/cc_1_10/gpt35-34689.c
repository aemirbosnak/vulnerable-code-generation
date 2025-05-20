//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: happy
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#define MAX_PASS_LEN 50 //Maximum length of password
#define NUM_OF_SPECIAL_CHAR 15 //Number of special characters we want in our password

// Function to generate a random number between to numbers 
int random_number_generator(int min, int max) 
{ 
    int num = (rand() % (max - min + 1)) + min; 
    return num; 
} 

// Function to generate random upper case letter
char random_uppercase()
{
    char ch = 'A' + (rand() % 26);
    return ch;
}

// Function to generate random lower case letter
char random_lowercase()
{
    char ch = 'a' + (rand() % 26);
    return ch;
}

// Function to generate random special character
char random_special_char()
{
    char special_char[] = {'!', '@', '#', '$', '%', '^', '&', '*', '+', '-', '/', '?', '<', '>', '|'};
    int index = random_number_generator(0, NUM_OF_SPECIAL_CHAR);
    return special_char[index];
}

// Main function 
int main()
{
    srand(time(NULL)); // Seeding the random number generator with time
    char password[MAX_PASS_LEN + 1]; //Array to store password

    // Initialize password array with null
    memset(password, 0, sizeof(password));

    int index = 0;

    // Generate random strings of various types and keep adding to password till we have maximum length of password
    while(index < MAX_PASS_LEN)
    {
        int type = random_number_generator(1,3); // Generate a random number between 1 and 3 to select which type of character to add
        // Type 1 - uppercase letter, Type 2 - lowercase letter, Type 3 - special character
        if(type == 1)
        {
            password[index++] = random_uppercase();
        }
        else if(type == 2)
        {
            password[index++] = random_lowercase();
        }
        else
        {
            password[index++] = random_special_char();
        }
    }

    printf("Your new secure password is: %s\n", password);

    return 0;
}
//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int length, choice; //variables to hold password length and user's choice of including characters
    printf("Welcome to the Secure Password Generator!\n");

    //get user input for password length
    do
    {
        printf("Enter the length of the password: ");
        scanf("%d", &length);
    } while (length <= 0);

    //get user input for including characters
    printf("Enter the type of characters you want to include:\n1. Alphabets only\n2. Alphabets and Numbers\n3. Alphabets, Numbers and Symbols\n");
    scanf("%d", &choice);

    char password[length+1]; //array to hold the generated password
    password[length] = '\0'; //set the last character to null
    
    srand(time(0)); //seed for random number generator
    
    //generate password based on user's choice
    switch(choice)
    {
        case 1: //only alphabets
        {
            for(int i=0; i<length; i++)
            {
                password[i] = 'a' + rand()%26; //random uppercase or lowercase alphabet
            }
            break;
        }
        case 2: //alphabets and numbers
        {
            for(int i=0; i<length; i++)
            {
                if(rand()%2) //50% chance of including alphabet
                    password[i] = 'a' + rand()%26;
                else
                    password[i] = '0' + rand()%10; //random number
            }
            break;
        }
        case 3: //alphabets, numbers and symbols
        {
            char symbols[] = "!@#$%^&*()_-+=[]{}\\|;:'\"<>,.?/~`"; //array of symbols to choose from
            
            for(int i=0; i<length; i++)
            {
                int choice = rand()%3; //randomly choose alphabets, numbers or symbols
                
                if(choice == 0) //alphabet
                    password[i] = 'a' + rand()%26;
                else if(choice == 1) //number
                    password[i] = '0' + rand()%10;
                else //symbol
                    password[i] = symbols[rand()%strlen(symbols)];
            }
            break;
        }
        default:
        {
            printf("Invalid choice! Please try again.\n");
            exit(EXIT_FAILURE);
        }
    }
    
    printf("Your password is: %s\n", password); //print the generated password
    
    return 0;
}
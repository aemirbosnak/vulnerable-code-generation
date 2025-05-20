//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

int main()
{
    srand(time(NULL)); //seed random number generator with system time
    char password[MAX_LENGTH+1]; //create array to hold password
    int length;
    
    printf("Welcome to the C Secure Password Generator\n\n");
    printf("Please enter the desired length of your password (between 8 and 16 characters): ");
    scanf("%d", &length);
    
    //validate user input for length of password
    while (length < MIN_LENGTH || length > MAX_LENGTH)
    {
        printf("\nInvalid input. Please enter a length between 8 and 16 characters: ");
        fflush(stdin); //clear input buffer
        scanf("%d", &length);
    }
    
    //create password by randomly selecting characters and appending to array
    for (int i = 0; i < length; i++)
    {
        int randNum = rand() % 74; //generate random number between 0 and 73 (inclusive)
        if (randNum < 10) //digits 0-9
        {
            password[i] = randNum + '0'; //add offset to get ASCII value of digit
        }
        else if (randNum < 36) //uppercase letters A-Z
        {
            password[i] = randNum + 'A' - 10; //add offset to get ASCII value of letter
        }
        else if (randNum < 62) //lowercase letters a-z
        {
            password[i] = randNum + 'a' - 36; //add offset to get ASCII value of letter
        }
        else //special characters !-#
        {
            password[i] = randNum + '!' - 62; //add offset to get ASCII value of character
        }
    }
    
    password[length] = '\0'; //add null terminator to end of password string
    
    printf("\nYour secure password is: %s\n", password);
    
    return 0;
}
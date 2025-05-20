//FormAI DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int generateNum(int lower, int upper) 
{ 
    int num = (rand() % 
        (upper - lower + 1)) + lower; 
    return num;
} 

int main()
{
    int random_num = generateNum(1,5); // Generate random number between 1-5
    int guessed_num;
    int attempts = 0;

    printf("Welcome to the guessing game!\n");
    printf("You have 3 attempts to guess the correct number between 1-5.\n");

    while(attempts < 3)
    {
        printf("Guess the number: ");
        scanf("%d", &guessed_num);

        if(guessed_num == random_num)
        {
            printf("Congratulations! You have guessed the correct number\n");
            break;
        }
        else
        {
            printf("Sorry, your guess is incorrect.\n");

            if(attempts == 2)
            {
                printf("Game Over! You have reached maximum attempts\n");
            }
            else
            {
                printf("Try Again!\n");
            }
        }

        attempts++;
    }

    printf("Thank you for playing the guessing game!\n");

    return 0;
}
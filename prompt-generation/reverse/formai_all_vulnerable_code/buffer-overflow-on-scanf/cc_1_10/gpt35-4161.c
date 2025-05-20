//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate a random number between lower and upper bounds
int generateRandomNumber(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    int guess, tries = 0;
    int lower = 1, upper = 100;

    //Seed the random number generator with the current time
    srand(time(NULL));

    //Generate a random number for the user to guess
    int number = generateRandomNumber(lower, upper);

    printf("Welcome to the Number Guessing game!\n");
    printf("I am thinking of a number between %d and %d. Can you guess it?\n", lower, upper);

    //Loop until the user guesses the correct number
    while(1)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        tries++;

        if(guess == number) //User guessed the correct number
        {
            printf("Congratulations! You guessed the number in %d tries.\n", tries);
            break;
        }
        else if(guess < number) //User's guess was too low
        {
            printf("Too low! Guess again.\n");
        }
        else //User's guess was too high
        {
            printf("Too high! Guess again.\n");
        }
    }

    printf("Thanks for playing the Number Guessing game!\n");

    return 0;
}
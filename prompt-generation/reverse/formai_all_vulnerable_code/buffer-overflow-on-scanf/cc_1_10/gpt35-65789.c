//FormAI DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 10

int main()
{
    int secret_number, guess, num_guesses = 0;
    
    srand(time(NULL)); //Seed the random number generator
    
    //Generate a random number between 1 and 100
    secret_number = rand() % 100 + 1;
    
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");
    
    while(num_guesses < MAX_GUESSES)
    {
        printf("Guess #%d: ", num_guesses + 1);
        scanf("%d", &guess);
        
        if(guess < 1 || guess > 100)
        {
            printf("Please guess a number between 1 and 100.\n");
            continue;
        }
        
        if(guess == secret_number)
        {
            printf("Congratulations! You guessed the number in %d guesses.\n", num_guesses + 1);
            break;
        }
        else if(guess < secret_number)
        {
            printf("Too low. ");
        }
        else
        {
            printf("Too high. ");
        }
        
        if(num_guesses == MAX_GUESSES - 1)
        {
            printf("Sorry, you're out of guesses. The number was %d.\n", secret_number);
        }
        else
        {
            printf("Guess again.\n");
        }
        
        num_guesses++;
    }
    
    return 0;
}
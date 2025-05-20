//FormAI DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between a range
int generateNumber(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    srand(time(NULL));
    
    int guesses = 0, guess;
    int max_guesses = 10, min = 1, max = 100;
    int secret_number = generateNumber(min, max);
    
    printf("Welcome to the Guessing Game!\n");
    printf("You have %d guesses to guess a number between %d and %d\n", max_guesses, min, max);
    
    while (guesses < max_guesses)
    {
        printf("Guess %d: ", guesses + 1);
        scanf("%d", &guess);
        
        if (guess < min || guess > max)
        {
            printf("Invalid guess! Guess must be between %d and %d\n", min, max);
            continue;
        }
        
        if (guess == secret_number)
        {
            printf("Congratulations! You guessed the secret number in %d guesses!\n", guesses + 1);
            break;
        }
        else if (guess < secret_number)
        {
            printf("The secret number is higher than %d\n", guess);
        }
        else
        {
            printf("The secret number is lower than %d\n", guess);
        }
        
        guesses++;
    }
    
    if (guesses == max_guesses)
    {
        printf("Game over! You could not guess the secret number in %d guesses. The secret number was %d\n", max_guesses, secret_number);
    }
    
    return 0;
}
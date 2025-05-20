//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function prototypes */
void play_game(int remaining_guesses, int secret_number);
int generate_random_number();

// main function
int main()
{
    int remaining_guesses = 5;
    int secret_number = generate_random_number();
    
    printf("==== Guess the Number Game ====\n\n");
    printf("You have 5 guesses to guess the secret number between 1 and 50.\n");
    printf("Good luck!\n\n");
    
    play_game(remaining_guesses, secret_number);
    
    printf("\nGame over. Thanks for playing!\n");
    return 0;
}

/* Function to play the game recursively */
void play_game(int remaining_guesses, int secret_number)
{
    int guess;
    
    // End game if no remaining guesses left
    if (remaining_guesses == 0)
    {
        printf("\nSorry, you ran out of guesses. The secret number was %d.\n", secret_number);
        return;
    }
    
    printf("\nYou have %d guesses remaining.\n", remaining_guesses);
    printf("Enter your guess: ");
    scanf("%d", &guess);
    
    // Check if guess is correct
    if (guess == secret_number)
    {
        printf("\nCongratulations! You guessed the secret number %d!\n", secret_number);
        return;
    }
    else
    {
        printf("Incorrect. ");
        if (guess < secret_number)
        {
            printf("Your guess was too low.\n");
        }
        else
        {
            printf("Your guess was too high.\n");
        }
        play_game(remaining_guesses - 1, secret_number); // recursive call
    }
}

/* Function to generate random number */
int generate_random_number()
{
    srand(time(0));
    int secret_number = rand() % 50 + 1; // generate random number between 1 and 50
    return secret_number;
}
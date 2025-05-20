//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game()
{
    // Variables
    int num_guess = 0;
    int guess_num = 0;
    int secret_num = rand() % 100 + 1;
    char answer;

    // Start the game loop
    while (num_guess < 5)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess_num);

        // Check if the guess is correct
        if (guess_num == secret_num)
        {
            printf("Congratulations! You guessed the number!\n");
            num_guess = 5;
        }
        else if (guess_num < secret_num)
        {
            printf("Your guess is too low. Try again.\n");
        }
        else
        {
            printf("Your guess is too high. Try again.\n");
        }

        // Increment the number of guesses
        num_guess++;
    }

    // End the game
    printf("Game over. The secret number was: %d\n", secret_num);
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    play_game();

    return 0;
}
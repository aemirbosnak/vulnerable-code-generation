//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

int main()
{
    int player_num, computer_num, current_num, guess_num, round_num = 1, score = 0;
    char answer;

    // Seed the random number generator
    srand(time(NULL));

    // Welcome the player
    printf("Welcome to the Number Guessing Game!\n");

    // Get the player's number
    printf("Please enter your desired number of rounds: ");
    scanf("%d", &round_num);

    // Loop for the number of rounds
    for (round_num; round_num > 0; round_num--)
    {
        // Set the computer's number
        computer_num = rand() % MAX_NUM + 1;

        // Get the player's guess
        printf("Guess a number between 1 and %d: ", MAX_NUM);
        scanf("%d", &guess_num);

        // Check if the guess is correct
        if (guess_num == computer_num)
        {
            // Increment the player's score
            score++;

            // Print a congratulatory message
            printf("Congratulations! You guessed the number!\n");
        }
        else
        {
            // Print an error message
            printf("Sorry, your guess is incorrect. The number was %d.\n", computer_num);
        }

        // Increment the round number
        round_num++;
    }

    // Print the player's score
    printf("Your final score is: %d\n", score);

    return 0;
}
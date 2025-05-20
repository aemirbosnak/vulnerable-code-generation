//Gemma-7B DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score = 0, round = 1, player_choice, computer_choice, game_over = 0;

    system("clear");

    printf("Welcome to the C Table Game!\n");
    printf("------------------------\n");

    while (!game_over)
    {
        // Player's turn
        printf("Enter your choice (1-3): ");
        scanf("%d", &player_choice);

        // Computer's turn
        computer_choice = rand() % 3 + 1;

        // Check if the game is over
        if (score >= 5)
        {
            game_over = 1;
            printf("Game Over! You won!");
        }
        else
        {
            // Calculate the winner
            if (player_choice == computer_choice)
            {
                score++;
                printf("It's a tie!");
            }
            else
            {
                score++;
                printf("You won!");
            }

            // Increment the round
            round++;
        }

        // Print the score and round
        printf("Score: %d\n", score);
        printf("Round: %d\n", round);
    }

    return 0;
}
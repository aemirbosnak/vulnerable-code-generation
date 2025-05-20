//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

void play_game()
{
    int choice, round = 1, player_1_points = 0, player_2_points = 0;

    // Welcome the players to the game
    printf("Welcome to Romeo and Juliet!\n");

    // Loop until one of the players reaches a score of 5
    while (player_1_points < 5 && player_2_points < 5)
    {
        // Display the current round and scores
        printf("Round %d:\n", round);
        printf("Player 1: %d points\n", player_1_points);
        printf("Player 2: %d points\n", player_2_points);

        // Get the player's choice
        printf("Enter your choice (1 for Romeo, 2 for Juliet): ");
        scanf("%d", &choice);

        // Check if the player's choice is valid
        if (choice < 1 || choice > 2)
        {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        // Simulate the outcome of the round
        switch (choice)
        {
            case 1:
                player_1_points++;
                printf("Romeo wins the round!\n");
                break;
            case 2:
                player_2_points++;
                printf("Juliet wins the round!\n");
                break;
        }

        // Increment the round number
        round++;
    }

    // Declare the winner
    if (player_1_points >= 5)
    {
        printf("Congratulations, Player 1! You have won the game!\n");
    }
    else
    {
        printf("Congratulations, Player 2! You have won the game!\n");
    }
}

int main()
{
    play_game();

    return 0;
}
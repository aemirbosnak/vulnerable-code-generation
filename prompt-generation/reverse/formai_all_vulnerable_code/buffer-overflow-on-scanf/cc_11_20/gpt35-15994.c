//FormAI DATASET v1.0 Category: Table Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize variables
    int chips = 10, bet = 0, player_move = 0, computer_move = 0;

    // Set up random number generator
    srand(time(0));

    // Game loop
    while (chips > 0)
    {
        // Get player's bet
        printf("You have %d chips. How many do you want to bet? ", chips);
        scanf("%d", &bet);

        // Check if bet is valid
        if (bet > chips || bet <= 0)
        {
            printf("Invalid bet\n");
            continue;
        }

        // Get player's move
        printf("Choose your move (1 for rock, 2 for paper, 3 for scissors): ");
        scanf("%d", &player_move);

        // Generate computer's move
        computer_move = rand() % 3 + 1;

        // Print moves
        printf("You played ");
        switch(player_move)
        {
            case 1:
                printf("rock");
                break;
            case 2:
                printf("paper");
                break;
            case 3:
                printf("scissors");
                break;
        }
        printf(", computer played ");
        switch(computer_move)
        {
            case 1:
                printf("rock");
                break;
            case 2:
                printf("paper");
                break;
            case 3:
                printf("scissors");
                break;
        }
        printf("\n");

        // Determine winner
        if (player_move == computer_move)
        {
            printf("Tie\n");
        }
        else if ((player_move == 1 && computer_move == 3) ||
                 (player_move == 2 && computer_move == 1) ||
                 (player_move == 3 && computer_move == 2))
        {
            printf("You win!\n");
            chips += bet;
        }
        else
        {
            printf("You lose\n");
            chips -= bet;
        }

        // Check if game is over
        if (chips == 0)
        {
            printf("Game over\n");
        }
    }

    return 0;
}
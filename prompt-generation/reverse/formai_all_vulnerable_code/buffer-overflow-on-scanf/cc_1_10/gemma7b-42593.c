//Gemma-7B DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

void play_game(int player_1_score, int player_2_score)
{
    int choice, player_1_move, player_2_move;

    // Get the player's choice
    printf("Enter your move (1, 2, 3, 4): ");
    scanf("%d", &choice);

    // Make the player's move
    switch (choice)
    {
        case 1:
            player_1_move = 1;
            break;
        case 2:
            player_1_move = 2;
            break;
        case 3:
            player_1_move = 3;
            break;
        case 4:
            player_1_move = 4;
            break;
        default:
            printf("Invalid move.\n");
            return;
    }

    // Check if the move is valid
    if (player_1_move < 1 || player_1_move > 4)
    {
        printf("Invalid move.\n");
        return;
    }

    // Make the opponent's move
    player_2_move = rand() % 4 + 1;

    // Update the scores
    player_1_score += player_1_move;
    player_2_score += player_2_move;

    // Check if the game is over
    if (player_1_score >= 10 || player_2_score >= 10)
    {
        printf("Game over! Player %d won.\n", player_1_score > player_2_score ? 1 : 2);
        return;
    }

    // Recursively play the game again
    play_game(player_1_score, player_2_score);
}

int main()
{
    int player_1_score = 0;
    int player_2_score = 0;

    // Play the game
    play_game(player_1_score, player_2_score);

    return 0;
}
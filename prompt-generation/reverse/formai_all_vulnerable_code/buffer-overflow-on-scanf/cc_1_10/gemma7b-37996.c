//Gemma-7B DATASET v1.0 Category: Table Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER 10

void play_game()
{
    int number_of_players = 2;
    int current_player = 0;
    int round = 1;
    int board[MAX_NUMBER] = {0};
    int guess_number;

    // Initialize the board
    board[0] = 1;
    board[MAX_NUMBER - 1] = 1;

    // Game loop
    while (board[MAX_NUMBER - 1] != number_of_players)
    {
        // Get the guess number from the current player
        printf("Player %d, it is your turn to guess a number: ", current_player + 1);
        scanf("%d", &guess_number);

        // Check if the guess number is valid
        if (guess_number < 0 || guess_number >= MAX_NUMBER)
        {
            printf("Invalid guess number. Please try again.\n");
            continue;
        }

        // Check if the guess number has already been made
        if (board[guess_number] == 1)
        {
            printf("Sorry, that number has already been guessed.\n");
            continue;
        }

        // Mark the guess number as made
        board[guess_number] = 1;

        // Increment the current player
        current_player = (current_player + 1) % number_of_players;

        // Increment the round
        round++;
    }

    // Print the winner
    printf("Congratulations, Player %d, you won the game!\n", current_player + 1);

    // Print the number of rounds
    printf("The number of rounds played was: %d\n", round);
}

int main()
{
    play_game();

    return 0;
}
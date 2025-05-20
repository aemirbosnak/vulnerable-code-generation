//Gemma-7B DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

int main()
{
    int num_players, game_round, current_player = 0, board[MAX_NUM][MAX_NUM] = {{0}}, winner = 0;
    char player_symbol;

    // Initialize the game board
    for (int i = 0; i < MAX_NUM; i++)
    {
        for (int j = 0; j < MAX_NUM; j++)
        {
            board[i][j] = 0;
        }
    }

    // Get the number of players
    printf("Enter the number of players (2-4): ");
    scanf("%d", &num_players);

    // Set the player symbol
    switch (num_players)
    {
        case 2:
            player_symbol = 'X';
            break;
        case 3:
            player_symbol = 'O';
            break;
        case 4:
            player_symbol = 'A';
            break;
    }

    // Start the game round
    game_round = 1;
    while (!winner && game_round <= MAX_NUM)
    {
        // Get the move of the current player
        int move_x, move_y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        // Validate the move
        if (move_x < 0 || move_x >= MAX_NUM || move_y < 0 || move_y >= MAX_NUM)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place the piece on the board
        board[move_x][move_y] = current_player;

        // Check if the current player has won
        winner = check_winner(board, current_player);

        // Increment the game round
        game_round++;

        // Switch to the next player
        current_player = (current_player + 1) % num_players;
    }

    // Print the winner
    if (winner)
    {
        printf("The winner is: %c\n", player_symbol);
    }
    else
    {
        printf("It's a draw.\n");
    }

    return 0;
}

int check_winner(int **board, int current_player)
{
    // Check rows
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (board[0][i] == current_player && board[1][i] == current_player && board[2][i] == current_player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < MAX_NUM; j++)
    {
        if (board[j][0] == current_player && board[j][1] == current_player && board[j][2] == current_player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player)
    {
        return 1;
    }
    if (board[0][2] == current_player && board[1][1] == current_player && board[2][0] == current_player)
    {
        return 1;
    }

    // No winner
    return 0;
}
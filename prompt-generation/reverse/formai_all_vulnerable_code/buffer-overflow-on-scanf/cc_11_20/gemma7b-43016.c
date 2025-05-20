//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>

#define MAX_SIZE 10

int main()
{
    int board[MAX_SIZE][MAX_SIZE] = { 0 };
    int player_1_pieces = 5;
    int player_2_pieces = 5;

    // Game setup
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = -1;
        }
    }

    // Place pieces
    board[2][2] = 1;
    board[3][3] = 1;
    board[4][4] = 1;
    board[5][5] = 1;
    board[2][5] = 2;
    board[3][4] = 2;
    board[4][2] = 2;
    board[5][3] = 2;

    // Game loop
    int game_over = 0;
    while (!game_over)
    {
        // Get player 1's move
        int move_1_x, move_1_y;
        printf("Enter move for player 1 (x, y): ");
        scanf("%d %d", &move_1_x, &move_1_y);

        // Validate move
        if (board[move_1_x][move_1_y] != -1 || move_1_x < 0 || move_1_x >= MAX_SIZE || move_1_y < 0 || move_1_y >= MAX_SIZE)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place piece
        board[move_1_x][move_1_y] = 1;

        // Check if player 1 won
        if (board[move_1_x][move_1_y] == 5)
        {
            game_over = 1;
            printf("Player 1 won!\n");
        }

        // Get player 2's move
        int move_2_x, move_2_y;
        printf("Enter move for player 2 (x, y): ");
        scanf("%d %d", &move_2_x, &move_2_y);

        // Validate move
        if (board[move_2_x][move_2_y] != -1 || move_2_x < 0 || move_2_x >= MAX_SIZE || move_2_y < 0 || move_2_y >= MAX_SIZE)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place piece
        board[move_2_x][move_2_y] = 2;

        // Check if player 2 won
        if (board[move_2_x][move_2_y] == 5)
        {
            game_over = 1;
            printf("Player 2 won!\n");
        }
    }

    return 0;
}
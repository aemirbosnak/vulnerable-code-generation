//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, x, y, player1_score = 0, player2_score = 0;
    char board[10][10] = {{0}};

    printf("Enter the number of rows (n): ");
    scanf("%d", &n);

    printf("Enter the number of columns (m): ");
    scanf("%d", &m);

    // Create the game board
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            board[i][j] = '0';
        }
    }

    // Place the first player's piece
    printf("Enter the row number for the first player's piece: ");
    scanf("%d", &x);

    printf("Enter the column number for the first player's piece: ");
    scanf("%d", &y);

    board[x][y] = '1';

    // Place the second player's piece
    printf("Enter the row number for the second player's piece: ");
    scanf("%d", &x);

    printf("Enter the column number for the second player's piece: ");
    scanf("%d", &y);

    board[x][y] = '2';

    // Game loop
    while (player1_score != 5 && player2_score != 5)
    {
        // Get the player's move
        printf("Enter the row number of your move: ");
        scanf("%d", &x);

        printf("Enter the column number of your move: ");
        scanf("%d", &y);

        // Check if the move is valid
        if (board[x][y] == '0' && board[x][y] != '1' && board[x][y] != '2')
        {
            // Invalid move, prompt the player to make another move
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place the player's piece on the board
        board[x][y] = player1_score == 0 ? '1' : '2';

        // Check if the player has won
        if (board[x][y] == '1' && player1_score == 0)
        {
            player1_score = 5;
        }
        else if (board[x][y] == '2' && player2_score == 0)
        {
            player2_score = 5;
        }
    }

    // Game over
    printf("Game over!\n");

    // Print the game board
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Display the winner
    if (player1_score == 5)
    {
        printf("Player 1 won!\n");
    }
    else if (player2_score == 5)
    {
        printf("Player 2 won!\n");
    }
    else
    {
        printf("It's a draw!\n");
    }

    return 0;
}
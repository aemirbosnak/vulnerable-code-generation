//FormAI DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

// Function to display the current status of the board
void display_board(int board[ROW][COL])
{
    printf("\n");
    printf("  CURRENT BOARD\n");
    printf("---------------\n");

    for (int i=0; i<ROW; i++)
    {
        for (int j=0; j<COL; j++)
        {
            if (board[i][j] == 1)
                printf(" X |");
            else if (board[i][j] == -1)
                printf(" O |");
            else
                printf("   |");
        }
        printf("\n---------------\n");
    }
}

// Function to check if someone has won the game
int check_win(int board[ROW][COL])
{
    // Check rows for a win
    for (int i=0; i<ROW; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
    }

    // Check columns for a win
    for (int j=0; j<COL; j++)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return board[0][j];
    }

    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    // If no one has won yet, return 0
    return 0;
}

int main()
{
    int board[ROW][COL] = {{0,0,0}, {0,0,0}, {0,0,0}};
    int player = 1;
    int turn_count = 0;

    printf("\n  WELCOME TO TIC-TAC-TOE!\n");
    printf("-----------------------------\n");
    printf("INSTRUCTIONS: \n");
    printf("Player 1 is X and Player 2 is O.\n");
    printf("Enter the row number and column number to place your mark on the board.\n");

    while (1)
    {
        display_board(board);

        int row, col;
        printf("\nPlayer %d's turn. Enter row and column number: ", player);
        scanf("%d %d", &row, &col);

        if (board[row-1][col-1] != 0)
        {
            printf("Error: That spot is already taken. Try again.\n");
            continue;
        }

        // Place the mark on the board
        board[row-1][col-1] = player;

        // Check if the player has won
        int winner = check_win(board);

        if (winner != 0)
        {
            display_board(board);
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        // If no one has won and we've reached turn 9, it's a tie
        turn_count++;
        if (turn_count == 9)
        {
            display_board(board);
            printf("\nIt's a tie!\n");
            break;
        }

        // Switch to the other player
        if (player == 1)
            player = -1;
        else
            player = 1;
    }

    return 0;
}
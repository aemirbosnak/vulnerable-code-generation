//FormAI DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to print the game board
void printBoard(char board[3][3])
{
    printf("\n\t   1   2   3 \n");
    printf("\t  ___ ___ ___\n");
    for(int i=0; i<3; i++)
    {
        printf("\t |");
        for(int j=0; j<3; j++)
        {
            printf(" %c |", board[i][j]);
        }
        printf(" %d\n", i+1);
        printf("\t |___|___|___|\n");
    }
}

// Function to check if there's a winner
char checkWinner(char board[3][3])
{
    for(int i=0; i<3; i++)
    {
        // Check rows for a winner
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return board[i][0];
        }
        // Check columns for a winner
        else if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    // Check diagonals for a winner
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return board[0][0];
    }
    else if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return board[0][2];
    }
    return ' ';
}

int main()
{
    printf("\n\t----------------------\n");
    printf("\t  Welcome to Tic Tac Toe\n");
    printf("\t----------------------\n\n");

    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    printBoard(board);
    int turn = 0;
    char winner = ' ';

    while(turn < 9 && winner == ' ')
    {
        char player = (turn % 2 == 0) ? 'X' : 'O';
        int row, column;

        printf("\n %c's turn. Enter row and column (ex. 1,2): ", player);
        scanf("%d,%d", &row, &column);

        if(board[row-1][column-1] != 'X' && board[row-1][column-1] != 'O')
        {
            board[row-1][column-1] = player;
            turn++;
        }
        else
        {
            printf("\nThat cell is already occupied. Please choose another one.\n");
        }

        printBoard(board);

        winner = checkWinner(board);
    }

    if(winner == ' ')
    {
        printf("\nIt's a tie!\n");
    }
    else
    {
        printf("\n%c wins!\n", winner);
    }

    printf("\nThank you for playing!\n");

    return 0;
}
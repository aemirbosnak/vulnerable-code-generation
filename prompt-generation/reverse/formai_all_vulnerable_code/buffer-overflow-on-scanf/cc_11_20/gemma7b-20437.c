//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_Players 2

int main()
{
    int numPlayers = MAX_Players;
    char board[6][6] = {{'0', '0', '0', '0', '0', '0'},
                              {'0', '0', '0', '0', '0', '0'},
                              {'0', '0', '0', '0', '0', '0'},
                              {'0', '0', '0', '0', '0', '0'},
                              {'0', '0', '0', '0', '0', '0'},
                              {'0', '0', '0', '0', '0', '0'}};

    int playerTurn = 0;
    int gameWon = 0;

    for (int round = 0; round < 5; round++)
    {
        system("cls");
        for (int r = 0; r < 6; r++)
        {
            for (int c = 0; c < 6; c++)
            {
                printf("%c ", board[r][c]);
            }
            printf("\n");
        }

        printf("It is player %d's turn.\n", playerTurn + 1);

        int row, column;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &column);

        if (board[row][column] != '0')
        {
            printf("That space is already taken.\n");
            continue;
        }

        board[row][column] = playerTurn + 1;

        // Check if the player has won
        if (checkWin(board, playerTurn))
        {
            gameWon = 1;
            break;
        }

        // Switch turns
        playerTurn = (playerTurn + 1) % numPlayers;
    }

    system("cls");
    for (int r = 0; r < 6; r++)
    {
        for (int c = 0; c < 6; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }

    if (gameWon)
    {
        printf("Player %d won the game!\n", playerTurn + 1);
    }
    else
    {
        printf("It's a draw.\n");
    }

    return 0;
}

int checkWin(char board[][6], int playerTurn)
{
    // Check rows
    for (int r = 0; r < 6; r++)
    {
        if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] == playerTurn)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < 6; c++)
    {
        if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] == playerTurn)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == playerTurn)
    {
        return 1;
    }

    if (board[0][5] == board[1][4] && board[0][5] == board[2][3] && board[0][5] == playerTurn)
    {
        return 1;
    }

    return 0;
}
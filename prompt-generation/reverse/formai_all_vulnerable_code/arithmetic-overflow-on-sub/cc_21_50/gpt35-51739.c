//FormAI DATASET v1.0 Category: Table Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawBoard(int board[3][3]);
int checkWin(int board[3][3]);
int getHumanMove(int board[3][3]);
void getComputerMove(int board[3][3], int *row, int *column);

int main(void)
{
    int board[3][3] = {0};
    int turn;
    int winner = 0;

    srand(time(NULL));

    printf("Welcome to the Tic Tac Toe game!\n");
    printf("You are X and the computer is O.\n");

    turn = rand() % 2; // randomly determine who goes first

    while (!winner)
    {
        drawBoard(board);

        if (turn == 0) // human's turn
        {
            int row, column;
            printf("It's your turn! Enter a row and column (ex: 1 2): ");
            scanf("%d %d", &row, &column);

            if (board[row-1][column-1] != 0) // spot is already taken
            {
                printf("That spot is already taken. Try again.\n");
                continue;
            }
            else // spot is available
            {
                board[row-1][column-1] = 1; // set move to X
                turn = 1; // switch to computer's turn
            }
        }
        else // computer's turn
        {
            int row, column;
            printf("It's the computer's turn.\n");
            getComputerMove(board, &row, &column);
            board[row][column] = -1; // set move to O
            turn = 0; // switch to human's turn
        }

        winner = checkWin(board);
    }

    drawBoard(board);

    if (winner == 1) // human wins
    {
        printf("Congratulations! You win!\n");
    }
    else // computer wins
    {
        printf("Sorry, the computer wins. Better luck next time!\n");
    }

    return 0;
}

void drawBoard(int board[3][3])
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0] == 1 ? 'X' : board[0][0] == -1 ? 'O' : ' ', board[0][1] == 1 ? 'X' : board[0][1] == -1 ? 'O' : ' ', board[0][2] == 1 ? 'X' : board[0][2] == -1 ? 'O' : ' ');
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0] == 1 ? 'X' : board[1][0] == -1 ? 'O' : ' ', board[1][1] == 1 ? 'X' : board[1][1] == -1 ? 'O' : ' ', board[1][2] == 1 ? 'X' : board[1][2] == -1 ? 'O' : ' ');
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0] == 1 ? 'X' : board[2][0] == -1 ? 'O' : ' ', board[2][1] == 1 ? 'X' : board[2][1] == -1 ? 'O' : ' ', board[2][2] == 1 ? 'X' : board[2][2] == -1 ? 'O' : ' ');
    printf("\n");
}

int checkWin(int board[3][3])
{
    // check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if (board[i][0] == 1) // human wins
            {
                return 1;
            }
            else if (board[i][0] == -1) // computer wins
            {
                return -1;
            }
        }
    }

    // check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if (board[0][i] == 1) // human wins
            {
                return 1;
            }
            else if (board[0][i] == -1) // computer wins
            {
                return -1;
            }
        }
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[0][0] == 1) // human wins
        {
            return 1;
        }
        else if (board[0][0] == -1) // computer wins
        {
            return -1;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[0][2] == 1) // human wins
        {
            return 1;
        }
        else if (board[0][2] == -1) // computer wins
        {
            return -1;
        }
    }

    // check for tie
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 0)
            {
                count++;
            }
        }
    }
    if (count == 9)
    {
        return 2; // tie game
    }

    return 0; // no winner yet
}

int getHumanMove(int board[3][3])
{
    int row, column;

    do
    {
        printf("Enter a row and column [1-3], separated by a space: ");
        scanf("%d %d", &row, &column);

        if (board[row-1][column-1] != 0)
        {
            printf("That spot is already taken. Try again.\n");
        }

    } while (board[row-1][column-1] != 0);

    return (row-1)*3 + (column-1);
}

void getComputerMove(int board[3][3], int *row, int *column)
{
    int moveFound = 0;

    // try to win
    for (int i = 0; i < 3 && !moveFound; i++)
    {
        if (board[i][0] == -1 && board[i][1] == -1 && board[i][2] == 0)
        {
            *row = i;
            *column = 2;
            moveFound = 1;
        }
        else if (board[i][0] == -1 && board[i][1] == 0 && board[i][2] == -1)
        {
            *row = i;
            *column = 1;
            moveFound = 1;
        }
        else if (board[i][0] == 0 && board[i][1] == -1 && board[i][2] == -1)
        {
            *row = i;
            *column = 0;
            moveFound = 1;
        }
    }
    for (int i = 0; i < 3 && !moveFound; i++)
    {
        if (board[0][i] == -1 && board[1][i] == -1 && board[2][i] == 0)
        {
            *row = 2;
            *column = i;
            moveFound = 1;
        }
        else if (board[0][i] == -1 && board[1][i] == 0 && board[2][i] == -1)
        {
            *row = 1;
            *column = i;
            moveFound = 1;
        }
        else if (board[0][i] == 0 && board[1][i] == -1 && board[2][i] == -1)
        {
            *row = 0;
            *column = i;
            moveFound = 1;
        }
    }
    if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == 0 && !moveFound)
    {
        *row = 2;
        *column = 2;
        moveFound = 1;
    }
    else if (board[0][0] == -1 && board[1][1] == 0 && board[2][2] == -1 && !moveFound)
    {
        *row = 1;
        *column = 1;
        moveFound = 1;
    }
    else if (board[0][0] == 0 && board[1][1] == -1 && board[2][2] == -1 && !moveFound)
    {
        *row = 0;
        *column = 0;
        moveFound = 1;
    }

    if (board[0][2] == -1 && board[1][1] == -1 && board[2][0] == 0 && !moveFound)
    {
        *row = 2;
        *column = 0;
        moveFound = 1;
    }
    else if (board[0][2] == -1 && board[1][1] == 0 && board[2][0] == -1 && !moveFound)
    {
        *row = 1;
        *column = 1;
        moveFound = 1;
    }
    else if (board[0][2] == 0 && board[1][1] == -1 && board[2][0] == -1 && !moveFound)
    {
        *row = 0;
        *column = 2;
        moveFound = 1;
    }

    // block human from winning
    for (int i = 0; i < 3 && !moveFound; i++)
    {
        if (board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 0)
        {
            *row = i;
            *column = 2;
            moveFound = 1;
        }
        else if (board[i][0] == 1 && board[i][1] == 0 && board[i][2] == 1)
        {
            *row = i;
            *column = 1;
            moveFound = 1;
        }
        else if (board[i][0] == 0 && board[i][1] == 1 && board[i][2] == 1)
        {
            *row = i;
            *column = 0;
            moveFound = 1;
        }
    }
    for (int i = 0; i < 3 && !moveFound; i++)
    {
        if (board[0][i] == 1 && board[1][i] == 1 && board[2][i] == 0)
        {
            *row = 2;
            *column = i;
            moveFound = 1;
        }
        else if (board[0][i] == 1 && board[1][i] == 0 && board[2][i] == 1)
        {
            *row = 1;
            *column = i;
            moveFound = 1;
        }
        else if (board[0][i] == 0 && board[1][i] == 1 && board[2][i] == 1)
        {
            *row = 0;
            *column = i;
            moveFound = 1;
        }
    }
    if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 0 && !moveFound)
    {
        *row = 2;
        *column = 2;
        moveFound = 1;
    }
    else if (board[0][0] == 1 && board[1][1] == 0 && board[2][2] == 1 && !moveFound)
    {
        *row = 1;
        *column = 1;
        moveFound = 1;
    }
    else if (board[0][0] == 0 && board[1][1] == 1 && board[2][2] == 1 && !moveFound)
    {
        *row = 0;
        *column = 0;
        moveFound = 1;
    }

    if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 0 && !moveFound)
    {
        *row = 2;
        *column = 0;
        moveFound = 1;
    }
    else if (board[0][2] == 1 && board[1][1] == 0 && board[2][0] == 1 && !moveFound)
    {
        *row = 1;
        *column = 1;
        moveFound = 1;
    }
    else if (board[0][2] == 0 && board[1][1] == 1 && board[2][0] == 1 && !moveFound)
    {
        *row = 0;
        *column = 2;
        moveFound = 1;
    }

    if (!moveFound) // make a random move
    {
        do
        {
            *row = rand() % 3;
            *column = rand() % 3;
        } while (board[*row][*column] != 0);
    }
}
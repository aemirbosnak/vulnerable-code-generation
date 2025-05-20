//Falcon-180B DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

int board[ROWS][COLS] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
int player = 1;
int choice;
int flag = 0;

void drawBoard()
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin()
{
    int i;

    // Check rows
    for (i = 0; i < ROWS; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < COLS; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return 1;
    }

    return 0;
}

int main()
{
    srand(time(NULL));
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    while (1)
    {
        system("clear");
        drawBoard();
        printf("\nPlayer %d's turn\n", player);

        printf("Enter your choice (1-%d): ", ROWS * COLS - 1);
        scanf("%d", &choice);
        choice--;

        if (choice < 0 || choice >= ROWS * COLS - 1)
        {
            printf("Invalid choice\n");
            continue;
        }

        if (board[choice / COLS][choice % COLS]!= 0)
        {
            printf("Cell already marked\n");
            continue;
        }

        board[choice / COLS][choice % COLS] = player;
        player = (player == 1)? 2 : 1;

        if (checkWin())
        {
            printf("\nPlayer %d wins!\n", player);
            break;
        }
    }

    return 0;
}
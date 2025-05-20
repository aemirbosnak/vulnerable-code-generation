//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Cell
{
    int row;
    int col;
    char state;
} Cell;

Cell cells[BOARD_SIZE][BOARD_SIZE] = {{
    {0, 0, ' '},
    {1, 0, ' '},
    {2, 0, ' '},
    {0, 1, ' '},
    {1, 1, ' '},
    {2, 1, ' '},
    {0, 2, ' '},
    {1, 2, ' '},
    {2, 2, ' '}
}};

void initializeBoard()
{
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            cells[r][c].state = ' ';
        }
    }
}

void printBoard()
{
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            printf("%c ", cells[r][c].state);
        }
        printf("\n");
    }
}

int checkWin(char player)
{
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        if (cells[r][0].state == player && cells[r][1].state == player && cells[r][2].state == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++)
    {
        if (cells[0][c].state == player && cells[1][c].state == player && cells[2][c].state == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (cells[0][0].state == player && cells[1][1].state == player && cells[2][2].state == player)
    {
        return 1;
    }
    else if (cells[0][2].state == player && cells[1][1].state == player && cells[2][0].state == player)
    {
        return 1;
    }

    return 0;
}

int main()
{
    initializeBoard();

    char player = 'X';
    int move = 0;

    while (!checkWin(player) && move < 9)
    {
        printBoard();

        printf("Enter your move (1-9): ");
        scanf("%d", &move);

        int validMove = 0;
        while (!validMove)
        {
            if (move < 1 || move > 9)
            {
                printf("Invalid move. Please try again: ");
                scanf("%d", &move);
            }
            else
            {
                validMove = 1;
            }
        }

        cells[move / BOARD_SIZE][move % BOARD_SIZE].state = player;
        move++;
    }

    printBoard();

    if (checkWin(player) == 1)
    {
        printf("Congratulations! You won!");
    }
    else
    {
        printf("It's a draw!");
    }

    return 0;
}
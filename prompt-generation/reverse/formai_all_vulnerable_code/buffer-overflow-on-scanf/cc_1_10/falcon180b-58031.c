//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define WIDTH 3
#define HEIGHT 3

int board[SIZE][SIZE] = {0};
int player = 1;
int choice;
int flag = 0;
int win = 0;

void drawBoard()
{
    int i, j;
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            if(board[i][j] == 1)
                printf("X ");
            else if(board[i][j] == 2)
                printf("O ");
            else
                printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void placeMark(int row, int col)
{
    if(row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == 0)
    {
        board[row][col] = player;
        win = checkWin();
        if(win)
        {
            printf("Player %d wins!\n", player);
            flag = 1;
        }
        else if(flag == 0)
            player = (player == 1)? 2 : 1;
    }
    else
        printf("Invalid move!\n");
}

int checkWin()
{
    int i, j;
    // Check rows
    for(i = 0; i < SIZE; i++)
    {
        if(board[i][0]!= 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
    }
    // Check columns
    for(j = 0; j < SIZE; j++)
    {
        if(board[0][j]!= 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return 1;
    }
    // Check diagonals
    if(board[0][0]!= 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if(board[0][2]!= 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

int main()
{
    srand(time(NULL));
    int i, j;
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            board[i][j] = 0;
        }
    }
    do
    {
        system("clear");
        drawBoard();
        printf("Player %d's turn.\n", player);
        printf("Enter row and column: ");
        scanf("%d%d", &i, &j);
        placeMark(i - 1, j - 1);
        if(flag == 0)
        {
            player = (player == 1)? 2 : 1;
            printf("Player %d's turn.\n", player);
        }
    } while(flag == 0);
    return 0;
}
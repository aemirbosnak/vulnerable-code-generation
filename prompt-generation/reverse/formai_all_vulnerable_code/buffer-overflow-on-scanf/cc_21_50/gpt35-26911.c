//FormAI DATASET v1.0 Category: Checkers Game ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

#define SIZE 8

int main()
{
    int i, j, rows, cols, move;
    char board[SIZE][SIZE] = {
        {'R', 'B', 'R', 'B', 'R', 'B', 'R', 'B'},
        {'B', 'R', 'B', 'R', 'B', 'R', 'B', 'R'},
        {'R', 'B', 'R', 'B', 'R', 'B', 'R', 'B'},
        {'B', 'R', 'B', 'R', 'B', 'R', 'B', 'R'},
        {'R', 'B', 'R', 'B', 'R', 'B', 'R', 'B'},
        {'B', 'R', 'B', 'R', 'B', 'R', 'B', 'R'},
        {'R', 'B', 'R', 'B', 'R', 'B', 'R', 'B'},
        {'B', 'R', 'B', 'R', 'B', 'R', 'B', 'R'}
    };

    printf("NOTE: R represents the Red player & B represents the Black Player. \n\n");

    for(move = 1; move <= 15; move++)
    {
        printf("\n MOVE %d \n\n", move);
        for(rows = 0; rows < SIZE; rows++)
        {
            for(cols = 0; cols < SIZE; cols++)
            {
                printf("%c\t", board[rows][cols]);
            }
            printf("\n\n\n");
        }
        printf("\n");

        if(move % 2 != 0)
            printf("Player: RED\n");
        else
            printf("Player: BLACK\n");

        printf("Enter the position of piece you want to move (eg. 2 5): ");
        scanf("%d %d", &i, &j);

        printf("Enter the position where you want to move the piece: ");
        scanf("%d %d", &rows, &cols);

        printf("\n");

        if(board[i][j] == 'B')
        {
            if(move % 2 != 0)
            {
                if(rows > i)
                {
                    printf("Invalid Move. Try Again\n");
                    move--;
                    continue;
                }
                else if(rows < i-2 || rows < 0 || cols < 0 || cols > 7)
                {
                    printf("Invalid Move. Try Again\n");
                    move--;
                    continue;
                }
                else if(board[rows][cols] != '-')
                {
                    printf("Space already occupied. Try again!\n");
                    move--;
                    continue;
                }
                else
                {
                    board[rows][cols] = 'B';
                    board[i][j] = '-';
                }
            }
            else
            {
                printf("Not your turn. Try again!\n");
                move--;
                continue;
            }
        }
        else if(board[i][j] == 'R')
        {
            if(move % 2 == 0)
            {
                if(rows < i)
                {
                    printf("Invalid move. Try again!\n");
                    move--;
                    continue;
                }
                else if(rows > i+2 || rows > 7 || cols < 0 || cols > 7)
                {
                    printf("Invalid Move. Try Again\n");
                    move--;
                    continue;
                }
                else if(board[rows][cols] != '-')
                {
                    printf("Space already occupied. Try again!\n");
                    move--;
                    continue;
                }
                else
                {
                    board[rows][cols] = 'R';
                    board[i][j] = '-';
                }
            }
            else
            {
                printf("Not your turn. Try again!\n");
                move--;
                continue;
            }
        }
        else
        {
            printf("No piece found. Try again!\n");
            move--;
            continue;
        }
    }

    return 0;
}
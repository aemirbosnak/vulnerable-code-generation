//FormAI DATASET v1.0 Category: Table Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int table[3][3] = { {0,0,0},
                    {0,0,0},
                    {0,0,0} };

int checkWin()
{
    for(int i = 0; i < 3; i++)
    {
        if (table[i][0] == table[i][1] && table[i][1] == table[i][2])
            return table[i][0];
        if (table[0][i] == table[1][i] && table[1][i] == table[2][i])
            return table[0][i];
    }

    if (table[0][0] == table[1][1] && table[1][1] == table[2][2])
        return table[0][0];

    if (table[0][2] == table[1][1] && table[1][1] == table[2][0])
        return table[0][2];

    return 0;
}

void printTable()
{
    printf("   1   2   3\n");
    for(int i = 0; i < 3; i++)
    {
        printf("%d ", i+1);
        for(int j = 0; j < 3; j++)
        {
            if (table[i][j] == 0)
                printf("|   ");
            else if (table[i][j] == 1)
                printf("| X ");
            else
                printf("| O ");
        }
        printf("|\n");
    }
}

int main()
{
    srand(time(NULL));
    int player = 1;
    int turn = 1;
    int done = 0;
    int row, col;

    printf("Welcome to Table Game!\n");

    while (!done)
    {
        printf("Turn %d:\n", turn);
        printTable();

        if (player == 1)
            printf("Player X, enter row and column: ");
        else
            printf("Player O, enter row and column: ");

        scanf("%d %d", &row, &col);
        row--;
        col--;
        if (table[row][col] != 0)
        {
            printf("That space is already taken!\n");
            continue;
        }

        table[row][col] = player;

        if (checkWin())
        {
            printf("Player %d wins!!!\n", player);
            done = 1;
        }
        else if (turn == 9)
        {
            printf("It's a tie!!!\n");
            done = 1;
        }
        player = (player == 1) ? 2 : 1;
        turn++;
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3

void printTable(int table[][COLUMNS]);
void play(int table[][COLUMNS], int player);
int checkWinner(int table[][COLUMNS]);

int main()
{
    int table[ROWS][COLUMNS] = {{0}};
    int player = 1;
    int winner = 0;

    srand(time(NULL));

    printf("Welcome to the C Table Game!\n");
    printf("Player 1 is X and Player 2 is O\n");

    while (winner == 0)
    {
        printTable(table);
        play(table, player);
        winner = checkWinner(table);
        if (winner == 0)
        {
            player = (player == 1) ? 2 : 1;
        }
    }

    printf("Player %d has won the game!\n", winner);

    return 0;  
}

void printTable(int table[][COLUMNS])
{
    printf("\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            printf("|%c|", (table[i][j] == 0) ? ' ' : (table[i][j] == 1) ? 'X' : 'O');
        }
        printf("\n");
    }
}

void play(int table[][COLUMNS], int player)
{
    int row, column;

    printf("Player %d, enter your move (row column): ", player);
    scanf("%d %d", &row, &column);

    if (table[row-1][column-1] == 0)
    {
        table[row-1][column-1] = player;
    }
    else
    {
        printf("That position is already occupied. Please try again.\n");
        play(table, player);
    }
}

int checkWinner(int table[][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
    {
        if ((table[i][0] == table[i][1]) && (table[i][1] == table[i][2]))
        {
            return table[i][0];
        }
    }

    for (int j = 0; j < COLUMNS; j++)
    {
        if ((table[0][j] == table[1][j]) && (table[1][j] == table[2][j]))
        {
            return table[0][j];
        }
    }

    if ((table[0][0] == table[1][1]) && (table[1][1] == table[2][2]))
    {
        return table[0][0];
    }
    if ((table[0][2] == table[1][1]) && (table[1][1] == table[2][0]))
    {
        return table[1][1];
    }

    return 0;
}
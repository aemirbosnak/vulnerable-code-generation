//FormAI DATASET v1.0 Category: Table Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void createTable(char table[][COLS]);
void displayTable(char table[][COLS], int player);
int checkWin(char table[][COLS], char symbol);

int main()
{
    char table[ROWS][COLS];
    int player = 1;
    int choice, row, col;
    char symbol;
    createTable(table);

    do
    {
        displayTable(table, player);
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);

        row = --choice / ROWS;
        col = choice % COLS;

        symbol = (player == 1) ? 'X' : 'O';

        if (table[row][col] == 'X' || table[row][col] == 'O')
        {
            printf("Invalid move! Try again.\n");
            player--;
            getchar();
            continue;
        }

        table[row][col] = symbol;

    } while (!checkWin(table, symbol) && choice < 9);

    displayTable(table, player);

    if (checkWin(table, symbol))
        printf("Player %d has won!\n", player);
    else
        printf("Game is tied!\n");

    return 0;
}

void createTable(char table[][COLS])
{
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            table[i][j] = rand() % ('Z' - 'A' + 1) + 'A';
        }
    }
}

void displayTable(char table[][COLS], int player)
{
    system("clear");

    printf("Player %d - X | Player %d - O\n\n", 1, 2);

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf(" %c ", table[i][j]);
            if (j < COLS - 1)
                printf("|");
        }
        printf("\n");

        if (i < ROWS - 1)
        {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int checkWin(char table[][COLS], char symbol)
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        if ((table[i][0] == symbol) && (table[i][1] == symbol) && (table[i][2] == symbol))
            return 1;
    }

    for (i = 0; i < COLS; i++)
    {
        if ((table[0][i] == symbol) && (table[1][i] == symbol) && (table[2][i] == symbol))
            return 1;
    }

    if ((table[0][0] == symbol) && (table[1][1] == symbol) && (table[2][2] == symbol))
        return 1;

    if ((table[0][2] == symbol) && (table[1][1] == symbol) && (table[2][0] == symbol))
        return 1;

    return 0;
}
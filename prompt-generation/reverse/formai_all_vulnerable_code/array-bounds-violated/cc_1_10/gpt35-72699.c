//FormAI DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void InitializeBoard(char board[][COLS]);
void ShuffleBoard(char board[][COLS]);
void DisplayBoard(char board[][COLS], char revealed[][COLS]);
int IsGameOver(char revealed[][COLS]);

int main()
{
    char board[ROWS][COLS];
    char revealed[ROWS][COLS] = {0};
    int row1, col1, row2, col2;
    int count = 0;

    srand(time(NULL)); // Seed the random number generator

    InitializeBoard(board);
    ShuffleBoard(board);

    while(!IsGameOver(revealed))
    {
        printf("\n\n\n");
        DisplayBoard(board, revealed);

        printf("Enter the coordinates (row, col) of the first card you want to reveal: ");
        scanf("%d %d", &row1, &col1);

        if(revealed[row1][col1])
        {
            printf("That card is already revealed. Try again.\n");
            continue;
        }

        revealed[row1][col1] = board[row1][col1];

        printf("\n\n\n");
        DisplayBoard(board, revealed);

        printf("Enter the coordinates (row, col) of the second card you want to reveal: ");
        scanf("%d %d", &row2, &col2);

        if(revealed[row2][col2])
        {
            printf("That card is already revealed. Try again.\n");
            revealed[row1][col1] = 0; // Unreveal the first card
            continue;
        }

        revealed[row2][col2] = board[row2][col2];

        if(board[row1][col1] == board[row2][col2])
        {
            printf("\nMATCH FOUND!\n");
            count++;
        }
        else
        {
            printf("\nNO MATCH. TRY AGAIN.\n");
            revealed[row1][col1] = 0; // Unreveal the first card
            revealed[row2][col2] = 0; // Unreveal the second card
        }
    }

    printf("\n\n\nCONGRATULATIONS! YOU'VE WON THE GAME IN %d MOVES!\n", count);

    return 0;
}

void InitializeBoard(char board[][COLS])
{
    char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};

    int numPairs = ROWS * COLS / 2;
    int pairsPlaced = 0;

    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(pairsPlaced < numPairs)
            {
                board[i][j] = symbols[pairsPlaced];
                pairsPlaced++;
            }
            else
            {
                board[i][j] = board[rand() % i][rand() % j];
            }
        }
    }
}

void ShuffleBoard(char board[][COLS])
{
    char temp;
    int randRow, randCol;

    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            randRow = rand() % ROWS;
            randCol = rand() % COLS;

            temp = board[i][j];
            board[i][j] = board[randRow][randCol];
            board[randRow][randCol] = temp;
        }
    }
}

void DisplayBoard(char board[][COLS], char revealed[][COLS])
{
    printf("  ");
    for(int i=0; i<COLS; i++)
    {
        printf("%d ", i);
    }

    printf("\n");
    for(int i=0; i<ROWS; i++)
    {
        printf("%d ", i);

        for(int j=0; j<COLS; j++)
        {
            if(revealed[i][j])
            {
                printf("%c ", board[i][j]);
            }
            else
            {
                printf("* ");
            }
        }

        printf("\n");
    }
}

int IsGameOver(char revealed[][COLS])
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(!revealed[i][j])
            {
                return 0;
            }
        }
    }

    return 1;
}
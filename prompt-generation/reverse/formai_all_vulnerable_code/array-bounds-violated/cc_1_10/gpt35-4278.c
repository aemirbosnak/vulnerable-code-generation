//FormAI DATASET v1.0 Category: Memory Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initializeBoard(int board[ROWS][COLS]);
void displayBoard(int board[ROWS][COLS], int revealed[ROWS][COLS]);
void shuffleBoard(int board[ROWS][COLS]);
int checkForMatch(int board[ROWS][COLS], int revealed[ROWS][COLS], int row1, int col1, int row2, int col2);

int main()
{
    int board[ROWS][COLS];
    int revealed[ROWS][COLS] = {{0}};
    int numPairs = ROWS * COLS / 2;
    int numMatches = 0;
    int row1, col1, row2, col2;
    int turnCount = 0;

    srand(time(NULL));
    initializeBoard(board);
    shuffleBoard(board);

    while (numMatches < numPairs)
    {
        printf("--- Turn %d ---\n\n", turnCount + 1);
        displayBoard(board, revealed);

        printf("Enter the row and column of the first card: ");
        scanf("%d %d", &row1, &col1);

        while (revealed[row1][col1] == 1)
        {
            printf("That card has already been revealed. Please enter a different card: ");
            scanf("%d %d", &row1, &col1);
        }

        revealed[row1][col1] = 1;

        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &row2, &col2);

        while (revealed[row2][col2] == 1 || (row1 == row2 && col1 == col2))
        {
            printf("Invalid selection. Please enter a different card: ");
            scanf("%d %d", &row2, &col2);
        }

        revealed[row2][col2] = 1;

        if (checkForMatch(board, revealed, row1, col1, row2, col2))
        {
            printf("Congratulations, you have a match!\n\n");
            numMatches++;
        }
        else
        {
            printf("Sorry, those cards do not match.\n\n");
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
        }

        turnCount++;
    }

    printf("You won in %d turns!\n", turnCount);

    return 0;
}

void initializeBoard(int board[ROWS][COLS])
{
    int i, j, num = 1;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = num / 2;
            num++;
        }
    }
}

void displayBoard(int board[ROWS][COLS], int revealed[ROWS][COLS])
{
    int i, j;

    printf("\n-------------\n");

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (revealed[i][j] == 1)
            {
                printf("| %d ", board[i][j]);
            }
            else
            {
                printf("|   ");
            }
        }

        printf("|\n-------------\n");
    }

    printf("\n");
}

void shuffleBoard(int board[ROWS][COLS])
{
    int i, j;
    int temp, tempRow, tempCol;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            tempRow = rand() % ROWS;
            tempCol = rand() % COLS;
            temp = board[i][j];
            board[i][j] = board[tempRow][tempCol];
            board[tempRow][tempCol] = temp;
        }
    }
}

int checkForMatch(int board[ROWS][COLS], int revealed[ROWS][COLS], int row1, int col1, int row2, int col2)
{
    if (board[row1][col1] == board[row2][col2])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
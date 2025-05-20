//FormAI DATASET v1.0 Category: Memory Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

int chooseDifficulty();
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE], int numPairs);
int selectCard(char board[BOARD_SIZE][BOARD_SIZE], int *row, int *col);
void checkMatch(char board[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2, int *matches);

int main()
{
    int numPairs = chooseDifficulty();
    char board[BOARD_SIZE][BOARD_SIZE];
    int row1, col1, row2, col2;
    int matches = 0;
    
    initializeBoard(board, numPairs);
    printBoard(board);
    
    while (matches < numPairs)
    {
        if (selectCard(board, &row1, &col1) == 0)
            continue;
        if (selectCard(board, &row2, &col2) == 0)
            continue;
        checkMatch(board, row1, col1, row2, col2, &matches);
        printBoard(board);
    }
    
    printf("Congratulations! You matched all the cards.\n");
    
    return 0;
}

// Ask the user to choose the difficulty level
int chooseDifficulty()
{
    int difficulty;
    printf("Choose the difficulty level (1-3): ");
    scanf("%d", &difficulty);
    return difficulty * 2;
}

// Print the game board
void printBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == '-')
                printf("\t%c", board[i][j]);
            else
                printf("\t%d", board[i][j]);
        }
        printf("\n\n");
    }
}

// Initialize the game board
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE], int numPairs)
{
    int pairsRemaining = numPairs;
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = '-';
        }
    }
    
    srand(time(NULL));
    
    while (pairsRemaining > 0)
    {
        int number = rand() % numPairs + 1;
        int count = 0;
        i = rand() % BOARD_SIZE;
        j = rand() % BOARD_SIZE;
        while (count < 2)
        {
            if (board[i][j] == '-')
            {
                board[i][j] = number;
                count++;
            }
            j++;
            if (j == BOARD_SIZE)
            {
                j = 0;
                i++;
                if (i == BOARD_SIZE)
                {
                    i = 0;
                }
            }
        }
        pairsRemaining--;
    }
}

// Ask the user to select a card and return the row and column
int selectCard(char board[BOARD_SIZE][BOARD_SIZE], int *row, int *col)
{
    int selected = 0;
    while (!selected)
    {
        printf("Choose a card (row column): ");
        scanf("%d %d", row, col);
        if (*row >= 0 && *row < BOARD_SIZE && *col >= 0 && *col < BOARD_SIZE && board[*row][*col] != '-')
            selected = 1;
    }
    return 1;
}

// Check if the selected cards have a match and update the game board
void checkMatch(char board[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2, int *matches)
{
    if (board[row1][col1] == board[row2][col2])
    {
        printf("Match found!\n");
        board[row1][col1] = '-';
        board[row2][col2] = '-';
        (*matches)++;
    }
    else
    {
        printf("No match.\n");
    }
}
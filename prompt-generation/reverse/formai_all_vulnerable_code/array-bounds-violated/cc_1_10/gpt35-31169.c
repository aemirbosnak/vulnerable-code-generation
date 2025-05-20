//FormAI DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4

int gameGrid[GRID_SIZE][GRID_SIZE];
int revealedGrid[GRID_SIZE][GRID_SIZE];
int numPairsFound = 0;

void generateGrid()
{
    int values[GRID_SIZE * GRID_SIZE / 2];
    int idx = 0;

    // Populate values array with pairs of numbers
    for(int i = 1; i <= GRID_SIZE * GRID_SIZE / 2; i++)
    {
        values[idx++] = i;
        values[idx++] = i;
    }

    // Shuffle values array
    srand(time(NULL));
    for(int i = 0; i < GRID_SIZE * GRID_SIZE; i++)
    {
        int j = rand() % (GRID_SIZE * GRID_SIZE - i) + i;
        int tmp = values[i];
        values[i] = values[j];
        values[j] = tmp;
    }

    // Populate game grid with shuffled values
    idx = 0;
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            gameGrid[i][j] = values[idx++];
        }
    }
}

void printGrid()
{
    printf("\n");
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            if(revealedGrid[i][j] == 1)
            {
                printf("%2d ", gameGrid[i][j]);
            }
            else
            {
                printf("%2c ", '-');
            }
        }
        printf("\n");
    }
}

void revealTile(int row, int col)
{
    if(revealedGrid[row][col] == 1) return;

    revealedGrid[row][col] = 1;
    printGrid();
    if(gameGrid[row][col] == 1)
    {
        printf("You found a pair!\n");
        numPairsFound++;
    }
}

int main()
{
    generateGrid();

    printf("Welcome to the Memory Game!\n");
    printf("Try to find all %d pairs of matching tiles.\n", GRID_SIZE * GRID_SIZE / 2);

    while(numPairsFound < GRID_SIZE * GRID_SIZE / 2)
    {
        int row, col;
        printf("Enter row and column to reveal tile: ");
        scanf("%d %d", &row, &col);

        if(row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE)
        {
            revealTile(row, col);
        }
        else
        {
            printf("Invalid row or column!\n");
        }
    }

    printf("Congratulations! You found all the pairs!\n");
    return 0;
}
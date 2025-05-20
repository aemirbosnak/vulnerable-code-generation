//FormAI DATASET v1.0 Category: Memory Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 3
#define NUM_COLS 4

// Function declarations
void generateRandomNumbers(int numList[][NUM_COLS]);
void printMemoryGrid(char gameGrid[][NUM_COLS], int numList[][NUM_COLS]);
void updateGameGrid(char gameGrid[][NUM_COLS], int numList[][NUM_COLS], int row1, int col1, int row2, int col2);
void clearScreen();

int main()
{
    char gameGrid[NUM_ROWS][NUM_COLS] = {{' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    int numList[NUM_ROWS][NUM_COLS];
    int row1, col1, row2, col2;
    int numAttempts = 0;

    generateRandomNumbers(numList);

    while (1)
    {
        printMemoryGrid(gameGrid, numList);

        printf("Enter coordinates of first card: ");
        scanf("%d %d", &row1, &col1);
        if (row1 > 2 || col1 > 3 || gameGrid[row1][col1] != ' ') continue;

        printf("Enter coordinates of second card: ");
        scanf("%d %d", &row2, &col2);
        if (row2 > 2 || col2 > 3 || gameGrid[row2][col2] != ' ') continue;

        updateGameGrid(gameGrid, numList, row1, col1, row2, col2);
        numAttempts++;

        if (numAttempts % 10 == 0)
        {
            clearScreen();
            printf("Warning: High memory usage detected! Please close some programs to continue playing.\n");
        }
    }

    return 0;
}

void generateRandomNumbers(int numList[][NUM_COLS])
{
    int i, j, k;
    int temp[NUM_ROWS * NUM_COLS];

    // Initialize temporary array
    for (i = 0; i < NUM_ROWS * NUM_COLS; i++)
    {
        temp[i] = i / 2 + 1;
        if (temp[i] > 6) temp[i] = 1;
    }

    // Shuffle temporary array using Fisher-Yates shuffle algorithm
    srand(time(NULL));
    for (i = NUM_ROWS * NUM_COLS - 1; i >= 1; i--)
    {
        j = rand() % (i + 1);
        k = temp[i];
        temp[i] = temp[j];
        temp[j] = k;
    }

    // Copy shuffled numbers to numList array
    k = 0;
    for (i = 0; i < NUM_ROWS; i++)
    {
        for (j = 0; j < NUM_COLS; j++)
        {
            numList[i][j] = temp[k++];
        }
    }
}

void printMemoryGrid(char gameGrid[][NUM_COLS], int numList[][NUM_COLS])
{
    int i, j;
    clearScreen();
    printf("   0   1   2   3\n");
    printf("-----------------\n");
    for (i = 0; i < NUM_ROWS; i++)
    {
        printf("%d| ", i);
        for (j = 0; j < NUM_COLS; j++)
        {
            printf("%c%d ", gameGrid[i][j], numList[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------\n");
}

void updateGameGrid(char gameGrid[][NUM_COLS], int numList[][NUM_COLS], int row1, int col1, int row2, int col2)
{
    gameGrid[row1][col1] = '|';
    gameGrid[row2][col2] = '|';
    printMemoryGrid(gameGrid, numList);
    if (numList[row1][col1] == numList[row2][col2])
    {
        gameGrid[row1][col1] = numList[row1][col1] + '0';
        gameGrid[row2][col2] = numList[row2][col2] + '0';
        printf("Match found!\n");
    }
    else
    {
        gameGrid[row1][col1] = ' ';
        gameGrid[row2][col2] = ' ';
        printf("No match found.\n");
    }
}

void clearScreen()
{
    system("cls||clear");
}
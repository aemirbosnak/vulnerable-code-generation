//FormAI DATASET v1.0 Category: Memory Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initialize(int grid[ROWS][COLS]);
void printGrid(int grid[ROWS][COLS], int rowFirst, int colFirst, int rowSecond, int colSecond);
int checkWin(int grid[ROWS][COLS]);

int main()
{
    int grid[ROWS][COLS];
    int rowFirst, rowSecond, colFirst, colSecond;
    int count = 0;
    int win = 0;

    // initialize grid
    initialize(grid);

    // seed the random number generator
    srand(time(NULL));

    // game loop
    while (!win) {
        // print the grid
        printGrid(grid, rowFirst, colFirst, rowSecond, colSecond);

        // get first card coordinates
        printf("\nEnter the row of the first card (1-4): ");
        scanf("%d", &rowFirst);
        printf("Enter the column of the first card (1-4): ");
        scanf("%d", &colFirst);

        // print the grid with the first card revealed
        printGrid(grid, rowFirst, colFirst, rowSecond, colSecond);

        // get second card coordinates
        printf("\nEnter the row of the second card (1-4): ");
        scanf("%d", &rowSecond);
        printf("Enter the column of the second card (1-4): ");
        scanf("%d", &colSecond);

        // print the grid with both cards revealed
        printGrid(grid, rowFirst, colFirst, rowSecond, colSecond);

        // if cards match, remove them from the grid
        if (grid[rowFirst-1][colFirst-1] == grid[rowSecond-1][colSecond-1]) {
            grid[rowFirst-1][colFirst-1] = 0;
            grid[rowSecond-1][colSecond-1] = 0;
            count += 2;
        }

        // check if all cards have been removed
        if (count == ROWS * COLS) {
            win = 1;
        }
    }

    printf("\nCongratulations, you won!\n");

    return 0;
}

void initialize(int grid[ROWS][COLS])
{
    int i, j, k = 0;
    int cards[ROWS*COLS/2];

    // generate unique pairs of card values
    for (i = 1; i <= ROWS * COLS / 2; i++) {
        cards[k] = i;
        cards[k+1] = i;
        k += 2;
    }

    // shuffle card values
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int randomIndex = rand() % (ROWS * COLS);
            int temp = cards[randomIndex];
            cards[randomIndex] = cards[k-1];
            cards[k-1] = temp;
            grid[i][j] = cards[k-1];
            k--;
        }
    }
}

void printGrid(int grid[ROWS][COLS], int rowFirst, int colFirst, int rowSecond, int colSecond)
{
    int i, j;

    printf("\n   1  2  3  4\n");
    printf("  -------------\n");

    for (i = 0; i < ROWS; i++) {
        printf("%d| ", i+1);
        for (j = 0; j < COLS; j++) {
            if ((i == rowFirst-1 && j == colFirst-1) ||
                (i == rowSecond-1 && j == colSecond-1)) {
                printf("%d* ", grid[i][j]);
            } else if (grid[i][j] == 0) {
                printf("   ");
            } else {
                printf("%2d ", grid[i][j]);
            }
        }
        printf("|\n");
    }

    printf("  -------------\n");
}

int checkWin(int grid[ROWS][COLS])
{
    int i, j;
    
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] != 0) {
                return 0;
            }
        }
    }
    
    return 1;
}
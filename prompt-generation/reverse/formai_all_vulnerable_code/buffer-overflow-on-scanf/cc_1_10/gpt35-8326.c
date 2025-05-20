//FormAI DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayGrid(int grid[3][3]);
void inputGuess(int guess[3][3]);
void compareGrids(int grid[3][3], int guess[3][3]);

int main()
{
    printf("Welcome to the C Memory Game! Get ready to test your memory!\n\n");

    srand(time(NULL));
    int grid[3][3] = {{rand() % 9 + 1, rand() % 9 + 1, rand() % 9 + 1},
                      {rand() % 9 + 1, rand() % 9 + 1, rand() % 9 + 1},
                      {rand() % 9 + 1, rand() % 9 + 1, rand() % 9 + 1}};

    displayGrid(grid);

    int guess[3][3];
    inputGuess(guess);

    compareGrids(grid, guess);

    char play_again;
    printf("\n\nWould you like to play again? (y/n)\n");
    fflush(stdin);
    scanf("%c", &play_again);

    if (play_again == 'y') {
        main();
    }

    return 0;
}

void displayGrid(int grid[3][3])
{
    printf("Take a look at the grid below: \n\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    printf("\nYou have 10 seconds to memorize the grid!\n\n");
    sleep(10);
    system("clear");
}

void inputGuess(int guess[3][3])
{
    printf("Input the numbers in the grid by row and column. Good luck!\n\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Row %d, Column %d: ", i + 1, j + 1);
            scanf("%d", &guess[i][j]);
        }
    }

    system("clear");
}

void compareGrids(int grid[3][3], int guess[3][3])
{
    int correct = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == guess[i][j]) {
                correct++;
            }
        }
    }

    if (correct == 9) {
        printf("Congratulations! You won! You have a great memory!\n");
    } else {
        printf("Sorry, you lost. Try again next time!\n");
    }
}
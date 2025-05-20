//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 5
#define NUM_NUMBERS 75

typedef struct {
    int row;
    int column;
    int number;
} BingoNumber;

int main(int argc, char *argv[]) {
    // Generate a random bingo card
    BingoNumber* bingoCard = (BingoNumber*)malloc(NUM_ROWS * NUM_COLUMNS * sizeof(BingoNumber));
    for (int i = 0; i < NUM_ROWS * NUM_COLUMNS; i++) {
        int row = rand() % NUM_ROWS;
        int column = rand() % NUM_COLUMNS;
        int number = rand() % NUM_NUMBERS + 1;
        bingoCard[i].row = row;
        bingoCard[i].column = column;
        bingoCard[i].number = number;
    }

    // Print the bingo card
    printf("Bingo Card:\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            printf("%d ", bingoCard[i * NUM_COLUMNS + j].number);
        }
        printf("\n");
    }

    // Play a game of bingo
    int markedNumbers[NUM_ROWS][NUM_COLUMNS] = {0};
    int drawnNumbers[NUM_NUMBERS] = {0};
    int gameOver = 0;
    int currentRow = 0;
    int currentColumn = 0;
    int currentNumber = 1;
    int currentDrawNumber = 0;

    while (!gameOver) {
        // Draw a number
        srand(time(NULL));
        currentDrawNumber = rand() % NUM_NUMBERS + 1;
        while (markedNumbers[currentRow][currentColumn] == currentDrawNumber || currentDrawNumber == 0) {
            currentDrawNumber = rand() % NUM_NUMBERS + 1;
        }

        // Mark the number
        markedNumbers[currentRow][currentColumn] = currentDrawNumber;

        // Check if bingo
        if (markedNumbers[currentRow][currentColumn] == NUM_ROWS * NUM_COLUMNS) {
            gameOver = 1;
            printf("Bingo!\n");
            printf("Winning numbers: %d, %d, %d, %d, %d\n", currentRow, currentColumn, currentDrawNumber, bingoCard[currentRow * NUM_COLUMNS + currentColumn].row, bingoCard[currentRow * NUM_COLUMNS + currentColumn].column);
        }

        // Check if game over
        for (int i = 0; i < NUM_ROWS; i++) {
            for (int j = 0; j < NUM_COLUMNS; j++) {
                if (markedNumbers[i][j]!= 0) {
                    currentRow = i;
                    currentColumn = j;
                    currentNumber = markedNumbers[i][j];
                    break;
                }
            }
            if (currentRow!= 0 && currentColumn!= 0 && currentNumber!= 0) {
                break;
            }
        }
    }

    // Free memory
    free(bingoCard);

    return 0;
}
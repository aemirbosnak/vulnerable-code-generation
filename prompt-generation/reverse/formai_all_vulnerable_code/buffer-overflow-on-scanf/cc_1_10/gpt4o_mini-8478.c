//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GRID_SIZE 4

void initializeGrid(int grid[GRID_SIZE][GRID_SIZE], int values[GRID_SIZE * GRID_SIZE]) {
    srand(time(0));
    // Randomly shuffling values for memory game
    for (int i = GRID_SIZE * GRID_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // Filling the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = values[i * GRID_SIZE + j];
        }
    }
}

void printGrid(int grid[GRID_SIZE][GRID_SIZE], bool shown[GRID_SIZE][GRID_SIZE]) {
    printf("Current Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (shown[i][j]) {
                printf("%2d ", grid[i][j]);
            } else {
                printf("** ");
            }
        }
        printf("\n");
    }
}

bool checkMatch(int firstCard, int secondCard) {
    return firstCard == secondCard;
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE];
    bool shown[GRID_SIZE][GRID_SIZE] = {false};
    int values[GRID_SIZE * GRID_SIZE];
    int pairsFound = 0;
    int totalPairs = (GRID_SIZE * GRID_SIZE) / 2;

    // Fill the values array with pairs
    for (int i = 0; i < totalPairs; i++) {
        values[i * 2] = i + 1;
        values[i * 2 + 1] = i + 1;
    }

    initializeGrid(grid, values);

    while (pairsFound < totalPairs) {
        printGrid(grid, shown);

        int x1, y1, x2, y2;
        printf("Select the first card (row col): ");
        scanf("%d %d", &x1, &y1);
        printf("Select the second card (row col): ");
        scanf("%d %d", &x2, &y2);

        if (x1 < 0 || x1 >= GRID_SIZE || y1 < 0 || y1 >= GRID_SIZE ||
            x2 < 0 || x2 >= GRID_SIZE || y2 < 0 || y2 >= GRID_SIZE) {
            printf("Invalid input! Please select cards within the grid.\n");
            continue;
        }

        if (shown[x1][y1] || shown[x2][y2]) {
            printf("One or both cards have already been revealed. Try again!\n");
            continue;
        }

        shown[x1][y1] = true;
        shown[x2][y2] = true;

        printGrid(grid, shown);

        if (checkMatch(grid[x1][y1], grid[x2][y2])) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("Not a match! Try again.\n");
            shown[x1][y1] = false;
            shown[x2][y2] = false;
        }
    }

    printf("Congratulations! You've found all pairs!\n");
    return 0;
}
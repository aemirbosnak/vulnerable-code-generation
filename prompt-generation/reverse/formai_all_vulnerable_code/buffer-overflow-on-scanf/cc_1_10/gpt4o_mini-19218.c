//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GRID_SIZE 4
#define TOTAL_PAIRS (GRID_SIZE * GRID_SIZE) / 2

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE], char characters[TOTAL_PAIRS]) {
    int k = 0;
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        grid[k % GRID_SIZE][k / GRID_SIZE] = characters[i];
        k++;
        grid[k % GRID_SIZE][k / GRID_SIZE] = characters[i];
        k++;
    }

    // Shuffle the grid
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        int j = rand() % (GRID_SIZE * GRID_SIZE);
        char temp = grid[i / GRID_SIZE][i % GRID_SIZE];
        grid[i / GRID_SIZE][i % GRID_SIZE] = grid[j / GRID_SIZE][j % GRID_SIZE];
        grid[j / GRID_SIZE][j % GRID_SIZE] = temp;
    }
}

void printGrid(char grid[GRID_SIZE][GRID_SIZE], int revealed[GRID_SIZE][GRID_SIZE]) {
    printf("Current Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", grid[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));

    char characters[TOTAL_PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char grid[GRID_SIZE][GRID_SIZE];
    int revealed[GRID_SIZE][GRID_SIZE] = {{0}};
    int firstPickX, firstPickY, secondPickX, secondPickY;
    int pairsFound = 0;

    // Initialize the grid with shuffled characters
    initializeGrid(grid, characters);

    while (pairsFound < TOTAL_PAIRS) {
        printGrid(grid, revealed);
        printf("Pick your first card (row and column): ");
        scanf("%d %d", &firstPickX, &firstPickY);
        revealed[firstPickX][firstPickY] = 1;
        printGrid(grid, revealed);

        printf("Pick your second card (row and column): ");
        scanf("%d %d", &secondPickX, &secondPickY);
        revealed[secondPickX][secondPickY] = 1;
        printGrid(grid, revealed);

        if (grid[firstPickX][firstPickY] == grid[secondPickX][secondPickY]) {
            printf("You found a match!\n");
            pairsFound++;
        } else {
            printf("Not a match. Try again.\n");
            revealed[firstPickX][firstPickY] = 0;
            revealed[secondPickX][secondPickY] = 0;
        }
    }

    printf("Congratulations! You found all pairs!\n");
    return 0;
}
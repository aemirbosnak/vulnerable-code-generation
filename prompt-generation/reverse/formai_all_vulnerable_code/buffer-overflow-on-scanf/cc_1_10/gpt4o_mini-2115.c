//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GRID_SIZE 4
#define MAX_PAIRS (GRID_SIZE * GRID_SIZE) / 2

char symbols[MAX_PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
char grid[GRID_SIZE][GRID_SIZE];
int revealed[GRID_SIZE][GRID_SIZE] = {0};

void initializeGrid() {
    int count = 0;
    char tempGrid[GRID_SIZE][GRID_SIZE];
    
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (count < MAX_PAIRS) {
                tempGrid[i][j] = symbols[count];
                tempGrid[i][j + 1] = symbols[count];
                j++; // Move to the next column for the second instance
                count++;
            } else {
                break;
            }
        }
    }

    // Shuffle the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int randRow = rand() % GRID_SIZE;
            int randCol = rand() % GRID_SIZE;

            char temp = tempGrid[i][j];
            tempGrid[i][j] = tempGrid[randRow][randCol];
            tempGrid[randRow][randCol] = temp;
        }
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = tempGrid[i][j];
        }
    }
}

void printGrid() {
    printf("\nCurrent Grid State:\n");
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

int checkMatch(int x1, int y1, int x2, int y2) {
    return grid[x1][y1] == grid[x2][y2];
}

int isGameWon() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (!revealed[i][j]) {
                return 0; // Not all cards are revealed
            }
        }
    }
    return 1; // All cards are revealed
}

int main() {
    srand(time(NULL));
    initializeGrid();
    
    int attempts = 0;
    int firstCardX, firstCardY, secondCardX, secondCardY;

    while (1) {
        printGrid();
        printf("Select first card (row col): ");
        scanf("%d %d", &firstCardX, &firstCardY);
        revealed[firstCardX][firstCardY] = 1;

        printGrid();
        printf("Select second card (row col): ");
        scanf("%d %d", &secondCardX, &secondCardY);
        revealed[secondCardX][secondCardY] = 1;

        attempts += 1;

        if (checkMatch(firstCardX, firstCardY, secondCardX, secondCardY)) {
            printf("It's a match!\n");
        } else {
            printf("Not a match, try again...\n");
            revealed[firstCardX][firstCardY] = 0;
            revealed[secondCardX][secondCardY] = 0;
        }

        if (isGameWon()) {
            printf("Congratulations! You've matched all pairs in %d attempts!\n", attempts);
            break;
        }
    }

    return 0;
}
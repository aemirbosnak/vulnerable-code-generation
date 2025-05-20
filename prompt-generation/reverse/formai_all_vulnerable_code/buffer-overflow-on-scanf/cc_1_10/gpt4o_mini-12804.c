//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void initializeGrid(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = '.';
        }
    }
}

void printGrid(char grid[SIZE][SIZE]) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void placeTreasure(int *treasureX, int *treasureY) {
    srand(time(NULL));
    *treasureX = rand() % SIZE;
    *treasureY = rand() % SIZE;
}

int main() {
    char grid[SIZE][SIZE];
    int treasureX, treasureY;
    int guessX, guessY;
    int attempts = 0;
    int found = 0;

    initializeGrid(grid);
    placeTreasure(&treasureX, &treasureY);

    printf("Welcome to the Treasure Hunt Game!\n");
    printf("You need to find the treasure in a %dx%d grid.\n", SIZE, SIZE);
    printf("Enter your guesses for the treasure coordinates (row and column) starting from 0.\n");
    
    while (!found) {
        printGrid(grid);
        printf("Enter your guess (row and column): ");
        scanf("%d %d", &guessX, &guessY);
        
        if (guessX < 0 || guessX >= SIZE || guessY < 0 || guessY >= SIZE) {
            printf("Invalid input! Please enter numbers between 0 and %d for both coordinates.\n", SIZE - 1);
            continue;
        }

        attempts++;
        
        if (guessX == treasureX && guessY == treasureY) {
            found = 1;
            printf("Congratulations! You've found the treasure in %d attempts!\n", attempts);
        } else {
            printf("No treasure at (%d, %d). Try again!\n", guessX, guessY);
            grid[guessX][guessY] = 'X';  // Mark the guess with an X
        }
    }
    
    printf("Thanks for playing the Treasure Hunt Game!\n");
    return 0;
}
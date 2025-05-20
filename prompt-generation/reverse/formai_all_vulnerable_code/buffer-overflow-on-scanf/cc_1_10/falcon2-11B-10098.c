//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_GRID_SIZE 5
#define BINGO_NUMBERS 75

// Function to simulate a Bingo game
void bingoSimulator() {
    // Create a 5x5 Bingo grid
    int grid[BINGO_GRID_SIZE][BINGO_GRID_SIZE];
    
    // Randomly fill the grid with numbers between 1 and 75
    for (int i = 0; i < BINGO_GRID_SIZE; i++) {
        for (int j = 0; j < BINGO_GRID_SIZE; j++) {
            int randomNumber = rand() % BINGO_NUMBERS + 1;
            grid[i][j] = randomNumber;
        }
    }
    
    // Check if the user has a Bingo
    if (checkBingo(grid)) {
        printf("Congratulations! You have a Bingo!\n");
    } else {
        printf("Sorry, you didn't win this time.\n");
    }
}

// Function to check if the user has a Bingo
int checkBingo(int grid[BINGO_GRID_SIZE][BINGO_GRID_SIZE]) {
    int userNumbers[BINGO_GRID_SIZE][BINGO_GRID_SIZE];
    
    // Get the user's numbers
    printf("Enter your numbers:\n");
    for (int i = 0; i < BINGO_GRID_SIZE; i++) {
        for (int j = 0; j < BINGO_GRID_SIZE; j++) {
            int userNumber;
            printf("%d", i + 1);
            scanf("%d", &userNumber);
            userNumbers[i][j] = userNumber;
        }
    }
    
    // Check if the user's numbers are in the grid
    for (int i = 0; i < BINGO_GRID_SIZE; i++) {
        for (int j = 0; j < BINGO_GRID_SIZE; j++) {
            if (userNumbers[i][j] == grid[i][j]) {
                return 1;
            }
        }
    }
    
    // User didn't have a Bingo
    return 0;
}

int main() {
    // Run the Bingo Simulator
    bingoSimulator();
    
    return 0;
}
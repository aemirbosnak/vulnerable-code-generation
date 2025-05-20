//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variable to hold the current state of the game
int currentState = 0;

// Function to initialize the game
void initializeGame() {
    currentState = 0;
}

// Function to generate a random puzzle
void generatePuzzle() {
    srand(time(NULL));

    // Create a 3x3 array to hold the puzzle
    int puzzle[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    // Fill the puzzle with random numbers
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            puzzle[i][j] = rand() % 9 + 1;
        }
    }

    // Print the puzzle
    printf("Puzzle: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the puzzle is solved
int isPuzzleSolved(int puzzle[3][3]) {
    int solved = 1;

    // Check rows
    for (int i = 0; i < 3; i++) {
        int rowSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum += puzzle[i][j];
        }

        if (rowSum!= 45) {
            solved = 0;
            break;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        int colSum = 0;
        for (int i = 0; i < 3; i++) {
            colSum += puzzle[i][j];
        }

        if (colSum!= 45) {
            solved = 0;
            break;
        }
    }

    // Check diagonals
    if (puzzle[0][0] + puzzle[1][1] + puzzle[2][2]!= 45) {
        solved = 0;
    }

    if (puzzle[0][2] + puzzle[1][1] + puzzle[2][0]!= 45) {
        solved = 0;
    }

    return solved;
}

// Function to get the current state of the game
int getCurrentState() {
    return currentState;
}

// Function to set the current state of the game
void setCurrentState(int state) {
    currentState = state;
}

// Function to check if the puzzle is solved and reset if necessary
void checkPuzzleState() {
    int puzzle[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    if (isPuzzleSolved(puzzle)) {
        setCurrentState(0);
    } else {
        setCurrentState(1);
    }
}

// Main function
int main() {
    initializeGame();

    while (1) {
        printf("1. Generate a new puzzle\n");
        printf("2. Check puzzle state\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generatePuzzle();
                break;
            case 2:
                checkPuzzleState();
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
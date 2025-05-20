//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the size of the Haunted House
#define ROWS 8
#define COLS 8

char grid[ROWS][COLS];
bool playerAlive = true;

/* Initialize the Haunted House and place the player at a starting position */
void initHauntedHouse(int playerRow, int playerCol) {
    int j, k;
    
    // Set the initial state of each cell in the grid
    for(j = 0; j < ROWS; j++) {
        for(k = 0; k < COLS; k++) {
            grid[j][k] = '.';
        }
    }
    
    // Place the player in the starting position
    grid[playerRow][playerCol] = 'P';
    
    // Place three ghosts randomly on the grid
    srand(time(NULL));
    int i;
    for(i = 0; i < 3; i++) {
        int ghostRow = rand() % ROWS;
        int ghostCol = rand() % COLS;
        grid[ghostRow][ghostCol] = 'G';
    }
}

/* Print the current state of the Haunted House grid */
void printGrid() {
    int j, k;
    
    for(j = 0; j < ROWS; j++) {
        for(k = 0; k < COLS; k++) {
            printf("%c ", grid[j][k]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Move the player in the specified direction */
void movePlayer(char direction, int *playerRow, int *playerCol) {
    int newPlayerRow = *playerRow;
    int newPlayerCol = *playerCol;
    
    // Update the new location of the player based on the specified direction
    switch(direction) {
        case 'U': newPlayerRow--; break;
        case 'D': newPlayerRow++; break;
        case 'L': newPlayerCol--; break;
        case 'R': newPlayerCol++; break;
    }
    
    // Check if the new location is valid and move the player if it is
    if(newPlayerRow >= 0 && newPlayerRow < ROWS && newPlayerCol >= 0 && newPlayerCol < COLS) {
        if(grid[newPlayerRow][newPlayerCol] != 'G') {
            grid[*playerRow][*playerCol] = '.';
            grid[newPlayerRow][newPlayerCol] = 'P';
            *playerRow = newPlayerRow;
            *playerCol = newPlayerCol;
        } else {
            playerAlive = false; // The player has been caught by a ghost!
        }
    }
}

/* Main program function */
int main() {
    int playerRow = 3;
    int playerCol = 3;
    
    // Initialize the Haunted House and place the player in the starting position
    initHauntedHouse(playerRow, playerCol);
    
    // Print the initial state of the Haunted House grid
    printGrid();
    
    // Begin the main game loop
    char input;
    while(playerAlive) {
        printf("Enter direction (U/D/L/R): ");
        scanf(" %c", &input);
        movePlayer(input, &playerRow, &playerCol);
        printGrid();
    }
    
    // End of game message
    printf("Game Over! You were caught by a ghost.\n");
    
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GRID_SIZE 10

// Defining the robot's movements
typedef enum {
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    STAY
} Movement;

// Structure for the robot's position
typedef struct {
    int x;
    int y;
} Position;

// Function to initialize the grid
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE], Position *robotPos) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
    robotPos->x = GRID_SIZE / 2;
    robotPos->y = GRID_SIZE / 2;
    grid[robotPos->x][robotPos->y] = 'R';
}

// Function to display the grid
void displayGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    printf("\nCurrent Grid State:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to move the robot
void moveRobot(Position *robotPos, Movement direction, char grid[GRID_SIZE][GRID_SIZE]) {
    // Clear the robot's current position
    grid[robotPos->x][robotPos->y] = '.';

    switch (direction) {
        case MOVE_UP:
            if (robotPos->x > 0) {
                robotPos->x--;
            }
            break;
        case MOVE_DOWN:
            if (robotPos->x < GRID_SIZE - 1) {
                robotPos->x++;
            }
            break;
        case MOVE_LEFT:
            if (robotPos->y > 0) {
                robotPos->y--;
            }
            break;
        case MOVE_RIGHT:
            if (robotPos->y < GRID_SIZE - 1) {
                robotPos->y++;
            }
            break;
        case STAY:
            // Do nothing
            break;
    }

    // Mark the new position
    grid[robotPos->x][robotPos->y] = 'R';
}

// Function to get user input for movement
Movement getUserInput() {
    char userInput;
    printf("Enter your movement (w: up, s: down, a: left, d: right, x: stay): ");
    scanf(" %c", &userInput);

    switch (userInput) {
        case 'w':
            return MOVE_UP;
        case 's':
            return MOVE_DOWN;
        case 'a':
            return MOVE_LEFT;
        case 'd':
            return MOVE_RIGHT;
        case 'x':
            return STAY;
        default:
            printf("Invalid input. Please enter again.\n");
            return STAY; // Default to stay on invalid input
    }
}

// Main control loop for the robot's movement
int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    Position robotPos;

    // Initializing the grid and the robot's position
    initializeGrid(grid, &robotPos);

    while (1) {
        displayGrid(grid);
        Movement direction = getUserInput();
        moveRobot(&robotPos, direction, grid);
        
        // Short delay to simulate movement
        usleep(500000); // 0.5 second delay
        
        // Clear screen for better visualization
        system("clear");
    }

    return 0;
}
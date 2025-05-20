//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GRID_SIZE 5
#define EMPTY ' '
#define ROBOT 'R'
#define GOAL 'G'

typedef struct {
    int x;
    int y;
} Position;

char grid[GRID_SIZE][GRID_SIZE];
Position robotPos;

void initializeGrid() {
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }
    grid[GRID_SIZE - 1][GRID_SIZE - 1] = GOAL; // Goal position
    robotPos.x = 0;
    robotPos.y = 0;
    grid[robotPos.x][robotPos.y] = ROBOT; // Initial robot position
}

void displayGrid() {
    printf("\nCurrent Grid State:\n");
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isValidMove(int newX, int newY) {
    return (newX >= 0 && newY >= 0 && newX < GRID_SIZE && newY < GRID_SIZE);
}

void moveRobot(int direction) {
    grid[robotPos.x][robotPos.y] = EMPTY; // Clear current position
    switch (direction) {
        case 0: // Up
            if (isValidMove(robotPos.x - 1, robotPos.y)) {
                robotPos.x--;
            }
            break;
        case 1: // Down
            if (isValidMove(robotPos.x + 1, robotPos.y)) {
                robotPos.x++;
            }
            break;
        case 2: // Left
            if (isValidMove(robotPos.x, robotPos.y - 1)) {
                robotPos.y--;
            }
            break;
        case 3: // Right
            if (isValidMove(robotPos.x, robotPos.y + 1)) {
                robotPos.y++;
            }
            break;
        default:
            printf("Invalid direction!\n");
    }
    grid[robotPos.x][robotPos.y] = ROBOT; // Update position
    displayGrid(); // Display the new grid state after moving
}

int main() {
    printf("Welcome to the Grateful Robot Movement Game!\n");
    initializeGrid();
    displayGrid();
    
    char input;
    while (1) {
        printf("Enter direction (W - Up, S - Down, A - Left, D - Right, E - Exit): ");
        scanf(" %c", &input);
        
        switch (input) {
            case 'W':
            case 'w':
                moveRobot(0);
                break;
            case 'S':
            case 's':
                moveRobot(1);
                break;
            case 'A':
            case 'a':
                moveRobot(2);
                break;
            case 'D':
            case 'd':
                moveRobot(3);
                break;
            case 'E':
            case 'e':
                printf("Thank you for playing! Goodbye!\n");
                exit(0);
            default:
                printf("Please enter a valid direction!\n");
        }

        if (robotPos.x == GRID_SIZE - 1 && robotPos.y == GRID_SIZE - 1) {
            printf("Congratulations! The robot has reached the goal!\n");
            break;
        }
    }
    return 0;
}
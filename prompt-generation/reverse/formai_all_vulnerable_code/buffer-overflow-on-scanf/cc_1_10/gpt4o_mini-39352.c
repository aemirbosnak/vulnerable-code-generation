//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
} Position;

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void displayGrid(char grid[GRID_SIZE][GRID_SIZE], Position robotPos);
void moveRobot(Position *robotPos, char direction);
int isValidPosition(Position robotPos);

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    Position robotPos = {GRID_SIZE / 2, GRID_SIZE / 2}; // Start in the center
    char command;

    // Initialize the grid
    initializeGrid(grid);

    printf("Robot Movement Control System\n");
    printf("Commands:\n");
    printf("w - Move Up\n");
    printf("s - Move Down\n");
    printf("a - Move Left\n");
    printf("d - Move Right\n");
    printf("q - Quit\n");

    while (1) {
        displayGrid(grid, robotPos);
        printf("Enter command: ");
        scanf(" %c", &command);

        // Process the command
        if (command == 'q') {
            printf("Exiting program...\n");
            break;
        }
        moveRobot(&robotPos, command);
    }

    return 0;
}

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
}

void displayGrid(char grid[GRID_SIZE][GRID_SIZE], Position robotPos) {
    // Clear the previous position (optional)
    initializeGrid(grid);
    
    // Draw the robot's position
    grid[robotPos.y][robotPos.x] = 'R';

    // Print the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void moveRobot(Position *robotPos, char direction) {
    Position newPos = *robotPos;

    switch (direction) {
        case 'w': // Move up
            newPos.y--;
            break;
        case 's': // Move down
            newPos.y++;
            break;
        case 'a': // Move left
            newPos.x--;
            break;
        case 'd': // Move right
            newPos.x++;
            break;
        default:
            printf("Invalid command! Use 'w', 'a', 's', 'd' to move.\n");
            return;
    }

    // Validate new position
    if (isValidPosition(newPos)) {
        *robotPos = newPos;
    } else {
        printf("Move out of bounds! Try again.\n");
    }
}

int isValidPosition(Position robotPos) {
    return robotPos.x >= 0 && robotPos.x < GRID_SIZE &&
           robotPos.y >= 0 && robotPos.y < GRID_SIZE;
}
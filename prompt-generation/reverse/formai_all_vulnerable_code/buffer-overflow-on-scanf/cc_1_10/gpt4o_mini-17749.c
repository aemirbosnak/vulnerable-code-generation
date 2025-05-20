//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
} Position;

typedef enum {
    UP, DOWN, LEFT, RIGHT, STAY
} Command;

char grid[GRID_SIZE][GRID_SIZE];

void initializeGrid() {
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            grid[i][j] = '.';
}

void printGrid(Position pos) {
    system("clear"); // Clear the terminal screen
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == pos.y && j == pos.x)
                printf("R "); // R represents the remote controlled vehicle
            else
                printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

Command getCommand() {
    int input;
    printf("Enter command (0-Up, 1-Down, 2-Left, 3-Right, 4-Stay): ");
    scanf("%d", &input);
    return (Command)input;
}

Position moveVehicle(Position pos, Command command) {
    switch (command) {
        case UP:
            if (pos.y > 0) pos.y--;
            break;
        case DOWN:
            if (pos.y < GRID_SIZE - 1) pos.y++;
            break;
        case LEFT:
            if (pos.x > 0) pos.x--;
            break;
        case RIGHT:
            if (pos.x < GRID_SIZE - 1) pos.x++;
            break;
        default:
            break;
    }
    return pos;
}

void randomObstacle() {
    int x = rand() % GRID_SIZE;
    int y = rand() % GRID_SIZE;
    grid[y][x] = 'X'; // X represents an obstacle
}

int checkCollision(Position pos) {
    return grid[pos.y][pos.x] == 'X';
}

int main() {
    Position vehiclePos = {0, 0}; // Starting position of the vehicle
    Command command;
    
    srand(time(NULL));
    initializeGrid();
    randomObstacle(); // Place an obstacle

    while (1) {
        printGrid(vehiclePos);
        command = getCommand();

        // Move the vehicle according to the command
        Position newPosition = moveVehicle(vehiclePos, command);

        // Check for collision
        if (checkCollision(newPosition)) {
            printf("Collision detected! Game Over.\n");
            break;
        }

        vehiclePos = newPosition; // Update vehicle position
        usleep(500000); // Sleep for half a second for a smoother simulation
    }

    printf("Final position: (%d, %d)\n", vehiclePos.x, vehiclePos.y);
    return 0;
}
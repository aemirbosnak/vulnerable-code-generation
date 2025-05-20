//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // For sleep function

#define GRID_SIZE 10
#define OBSTACLES 5

typedef struct {
    int x;
    int y;
} Vehicle;

void initGrid(Vehicle *vehicle, char grid[GRID_SIZE][GRID_SIZE]);
void displayGrid(Vehicle *vehicle, char grid[GRID_SIZE][GRID_SIZE]);
void placeObstacles(char grid[GRID_SIZE][GRID_SIZE]);
void moveVehicle(Vehicle *vehicle, char grid[GRID_SIZE][GRID_SIZE], char direction);
int isObstacle(char grid[GRID_SIZE][GRID_SIZE], int x, int y);
void clearScreen();

int main() {
    Vehicle rcCar = {0, 0};
    char grid[GRID_SIZE][GRID_SIZE];
    
    initGrid(&rcCar, grid);
    placeObstacles(grid);
    
    char command;
    while (1) {
        clearScreen();
        displayGrid(&rcCar, grid);
        printf("\nControl your RC Vehicle! (w: Up, s: Down, a: Left, d: Right, q: Quit): ");
        scanf(" %c", &command);

        if (command == 'q') {
            printf("Thanks for driving! Goodbye!\n");
            break;
        }
        
        moveVehicle(&rcCar, grid, command);
        usleep(500000);  // Sleep for half a second
    }
    return 0;
}

void clearScreen() {
    // Clear console
    printf("\033[H\033[J");
}

void initGrid(Vehicle *vehicle, char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
    grid[vehicle->x][vehicle->y] = 'R';  // R for RC vehicle
}

void placeObstacles(char grid[GRID_SIZE][GRID_SIZE]) {
    srand(time(NULL));  // Seed for random number generation
    for (int i = 0; i < OBSTACLES; i++) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == '.') {  // Place obstacle only in empty spots
            grid[x][y] = 'X';
        } else {
            i--;  // Retry if the spot is already taken
        }
    }
}

void displayGrid(Vehicle *vehicle, char grid[GRID_SIZE][GRID_SIZE]) {
    printf("RC Vehicle Position: (%d, %d)\n", vehicle->x, vehicle->y);
    printf("Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            putchar(grid[i][j]);
        }
        putchar('\n');
    }
}

void moveVehicle(Vehicle *vehicle, char grid[GRID_SIZE][GRID_SIZE], char direction) {
    grid[vehicle->x][vehicle->y] = '.';  // Clear current position
    int new_x = vehicle->x;
    int new_y = vehicle->y;

    switch (direction) {
        case 'w': new_x -= 1; break;  // Move up
        case 's': new_x += 1; break;  // Move down
        case 'a': new_y -= 1; break;  // Move left
        case 'd': new_y += 1; break;  // Move right
        default: printf("Invalid command!\n"); return;  // Just return to avoid moving
    }
    
    // Boundary check
    if (new_x < 0 || new_x >= GRID_SIZE || new_y < 0 || new_y >= GRID_SIZE) {
        printf("Hit a boundary! Can't move that way.\n");
        return;
    }
    
    // Obstacle check
    if (isObstacle(grid, new_x, new_y)) {
        printf("Crash! There's an obstacle there!\n");
    } else {
        vehicle->x = new_x;
        vehicle->y = new_y;
    }
    
    grid[vehicle->x][vehicle->y] = 'R';  // Update vehicle position
}

int isObstacle(char grid[GRID_SIZE][GRID_SIZE], int x, int y) {
    return grid[x][y] == 'X';
}
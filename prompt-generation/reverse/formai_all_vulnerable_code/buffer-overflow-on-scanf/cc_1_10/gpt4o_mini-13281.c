//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 5

// Define the vehicle structure
typedef struct {
    int x; // x position
    int y; // y position
} Vehicle;

// Function to initialize vehicle position
void initializeVehicle(Vehicle *v) {
    v->x = GRID_SIZE / 2; // Start in the middle of the grid
    v->y = GRID_SIZE / 2; // Start in the middle of the grid
}

// Function to display the grid and vehicle position
void displayGrid(const Vehicle *v) {
    system("clear"); // Clear the terminal screen
    printf("Vehicle Position: (%d, %d)\n", v->x, v->y);
    printf("Grid:\n");
    
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == v->y && j == v->x) {
                printf(" V "); // Vehicle representation
            } else {
                printf(" . "); // Empty space
            }
        }
        printf("\n");
    }
}

// Function to move the vehicle based on user input
void moveVehicle(Vehicle *v, const char *command) {
    if (strcmp(command, "w") == 0 && v->y > 0) { // Move up
        v->y--;
    } else if (strcmp(command, "s") == 0 && v->y < GRID_SIZE - 1) { // Move down
        v->y++;
    } else if (strcmp(command, "a") == 0 && v->x > 0) { // Move left
        v->x--;
    } else if (strcmp(command, "d") == 0 && v->x < GRID_SIZE - 1) { // Move right
        v->x++;
    } else {
        printf("Invalid move!\n");
    }
}

// Function to run the vehicle simulation
void runSimulation() {
    Vehicle vehicle;
    initializeVehicle(&vehicle);
    
    char command[10];
    while (1) {
        displayGrid(&vehicle);
        printf("Enter command (w=up, s=down, a=left, d=right, q=quit): ");
        scanf("%s", command);
        
        if (strcmp(command, "q") == 0) { 
            printf("Exiting simulation...\n");
            break;
        }
        
        moveVehicle(&vehicle, command);
    }
}

int main() {
    runSimulation();
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
} Vehicle;

void initVehicle(Vehicle *v) {
    v->x = GRID_SIZE / 2;  // Start in the middle of the grid
    v->y = GRID_SIZE / 2;
}

void printGrid(Vehicle *v) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == v->y && j == v->x) {
                printf("V ");  // Vehicle representation
            } else {
                printf(". ");  // Free space representation
            }
        }
        printf("\n");
    }
}

void moveVehicle(Vehicle *v, char direction) {
    switch (direction) {
        case 'w': // Move up
            if (v->y > 0) v->y--;
            break;
        case 's': // Move down
            if (v->y < GRID_SIZE - 1) v->y++;
            break;
        case 'a': // Move left
            if (v->x > 0) v->x--;
            break;
        case 'd': // Move right
            if (v->x < GRID_SIZE - 1) v->x++;
            break;
        default:
            printf("Invalid direction! Use 'w', 'a', 's', 'd' to move.\n");
    }
}

void displayInstructions() {
    printf("Remote Control Vehicle Simulation\n");
    printf("Control the vehicle using the following keys:\n");
    printf("'w' - Move Up\n");
    printf("'s' - Move Down\n");
    printf("'a' - Move Left\n");
    printf("'d' - Move Right\n");
    printf("'q' - Quit the simulation\n");
}

int main() {
    Vehicle vehicle;
    char command;

    initVehicle(&vehicle);
    displayInstructions();

    while (1) {
        printGrid(&vehicle);

        printf("Enter command: ");
        scanf(" %c", &command);

        if (command == 'q') {
            printf("Exiting simulation...\n");
            break;
        }

        moveVehicle(&vehicle, command);
    }

    return 0;
}
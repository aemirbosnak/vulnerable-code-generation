//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    char direction; // N, E, S, W
} Vehicle;

void initVehicle(Vehicle *v) {
    v->pos.x = GRID_SIZE / 2; // Start in the middle of the grid
    v->pos.y = GRID_SIZE / 2; // Start in the middle of the grid
    v->direction = 'N'; // Start facing North
}

void printGrid(Vehicle *v) {
    system("clear"); // Clear the terminal for a better view (use "cls" on Windows)
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == v->pos.y && j == v->pos.x) {
                printf("V "); // Display the vehicle
            } else {
                printf(". "); // Empty space
            }
        }
        printf("\n");
    }
    printf("Vehicle Direction: %c\n", v->direction);
}

void moveForward(Vehicle *v) {
    switch (v->direction) {
        case 'N':
            if (v->pos.y > 0) v->pos.y--;
            break;
        case 'E':
            if (v->pos.x < GRID_SIZE - 1) v->pos.x++;
            break;
        case 'S':
            if (v->pos.y < GRID_SIZE - 1) v->pos.y++;
            break;
        case 'W':
            if (v->pos.x > 0) v->pos.x--;
            break;
    }
}

void turnLeft(Vehicle *v) {
    switch (v->direction) {
        case 'N': v->direction = 'W'; break;
        case 'W': v->direction = 'S'; break;
        case 'S': v->direction = 'E'; break;
        case 'E': v->direction = 'N'; break;
    }
}

void turnRight(Vehicle *v) {
    switch (v->direction) {
        case 'N': v->direction = 'E'; break;
        case 'E': v->direction = 'S'; break;
        case 'S': v->direction = 'W'; break;
        case 'W': v->direction = 'N'; break;
    }
}

int main() {
    Vehicle vehicle;
    initVehicle(&vehicle);
    
    char command;

    while (1) {
        printGrid(&vehicle);
        printf("Enter command (W: Move Forward, A: Turn Left, D: Turn Right, Q: Quit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'W':
            case 'w':
                moveForward(&vehicle);
                break;
            case 'A':
            case 'a':
                turnLeft(&vehicle);
                break;
            case 'D':
            case 'd':
                turnRight(&vehicle);
                break;
            case 'Q':
            case 'q':
                printf("Exiting the simulation. Goodbye!\n");
                return 0;
            default:
                printf("Invalid command. Please try again.\n");
                break;
        }
    }

    return 0;
}
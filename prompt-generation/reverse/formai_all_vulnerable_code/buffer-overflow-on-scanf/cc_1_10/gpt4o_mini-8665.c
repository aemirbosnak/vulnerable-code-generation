//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
    char direction; // N, S, E, W
} Vehicle;

void initializeVehicle(Vehicle *v) {
    v->x = GRID_SIZE / 2;  // Start in the middle of the grid
    v->y = GRID_SIZE / 2;
    v->direction = 'N'; // Facing North by default
}

void printGrid(Vehicle v) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == v.y && j == v.x) {
                printf("V "); // Vehicle representation
            } else {
                printf(". "); // Empty space
            }
        }
        printf("\n");
    }
    printf("\n");
}

void moveVehicle(Vehicle *v, char command) {
    switch (v->direction) {
        case 'N':
            if (command == 'F' && v->y > 0) v->y--;
            else if (command == 'B' && v->y < GRID_SIZE - 1) v->y++;
            break;
        case 'S':
            if (command == 'F' && v->y < GRID_SIZE - 1) v->y++;
            else if (command == 'B' && v->y > 0) v->y--;
            break;
        case 'E':
            if (command == 'F' && v->x < GRID_SIZE - 1) v->x++;
            else if (command == 'B' && v->x > 0) v->x--;
            break;
        case 'W':
            if (command == 'F' && v->x > 0) v->x--;
            else if (command == 'B' && v->x < GRID_SIZE - 1) v->x++;
            break;
    }
}

void turnVehicle(Vehicle *v, char turn) {
    if (turn == 'L') {
        switch (v->direction) {
            case 'N': v->direction = 'W'; break;
            case 'W': v->direction = 'S'; break;
            case 'S': v->direction = 'E'; break;
            case 'E': v->direction = 'N'; break;
        }
    } else if (turn == 'R') {
        switch (v->direction) {
            case 'N': v->direction = 'E'; break;
            case 'E': v->direction = 'S'; break;
            case 'S': v->direction = 'W'; break;
            case 'W': v->direction = 'N'; break;
        }
    }
}

void displayInstructions() {
    printf("Control the Vehicle with commands:\n");
    printf("F - Move Forward\n");
    printf("B - Move Backward\n");
    printf("L - Turn Left\n");
    printf("R - Turn Right\n");
    printf("Q - Quit\n\n");
}

int main() {
    Vehicle v;
    char command;

    initializeVehicle(&v);
    displayInstructions();

    while (1) {
        printGrid(v);
        printf("Enter command: ");
        scanf(" %c", &command);

        if (command == 'Q') {
            printf("Exiting the simulation...\n");
            break;
        } else if (command == 'F' || command == 'B') {
            moveVehicle(&v, command);
        } else if (command == 'L' || command == 'R') {
            turnVehicle(&v, command);
        } else {
            printf("Invalid command, please try again.\n");
        }
    }

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 5

typedef struct {
    int x;
    int y;
} Vehicle;

void printGrid(Vehicle *v) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == v->x && j == v->y) {
                printf("V ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int canMove(Vehicle *v, int newX, int newY) {
    return (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE);
}

void moveVehicle(Vehicle *v, char direction, int steps) {
    if (steps <= 0) {
        return;
    }

    int newX = v->x;
    int newY = v->y;

    switch (direction) {
        case 'u': // Move up
            newX--;
            break;
        case 'd': // Move down
            newX++;
            break;
        case 'l': // Move left
            newY--;
            break;
        case 'r': // Move right
            newY++;
            break;
        default:
            printf("Invalid direction!\n");
            return;
    }

    if (canMove(v, newX, newY)) {
        v->x = newX;
        v->y = newY;
        printGrid(v);
        moveVehicle(v, direction, steps - 1);
    } else {
        printf("Move out of bounds! Current position: (%d, %d)\n", v->x, v->y);
    }
}

int main() {
    Vehicle v = {2, 2}; // Start in the middle of the grid
    printGrid(&v);

    char direction;
    int steps;

    while (1) {
        printf("Enter direction (u/d/l/r) and steps (0 to exit): ");
        scanf(" %c%d", &direction, &steps);

        if (steps == 0) {
            break; // Exit the loop
        }

        moveVehicle(&v, direction, steps);
    }

    printf("Simulation finished. Final position: (%d, %d)\n", v.x, v.y);
    return 0;
}
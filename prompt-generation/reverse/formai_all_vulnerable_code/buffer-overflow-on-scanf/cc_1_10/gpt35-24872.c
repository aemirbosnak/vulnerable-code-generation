//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random number between 0 and 3, inclusive
int generateRandomDirection() {
    srand(time(NULL));
    return rand() % 4;
}

// Struct to represent a drone
typedef struct {
    int x;
    int y;
    int direction; // 0 = north, 1 = east, 2 = south, 3 = west
} Drone;

// Function to create and initialize a new drone
Drone* createDrone(int x, int y) {
    Drone* drone = (Drone*) malloc(sizeof(Drone));
    drone->x = x;
    drone->y = y;
    drone->direction = generateRandomDirection();
    return drone;
}

// Function to move a drone in its current direction
void moveDrone(Drone* drone) {
    switch(drone->direction) {
        case 0:
            drone->y++;
            break;
        case 1:
            drone->x++;
            break;
        case 2:
            drone->y--;
            break;
        case 3:
            drone->x--;
            break;
    }
}

int main() {
    // Create an array of 4 drones
    Drone* drones[4];
    drones[0] = createDrone(0, 0);
    drones[1] = createDrone(10, 0);
    drones[2] = createDrone(0, 10);
    drones[3] = createDrone(10, 10);

    // Prompt user for number of moves to make
    int numMoves;
    printf("How many moves do you want to make? ");
    scanf("%d", &numMoves);

    // Perform the specified number of moves
    int i;
    for(i = 0; i < numMoves; i++) {
        printf("Move %d:\n", i+1);
        // Move each drone and print its new position
        int j;
        for(j = 0; j < 4; j++) {
            moveDrone(drones[j]);
            printf("Drone %d: (%d, %d)\n", j+1, drones[j]->x, drones[j]->y);
        }
    }

    // Free memory allocated for the drones
    for(i = 0; i < 4; i++) {
        free(drones[i]);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the width and height of the simulation grid
#define WIDTH 10
#define HEIGHT 10

// Define constants for the actions that the remote control can perform
#define FORWARD 0
#define BACKWARD 1
#define LEFT 2
#define RIGHT 3

// Define the struct for the remote control vehicle
typedef struct {
    int x;
    int y;
    int heading; // 0 = north, 1 = east, 2 = south, 3 = west
} Vehicle;

// Function to initialize the vehicle at a random starting position and heading
void initVehicle(Vehicle *v) {
    srand(time(NULL)); // seed the random number generator with the current time
    v->x = rand() % WIDTH;
    v->y = rand() % HEIGHT;
    v->heading = rand() % 4;
}

// Function to print the current position and heading of the vehicle
void printPosition(Vehicle v) {
    printf("Position: (%d, %d)\n", v.x, v.y);
    switch (v.heading) {
        case 0:
            printf("Heading: north\n");
            break;
        case 1:
            printf("Heading: east\n");
            break;
        case 2:
            printf("Heading: south\n");
            break;
        case 3:
            printf("Heading: west\n");
            break;
    }
}

// Function to move the vehicle forward one grid square in its current heading
void moveForward(Vehicle *v) {
    switch (v->heading) {
        case 0:
            if (v->y > 0) {
                v->y--;
            }
            break;
        case 1:
            if (v->x < WIDTH-1) {
                v->x++;
            }
            break;
        case 2:
            if (v->y < HEIGHT-1) {
                v->y++;
            }
            break;
        case 3:
            if (v->x > 0) {
                v->x--;
            }
            break;
    }
}

// Function to move the vehicle backward one grid square opposite to its current heading
void moveBackward(Vehicle *v) {
    switch (v->heading) {
        case 0:
            if (v->y < HEIGHT-1) {
                v->y++;
            }
            break;
        case 1:
            if (v->x > 0) {
                v->x--;
            }
            break;
        case 2:
            if (v->y > 0) {
                v->y--;
            }
            break;
        case 3:
            if (v->x < WIDTH-1) {
                v->x++;
            }
            break;
    }
}

// Function to turn the vehicle 90 degrees to the left
void turnLeft(Vehicle *v) {
    v->heading = (v->heading + 3) % 4;
}

// Function to turn the vehicle 90 degrees to the right
void turnRight(Vehicle *v) {
    v->heading = (v->heading + 1) % 4;
}

int main() {
    Vehicle rcVehicle;
    initVehicle(&rcVehicle);

    printf("Remote Control Vehicle Simulation\n\n");

    while (1) {
        printPosition(rcVehicle);

        int action;
        printf("Enter action code (0 = forward, 1 = backward, 2 = left, 3 = right): ");
        scanf("%d", &action);

        switch (action) {
            case FORWARD:
                moveForward(&rcVehicle);
                break;
            case BACKWARD:
                moveBackward(&rcVehicle);
                break;
            case LEFT:
                turnLeft(&rcVehicle);
                break;
            case RIGHT:
                turnRight(&rcVehicle);
                break;
            default:
                printf("Invalid action code.\n");
                break;
        }

        printf("\n");
    }
}
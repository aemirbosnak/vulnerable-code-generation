//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SPEED 100
#define TURN_ANGLE 10

// Function prototypes
void turnLeft(int* direction);
void turnRight(int* direction);
int accelerate(int speed);
int decelerate(int speed);

int main() {
    srand(time(0)); // Set seed for random number generation

    int speed = 0;
    int direction = 0; // 0 = north, 1 = east, 2 = south, 3 = west

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Use the following commands to control the vehicle:\n");
    printf("A: accelerate\nD: decelerate\nL: turn left\nR: turn right\nQ: quit\n");

    char input = ' ';
    while(input != 'Q') {
        printf("\nCurrent speed: %d\nCurrent direction: ", speed);
        switch(direction) {
            case 0:
                printf("North");
                break;
            case 1:
                printf("East");
                break;
            case 2:
                printf("South");
                break;
            case 3:
                printf("West");
                break;
            default:
                printf("Invalid direction");
        }

        printf("\nEnter a command: ");
        scanf(" %c", &input);

        switch(input) {
            case 'A':
                speed = accelerate(speed);
                break;
            case 'D':
                speed = decelerate(speed);
                break;
            case 'L':
                turnLeft(&direction);
                break;
            case 'R':
                turnRight(&direction);
                break;
            case 'Q':
                printf("Quitting program...");
                break;
            default:
                printf("Invalid command");
        }
    }

    return 0;
}

/*
 * Function to turn the vehicle left and update its direction
 */
void turnLeft(int* direction) {
    *direction -= 1;
    if(*direction < 0) {
        *direction = 3;
    }

    printf("Vehicle turned left\n");
}

/*
 * Function to turn the vehicle right and update its direction
 */
void turnRight(int* direction) {
    *direction += 1;
    if(*direction > 3) {
        *direction = 0;
    }

    printf("Vehicle turned right\n");
}

/*
 * Function to accelerate the vehicle and return its new speed
 */
int accelerate(int speed) {
    int increase = rand() % 11; // Generate a random speed increase between 0 and 10

    speed += increase;
    if(speed > MAX_SPEED) {
        speed = MAX_SPEED;
    }

    printf("Vehicle accelerated by %d units\n", increase);
    return speed;
}

/*
 * Function to decelerate the vehicle and return its new speed
 */
int decelerate(int speed) {
    int decrease = rand() % 11; // Generate a random speed decrease between 0 and 10

    speed -= decrease;
    if(speed < 0) {
        speed = 0;
    }

    printf("Vehicle decelerated by %d units\n", decrease);
    return speed;
}
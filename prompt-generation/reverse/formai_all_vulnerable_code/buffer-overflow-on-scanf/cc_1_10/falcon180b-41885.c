//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining the speed of the vehicle
#define SPEED 5

// Defining the directions
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

// Function to move the vehicle
void moveVehicle(int direction) {
    printf("Vehicle is moving %c\n", direction);
}

// Function to turn the vehicle
void turnVehicle(int direction) {
    printf("Vehicle is turning %c\n", direction);
}

// Function to simulate the movement of the vehicle
void simulateMovement(int speed, int duration) {
    int i;
    for (i = 0; i < duration; i++) {
        printf("Vehicle is moving forward\n");
        sleep(1);
    }
}

// Main function
int main() {
    int choice;
    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Please choose an option:\n");
    printf("1. Move forward\n");
    printf("2. Turn left\n");
    printf("3. Turn right\n");
    printf("4. Move backward\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Vehicle is moving forward for 5 seconds...\n");
            simulateMovement(SPEED, 5);
            break;
        case 2:
            turnVehicle(LEFT);
            break;
        case 3:
            turnVehicle(RIGHT);
            break;
        case 4:
            printf("Vehicle is moving backward for 5 seconds...\n");
            simulateMovement(SPEED, 5);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

/*
Sample Output:

Welcome to the Remote Control Vehicle Simulation!
Please choose an option:
1. Move forward
2. Turn left
3. Turn right
4. Move backward
1
Vehicle is moving forward for 5 seconds...
Vehicle is moving forward
Vehicle is moving forward
Vehicle is moving forward
Vehicle is moving forward
*/
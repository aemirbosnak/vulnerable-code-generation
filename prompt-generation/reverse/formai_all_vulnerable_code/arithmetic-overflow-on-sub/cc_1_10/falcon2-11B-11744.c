//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototypes
void simulate_vehicle(int x, int y, int angle, int speed);

// Main function
int main() {
    int x = 0;
    int y = 0;
    int angle = 0;
    int speed = 0;

    while (1) {
        printf("Enter x position: ");
        scanf("%d", &x);

        printf("Enter y position: ");
        scanf("%d", &y);

        printf("Enter angle: ");
        scanf("%d", &angle);

        printf("Enter speed: ");
        scanf("%d", &speed);

        simulate_vehicle(x, y, angle, speed);

        printf("\n");
    }

    return 0;
}

// Function to simulate the vehicle
void simulate_vehicle(int x, int y, int angle, int speed) {
    // Perform simulation logic here
    // For example, move the vehicle in the given direction and angle at the given speed
    if (angle == 0) {
        x += speed;
    } else if (angle == 90) {
        y += speed;
    } else if (angle == 180) {
        x -= speed;
    } else if (angle == 270) {
        y -= speed;
    }

    // Print the updated position of the vehicle
    printf("Vehicle position: (%d, %d)\n", x, y);
}
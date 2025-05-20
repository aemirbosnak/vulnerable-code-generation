//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

struct vehicle {
    double x, y, vx, vy, theta;
};

int main() {
    // Create a vehicle
    struct vehicle car;
    car.x = 0;
    car.y = 0;
    car.vx = 0;
    car.vy = 0;
    car.theta = 0;

    // Start simulation
    while (1) {
        // Read user input
        printf("Enter control command: ");
        int command;
        scanf("%d", &command);

        // Process control command
        switch (command) {
            case 1:
                // Forward
                car.vx += 1;
                car.vy -= 1;
                break;
            case 2:
                // Reverse
                car.vx -= 1;
                car.vy += 1;
                break;
            case 3:
                // Turn left
                car.theta += 0.1;
                break;
            case 4:
                // Turn right
                car.theta -= 0.1;
                break;
            default:
                printf("Invalid command\n");
        }

        // Update vehicle position
        car.x += car.vx * cos(car.theta);
        car.y += car.vy * sin(car.theta);

        // Display vehicle position
        printf("Vehicle position: (%f, %f)\n", car.x, car.y);
        printf("Vehicle velocity: (%f, %f)\n", car.vx, car.vy);
        printf("Vehicle heading: %f\n", car.theta);

        // Delay for smooth simulation
        sleep(0.1);
    }
}
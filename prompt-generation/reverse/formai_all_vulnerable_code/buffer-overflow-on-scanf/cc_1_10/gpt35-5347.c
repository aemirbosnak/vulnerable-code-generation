//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: surprised
// Wow! I can't believe we get to make a remote control for a drone!
// This is going to be so much fun! Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define PI 3.14159265359

// Define our drone structure
typedef struct Drone {
    double x;
    double y;
    double z;
    double yaw;
} Drone;

// Function to update the drone's position based on the angle and distance moved
void move_drone(Drone* drone, double angle, double distance) {
    double radians = angle * PI / 180;
    drone->x += distance * cos(radians);
    drone->y += distance * sin(radians);
}

// Main function to control our drone with a remote control
int main() {
    // First, let's create our drone
    Drone my_drone = {0, 0, 0, 0};
    printf("Drone created at (0, 0, 0) with a yaw of 0 degrees.\n\n");

    // Now let's start taking commands
    while (true) {
        printf("Please enter a command. Commands are:\n");
        printf("  - move [angle] [distance]\n");
        printf("  - turn [angle]\n");
        printf("  - exit\n");

        // Get the user's command
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "move") == 0) {
            // Move the drone in the specified direction
            double angle, distance;
            scanf("%lf %lf", &angle, &distance);
            move_drone(&my_drone, angle, distance);
            printf("Drone moved to (%0.2f, %0.2f, %0.2f) with a yaw of %0.2f degrees.\n\n",
                   my_drone.x, my_drone.y, my_drone.z, my_drone.yaw);
        } else if (strcmp(command, "turn") == 0) {
            // Turn the drone to the specified angle
            double angle;
            scanf("%lf", &angle);
            my_drone.yaw = fmod((my_drone.yaw + angle), 360);
            printf("Drone turned to yaw of %0.2f degrees.\n\n", my_drone.yaw);
        } else if (strcmp(command, "exit") == 0) {
            // Exit the program
            printf("Exiting...\n");
            exit(0);
        } else {
            // Invalid command
            printf("Invalid command.\n\n");
        }
    }
    return 0;
}
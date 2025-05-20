//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: irregular
// This is a drone remote control program

#include <stdio.h>
#include <stdlib.h>

// Define the drone's speed and direction
#define SPEED 10
#define UP 1
#define DOWN -1
#define LEFT 2
#define RIGHT -2

// Define the drone's current position and direction
int x = 0;
int y = 0;
int direction = UP;

// Define the drone's maximum position
#define MAX_X 100
#define MAX_Y 100

// Define the main function
int main() {
    // Initialize the drone's position
    x = 50;
    y = 50;

    // Loop until the user wants to quit
    while (1) {
        // Print the current drone position
        printf("Drone position: (%d, %d)\n", x, y);

        // Get user input
        int input;
        scanf("%d", &input);

        // Move the drone based on user input
        if (input == UP) {
            y -= SPEED;
        } else if (input == DOWN) {
            y += SPEED;
        } else if (input == LEFT) {
            x -= SPEED;
        } else if (input == RIGHT) {
            x += SPEED;
        }

        // Check if the drone has hit a wall
        if (x < 0 || x > MAX_X || y < 0 || y > MAX_Y) {
            printf("Drone has hit a wall!\n");
            break;
        }

        // Check if the drone has reached the destination
        if (x == 0 && y == 0) {
            printf("Drone has reached the destination!\n");
            break;
        }
    }

    // Exit the program
    return 0;
}
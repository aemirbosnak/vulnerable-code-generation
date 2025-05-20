//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define drone's initial position and orientation
float x = 0.0, y = 0.0, z = 0.0;
float roll = 0.0, pitch = 0.0, yaw = 0.0;

// Define drone's speed and turning rate
float speed = 10.0;
float turn_rate = 30.0;

// Main function to control the drone
int main() {
    // Get user input for desired drone movement
    printf("Enter your desired movement (forward, backward, left, right, up, down): ");
    char movement;
    scanf(" %c", &movement);

    // Get user input for desired drone turn
    printf("Enter your desired turn (left, right, roll left, roll right): ");
    char turn;
    scanf(" %c", &turn);

    // Update drone's position and orientation based on user input
    switch (movement) {
        case 'f': // Forward
            x += speed * cos(yaw);
            y += speed * sin(yaw);
            break;
        case 'b': // Backward
            x -= speed * cos(yaw);
            y -= speed * sin(yaw);
            break;
        case 'l': // Left
            x -= speed * sin(yaw);
            y += speed * cos(yaw);
            break;
        case 'r': // Right
            x += speed * sin(yaw);
            y -= speed * cos(yaw);
            break;
        case 'u': // Up
            z += speed;
            break;
        case 'd': // Down
            z -= speed;
            break;
        default:
            printf("Invalid movement input. Please try again.\n");
            break;
    }

    switch (turn) {
        case 'a': // Left turn
            yaw += turn_rate * M_PI / 180.0;
            break;
        case 'd': // Right turn
            yaw -= turn_rate * M_PI / 180.0;
            break;
        case 'q': // Roll left
            roll += turn_rate * M_PI / 180.0;
            break;
        case 'e': // Roll right
            roll -= turn_rate * M_PI / 180.0;
            break;
        default:
            printf("Invalid turn input. Please try again.\n");
            break;
    }

    // Display updated drone position and orientation
    printf("Drone's updated position: (%f, %f, %f)\n", x, y, z);
    printf("Drone's updated orientation: (roll: %f, pitch: %f, yaw: %f)\n", roll, pitch, yaw);

    return 0;
}